#include "zoey_threadpool.h"
#include "zoey_toolfun.h"

extern  void z_threadpool_exit_cb(void* argv);


//初始化一个线程池  conf为配置参数
zoey_threadpool_t* zoey_threadpool_init(zoey_threadpool_conf_t *conf)
{
	zoey_threadpool_t *pool = NULL;
	int error_flag_mutex = 0;
	int error_flag_cond = 0;
	pthread_attr_t attr;
	do{
		if (z_conf_check(conf) !=0){ //检查参数是否合法
			break;
		}

		pool = (zoey_threadpool_t *)malloc(sizeof(zoey_threadpool_t));//申请线程池句柄
		if (pool == NULL){
			break;
		}

		//初始化线程池基本参数
		pool->threadnum = conf->threadnum;
		pool->thread_stack_size = conf->thread_stack_size;
		pool->tasks.maxtasknum = conf->maxtasknum;
		pool->tasks.curtasknum = 0;

		z_task_queue_init(&pool->tasks);
	
		if (z_thread_key_create() != 0){//创建一个pthread_key_t，用以访问线程全局变量。
			free(pool);
			break;
		}
		if (z_thread_mutex_create(&pool->mutex) != 0){ //初始化互斥锁
			z_thread_key_destroy();
			free(pool);
			break;
		}

		if (z_thread_cond_create(&pool->cond) != 0){  //初始化条件锁
			z_thread_key_destroy();
			z_thread_mutex_destroy(&pool->mutex);
			free(pool);
			break;
		}

		if (z_threadpool_create(pool) != 0){       //创建线程池
			z_thread_key_destroy();
			z_thread_mutex_destroy(&pool->mutex);
			z_thread_cond_destroy(&pool->cond);
			free(pool);
			break;
		}
		return pool;
	}while(0);

	return NULL;
}

//向线程池中添加一个任务。handler为回掉函数，argv为参数
int zoey_threadpool_add_task(zoey_threadpool_t *pool, CB_FUN handler, void* argv)
{
	zoey_task_t *task = NULL;
	//申请一个任务节点并赋值
	task = (zoey_task_t *)malloc(sizeof(zoey_task_t));
	if (task == NULL){
		return -1;
	}
	task->handler = handler;
	task->argv = argv;
	task->next = NULL;
	if (pthread_mutex_lock(&pool->mutex) != 0){ //加锁
		free(task);
		return -1;
	}
	do{

		if (pool->tasks.curtasknum >= pool->tasks.maxtasknum){//判断工作队列中的任务数是否达到限制
			break;
		}

		//将任务节点尾插到任务队列
		*(pool->tasks.tail) = task;
		pool->tasks.tail = &task->next;
		pool->tasks.curtasknum++;

		//通知阻塞的线程
		if (pthread_cond_signal(&pool->cond) != 0){
			break;
		}
		//解锁
		pthread_mutex_unlock(&pool->mutex);
		return 0;

	}while(0);
	pthread_mutex_unlock(&pool->mutex);
	free(task);
	return -1;

}

//销毁线程池。
void zoey_threadpool_destroy(zoey_threadpool_t *pool)
{
	unsigned int n = 0;
	volatile unsigned int  lock;

	//z_threadpool_exit_cb函数会使对应线程退出
	for (; n < pool->threadnum; n++){
		lock = 1;
		if (zoey_threadpool_add_task(pool, z_threadpool_exit_cb, (void*)&lock) != 0){
			return;
		}
		while (lock){
			usleep(1);
		}
	}
	z_thread_mutex_destroy(&pool->mutex);
	z_thread_cond_destroy(&pool->cond);
	z_thread_key_destroy();
	free(pool);
}

//给线程池中增加一个工作线程
int zoey_thread_add(zoey_threadpool_t *pool)
{
	int ret = 0;
	if (pthread_mutex_lock(&pool->mutex) != 0){
		return -1;
	}
	ret = z_thread_add(pool);
	pthread_mutex_unlock(&pool->mutex);
	return ret;
}

//设置新的最大任务限制   0为不限制
int zoey_set_max_tasknum(zoey_threadpool_t *pool,unsigned int num)
{
	if (pthread_mutex_lock(&pool->mutex) != 0){
		return -1;
	}
	z_change_maxtask_num(pool, num);  //改变最大任务限制
	pthread_mutex_unlock(&pool->mutex);
	return 0;
}



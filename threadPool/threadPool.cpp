#include "common.h"

threadPool::threadPool(zoey_threadpool_conf_t *conf,toolFun *obj)
{
	zoey_threadpool_t *pool = this->pool;
	int error_flag_mutex = 0;
	int error_flag_cond = 0;
	pthread_attr_t attr;
	do{
		if (obj->conf_check(conf) == -1){ //检查参数是否合法
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

		obj->task_queue_init(&pool->tasks);
	
		if (obj->thread_key_create() != 0){//创建一个pthread_key_t，用以访问线程全局变量。
			free(pool);
			break;
		}
		if (obj->thread_mutex_create(&pool->mutex) != 0){ //初始化互斥锁
			obj->thread_key_destroy();
			free(pool);
			break;
		}

		if (obj->thread_cond_create(&pool->cond) != 0){  //初始化条件锁
			obj->thread_key_destroy();
			obj->thread_mutex_destroy(&pool->mutex);
			free(pool);
			break;
		}

		if (obj->threadpool_create(pool) != 0){       //创建线程池
			obj->thread_key_destroy();
			obj->thread_mutex_destroy(&pool->mutex);
			obj->thread_cond_destroy(&pool->cond);
			free(pool);
			break;
		}
	}while(0);
	
};

	int threadPool::threadPool_add_task(CB_FUN handler, void* argv){
	zoey_threadpool_t *pool = this->pool;
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
	
};

void threadPool::threadPool_destroy(toolFun *obj){
	zoey_threadpool_t *pool = this->pool;
	unsigned int n = 0;
	static unsigned int lock;

	//threadpool_exit_cb函数会使对应线程退出
	for (; n < pool->threadnum; n++){
		lock = 1;
		if ((this->threadPool_add_task(obj->threadpool_exit_cb, &lock)) != 0){
			return ;
		}
		while (lock){
			usleep(1);
		}
	}
	obj->thread_mutex_destroy(&pool->mutex);
	obj->thread_cond_destroy(&pool->cond);
	obj->thread_key_destroy();
	free(pool);
	
}

int threadPool::threadPool_add(toolFun *obj){
	
	zoey_threadpool_t *pool = this->pool;
	int ret = 0;
	if (pthread_mutex_lock(&pool->mutex) != 0){
		return -1;
	}
	ret = obj->thread_add(pool,obj);
	pthread_mutex_unlock(&pool->mutex);
	return ret;
}
void threadPool::threadPool_tasknum(unsigned int num,toolFun *obj){
	
	zoey_threadpool_t *pool = this->pool;
	if (pthread_mutex_lock(&pool->mutex) != 0){
		return -1;
	
	
	obj->change_maxtask_num(pool, num);  //改变最大任务限制
	pthread_mutex_unlock(&pool->mutex);
	
}



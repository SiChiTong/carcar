#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include "common.h"
#include "toolFun.h"
typedef void (*CB_FUN)(void *);
class toolFun;
//任务结构体
typedef struct task
{
	void		*argv; //任务函数的参数（任务执行结束前，要保证参数地址有效）
	CB_FUN		handler; //任务函数（返回值必须为0   非0值用作增加线程，和销毁线程池）
	struct task *next; //任务链指针
}zoey_task_t;

//任务队列
typedef struct task_queue
{
	zoey_task_t *head;  //队列头
	zoey_task_t **tail;	//队列尾
	unsigned int maxtasknum; //最大任务限制
	unsigned int curtasknum; //当前任务数
}zoey_task_queue_t;

//线程池
typedef struct threadpool
{
	pthread_mutex_t    mutex;  //互斥锁
	pthread_cond_t     cond;	//条件锁
	zoey_task_queue_t       tasks;//任务队列

	unsigned int       threadnum; //线程数
	unsigned int       thread_stack_size; //线程堆栈大小

}zoey_threadpool_t;

//配置参数
typedef struct threadpool_conf
{
	unsigned int threadnum;    //线程数
	unsigned int thread_stack_size;//线程堆栈大小
	unsigned int maxtasknum;//最大任务限制
}zoey_threadpool_conf_t;

//线程池类定义
class threadPool{
	public:
		zoey_threadpool_t *pool;
	public:
		threadPool(zoey_threadpool_conf_t *conf,toolFun *obj);
		int threadPool_add_task(CB_FUN handler, void* argv);
		void threadPool_destroy(toolFun *obj);
		int threadPool_add(toolFun *obj);
		void threadPool_tasknum(unsigned int num,toolFun *obj);
		
};

class toolFun{
	public:
	static 	pthread_key_t  key;
	const long MAX_TASK_SIZE=999999 ;
	public:

		int conf_check(zoey_threadpool_conf_t *conf);
		void task_queue_init(zoey_task_queue_t* task_queue);
		int thread_mutex_create(pthread_mutex_t *mutex);
		void thread_mutex_destroy(pthread_mutex_t *mutex);
	    int thread_cond_create(pthread_cond_t *cond);
		void thread_cond_destroy(pthread_cond_t *cond);
		int threadpool_create(zoey_threadpool_t *pool);
		void threadpool_cycle(void* argv);
		void threadpool_exit_cb(void* argv);
		int thread_add(zoey_threadpool_t *pool);
		void change_maxtask_num(zoey_threadpool_t *pool, unsigned int num);
		int thread_key_create();
		void thread_key_destroy();
	
};





#endif
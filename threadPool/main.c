
#include<stdio.h>
#include<pthread.h>
#include "zoey_threadpool.h"

int testfun(void *argv)
{
	int *num = (int*)argv;
	printf("testfun threadid = %u  num = %d\n",pthread_self(),*num);
	//sleep(3);
	return 0;
}

int main()
{
	int array[10000] = {0};
	int i = 0;
	zoey_threadpool_conf_t conf = {5,0,5}; //实例化启动参数
	toolFun tF;
	threadPool tp(&conf,tF);
	
	//zoey_threadpool_t *pool = zoey_threadpool_init(&conf);//初始化线程池

	if (tp->pool == NULL){
		return 0;
	}
	for (; i < 10000; i++){
		array[i] = i;
		if (i == 80){
			tF->thread_add(tp->pool); //增加线程
			tF->thread_add(tp->pool);
		}
		
		if (i == 100){
			tp->threadPool_tasknum(tp->pool, 0); //改变最大任务数   0为不做上限
		}
		while(1){
			if (tp->threadPool_add_task(tp->pool, testfun, &array[i]) == 0){
				break;
			}
			printf("error in i = %d\n",i);
		
		}
	}
	tp->threadPool_destroy(tp,tF);

	while(1){
		sleep(5);
	}
	return 0;
}

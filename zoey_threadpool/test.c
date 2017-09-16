#include<stdio.h>
#include<pthread.h>
#include "zoey_threadpool.h"

int testfun(void *argv)
{
	int *num = (int*)argv;
	printf("testfun threadid = %d  num = %d\n",(int)pthread_self(),*num);
	//sleep(3);
	return 0;
}

int main()
{
	int array[1000] = {0};
	int i = 0;
	zoey_threadpool_conf_t conf = {5,0,5}; //实例化启动参数
	zoey_threadpool_t *pool = zoey_threadpool_init(&conf);//初始化线程池
	if (pool == NULL){
		return 0;
	}
	for (; i < 1000; i++){
		array[i] = i;
		if (i == 80){
			zoey_thread_add(pool); //增加线程
			zoey_thread_add(pool);
		}
		
		if (i == 100){
			zoey_set_max_tasknum(pool, 0); //改变最大任务数   0为不做上限
		}
		while(1){
			if (zoey_threadpool_add_task(pool, (CB_FUN)testfun, &array[i]) == 0){
				break;
			}
			printf("error in i = %d\n",i);
		
		}
	}
	zoey_threadpool_destroy(pool);

	while(1){
		sleep(5);
	}
	return 0;
}

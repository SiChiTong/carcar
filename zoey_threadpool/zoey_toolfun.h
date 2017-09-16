#ifndef ZOEY_TOOLFUN
#define ZOEY_TOOLFUN

#define MAX_TASK_SIZE 99999999

pthread_key_t  key;

int z_conf_check(zoey_threadpool_conf_t *conf);

void z_task_queue_init(zoey_task_queue_t* task_queue);

int z_thread_mutex_create(pthread_mutex_t *mutex);

void z_thread_mutex_destroy(pthread_mutex_t *mutex);

int z_thread_cond_create(pthread_cond_t *cond);

void z_thread_cond_destroy(pthread_cond_t *cond);

int z_threadpool_create(zoey_threadpool_t *pool);

void z_threadpool_cycle(void* argv);

void  z_threadpool_exit_cb(void* argv);

int z_thread_add(zoey_threadpool_t *pool);

void z_change_maxtask_num(zoey_threadpool_t *pool, unsigned int num);

int z_thread_key_create();

void z_thread_key_destroy();

#endif

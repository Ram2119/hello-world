#define _GNU_SOURCE

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/sched.h>

pthread_mutex_t mutex_var = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

void *threadFun(void* arg)
{
	printf("$ [lock %d] [cnt %d]\n", mutex_var.__data.__lock, mutex_var.__data.__count);
	//pthread_mutex_lock(&mutex_var);
	printf("Executing %s\n", (char*)arg);
	int ret = pthread_mutex_trylock(&mutex_var);
	if (ret != 0)
		perror("2nd time lock \n");


	printf("$$ [lock %d] [cnt %d]\n", mutex_var.__data.__lock, mutex_var.__data.__count);

	struct timespec tp;
	sched_rr_get_interval(pthread_self(), &tp);
	printf("[%s] [%ld - %ld]\n", (char*)arg, tp.tv_sec, tp.tv_nsec);

	int sched = sched_getscheduler(0);
	if (sched == -1)
		perror("getsched failed");	
	printf("[%s] # %d\n", (char*)arg, sched);

	pthread_attr_t *attr = (pthread_attr_t*)malloc(sizeof(pthread_attr_t));
	struct sched_param sp;

	pthread_getattr_np(pthread_self(), attr);

	int i;
    int s = pthread_attr_getinheritsched(attr, &i);
    	if (s != 0)
        	perror("pthread_attr_getinheritsched");
        printf("Inherit scheduler   = %s\n",
        (i == PTHREAD_INHERIT_SCHED)  ? "PTHREAD_INHERIT_SCHED" :
        (i == PTHREAD_EXPLICIT_SCHED) ? "PTHREAD_EXPLICIT_SCHED" :
         "???");
        s = pthread_attr_getschedpolicy(attr, &i);
        if (s != 0)
            perror("pthread_attr_getschedpolicy");
        printf("Scheduling policy   = %s\n",
	         (i == SCHED_OTHER) ? "SCHED_OTHER" :
            (i == SCHED_FIFO)  ? "SCHED_FIFO" :
            (i == SCHED_RR)    ? "SCHED_RR" :
			"???");
		s = pthread_attr_getschedparam(attr, &sp);
			if (s != 0)
				perror("pthread_attr_getschedparam");
		printf("Scheduling priority = %d\n", sp.sched_priority);


	for (i = 0; i < 30; i++)
		printf("# %s\n", (char*)arg);	

	pthread_mutex_unlock(&mutex_var);
	pthread_mutex_unlock(&mutex_var);
/*	int ret = pthread_detach(pthread_self());
	if (ret == -1)
		perror("detach failed\n");
*/	pthread_exit("Hello");
	//return "Hello";
}

int main(void)
{

	pthread_t th_id;

	pthread_attr_t th_attr;
	struct sched_param sp;

	pthread_attr_init(&th_attr);
	
	int ret = pthread_attr_setinheritsched(&th_attr, PTHREAD_EXPLICIT_SCHED);
	if (ret == -1)
		perror("setinheritsched\n");	
		
	ret = pthread_attr_setschedpolicy(&th_attr, SCHED_RR);
	if (ret == -1)
		perror("setschedpolicy\n");	

	sp.sched_priority = 50;
	ret = pthread_attr_setschedparam(&th_attr, &sp);
	if (ret == -1)
		perror("setschedparam\n");	

	ret = pthread_create(&th_id, &th_attr, threadFun, "Thread-1");
	if (ret == -1) 
		perror("Failed to create thread\n");
	else {
//		pthread_exit(NULL);

	sp.sched_priority = 40;
	pthread_attr_setschedparam(&th_attr, &sp);
	ret = pthread_create(&th_id, &th_attr, threadFun, "Thread-2");
	if (ret == -1) 
		perror("Failed to create thread - 2 \n");

//		sleep(1);	
		
/*		void *retVal;	
		ret = pthread_join(th_id, &retVal);
		if (ret == -1)
			perror("Failed to join thread\n");
		else {
			printf("Return from thread\n");	
			printf("# %s\n", (char*)retVal);
		}
*/
		pthread_exit(NULL);
	}


	
	pthread_attr_destroy(&th_attr);
	return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutexVar = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condVar = PTHREAD_COND_INITIALIZER;


int shared = 3;

void *thread1(void* arg)
{
	pthread_mutex_lock(&mutexVar);
	
	while(shared != 1)
		pthread_cond_wait(&condVar, &mutexVar);

	int i = 0;
	for(i = 0; i < 50; i++)
		printf("Running thread1..\n");
	
	shared--;
	pthread_mutex_unlock(&mutexVar);
	pthread_cond_signal(&condVar);
}

void *thread2(void* arg)
{
	pthread_mutex_lock(&mutexVar);
	
	while(shared != 2)
		pthread_cond_wait(&condVar, &mutexVar);
	
	int i = 0;
	for(i = 0; i < 50; i++)
		printf("Running thread2..\n");
	shared--;
	pthread_mutex_unlock(&mutexVar);
	pthread_cond_signal(&condVar);
}

void *thread3(void* arg)
{
	pthread_mutex_lock(&mutexVar);
	while(shared != 3)
		pthread_cond_wait(&condVar, &mutexVar);
	int i = 0;
	for(i = 0; i < 50; i++)
		printf("Running thread3..\n");
	shared--;
	pthread_mutex_unlock(&mutexVar);
	pthread_cond_signal(&condVar);
}

int main(void)
{
	pthread_t thId[3];
	
	int ret = pthread_create(&thId[0], NULL, thread1, NULL);
	if (ret == -1)
		perror("Failed to create thread1\n");

	
	ret = pthread_create(&thId[1], NULL, thread2, NULL);
	if (ret == -1)
		perror("Failed to create thread2\n");

	ret = pthread_create(&thId[2], NULL, thread3, NULL);
	if (ret == -1)
		perror("Failed to create thread3\n");

	pthread_exit(NULL);
	return 0;
}

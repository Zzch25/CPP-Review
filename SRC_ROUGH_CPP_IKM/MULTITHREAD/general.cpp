/*
 *
 */

#include <iostream>
#include <pthread.h>
#include "def.h"

using namespace std;

void *threadContentionFunc(void *arg)
{
	void **args;
	int *shared;
	pthread_mutex_t *lock;
	pthread_cond_t *wait;

	args = (void **)arg; //lazy cast
	
	shared = (int*)(args[0]);
	lock = (pthread_mutex_t*)(args[1]);
	wait = (pthread_cond_t*)(args[2]);

	pthread_mutex_lock(lock);

	//some silly condition that sleeps and indicates the need to signal
	
	/*
	
	while(thatSillyCondition == true)
		pthread_cond_wait(wait);
	pthread_cond_signal(wait);

	 */

	(*shared)++;

	pthread_mutex_unlock(lock);

	pthread_exit(NULL);
}

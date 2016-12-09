#include <iostream>
#include <pthread.h>
#include "def.h"

using namespace std;

int main()
{
	//An unber basic strip from work on "STIGBOT", does not infringe, based on personal code originally and special attributes junked

	int i, shared = 23;
	void* arg[3];

	pthread_t threads[DEFS_NUMTHREADS];
	pthread_mutex_t lock;
	pthread_cond_t wait;

	arg[0] = (void*)&shared;
	arg[1] = (void*)&lock;
	arg[2] = (void*)&wait;

	cout << "Super basic non infringment implementation on STIGBOT implementation\n\n";

	if((pthread_mutex_init(&lock, NULL)) == 0 && (pthread_cond_init(&wait, NULL)) == 0) 
	{
		cout << "Init mutex basics...\n\n";
		for(i = 0; i < DEFS_NUMTHREADS && pthread_create(&(threads[i]),NULL,threadContentionFunc,(void *)arg) == 0; pthread_join(threads[i++],NULL))
			cout << i << "th success...\n";
	}

	cout << "\nShared is " << shared << endl;

	//Not necesary technically
	pthread_exit(NULL);

	return 0;
}

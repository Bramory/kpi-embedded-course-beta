#include <stdio.h>
#include <pthread.h>

#define NUM_OF_THREADS 2
#define NUM_LOOPS  (100000000 / NUM_OF_THREADS)

long long sum = 0;

void *counting_thread(void *arg)
{
	int offset = *(int *) arg;
	for (int i = 0; i < NUM_LOOPS; i++) {
		sum += offset;	
	} 
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t id[NUM_OF_THREADS];   
	
	int offset = 1;
	
	for (int i = 0; i < NUM_OF_THREADS; i++) {	
		pthread_create(&id[i], NULL, counting_thread, &offset);
	}

	for (int i = 0; i < NUM_OF_THREADS; i++) {	
		pthread_join( id[i], NULL);
	}
	
	printf("Sum = %lld\n", sum);
	return 0;
}


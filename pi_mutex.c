#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>


#define NUM_THREAD 3
static long int count_circle = 0;
pthread_mutex_t lock;
double random_double()
{
	return random() / ((double)RAND_MAX);
}

void* point_thread(void *point_per_thread)
{
	int POINTS =*((int*)point_per_thread);
	int HitCount = 0;
	for(int i = 0; i < POINTS; i++)
	{
		double x = random_double() * 2.0 - 1.0;
		double y = random_double() * 2.0 - 1.0;
		double r = x*x + y*y;
		if(r <= 1) {
			++HitCount;
		}
	}
	pthread_mutex_lock(&lock);
	count_circle += HitCount;
	pthread_mutex_unlock(&lock);
	pthread_exit(0);
}


int main(int argc, char** argv)
{
	pthread_t tid[NUM_THREAD];
	int total_point_per_thread = atoll(argv[1])/NUM_THREAD;
	pthread_mutex_init(&lock, NULL);
	srandom((unsigned)time(NULL));
	static int i;
	for(i = 0; i < NUM_THREAD ; i++){
		pthread_create(&tid[i], NULL, point_thread,
			       	&total_point_per_thread);
	}
	for(i = 0 ; i < NUM_THREAD ; i++)
	{
		pthread_join(tid[i],NULL);
	}

	double pi = 4.0 * (double)count_circle/(double)total_point_per_thread/(double)NUM_THREAD;
	pthread_mutex_destroy(&lock);
	printf("PI = %17.15f\n",pi);
	return 0;
}
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define NUM_THREAD 10 

void *hello(void *tid){
	printf("Hello from thread %d\n", (int)tid);
}

int main(){
	pthread_t tid[NUM_THREAD];
	long i;
	for(i = 0; i < NUM_THREAD; i++){
		pthread_create(&tid[i], NULL, hello, (void*)i);
		//sleep(1);
		pthread_join(tid[i],NULL);
	}
	//for(long j = 0 ; j < NUM_THREAD; j++){
	//	pthread_join(tid[j],NULL);
	//}
	pthread_exit(NULL);
	return 0;
}

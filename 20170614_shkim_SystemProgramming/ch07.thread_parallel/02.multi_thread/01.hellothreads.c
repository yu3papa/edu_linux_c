#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD	3

void *hello_thread(void *arg)
{
	int i;
	
	for(i=1; i<=3; i++) {
		printf("Thread %ld: Hello, World(%d)!\n", (long)arg, i);
		sleep(1);
	}
	
	return arg;
}

int main(void)
{
	...........
	int status;
	long i;
	
	for(i=0; i<NUM_THREAD; i++) {
		status = ............
		if(status != 0) {
			perror("thread create");
			exit(1);
		}
	}
	
	printf("Main Thread End!!\n");
	pthread_exit(NULL);
	
    return 0;
}

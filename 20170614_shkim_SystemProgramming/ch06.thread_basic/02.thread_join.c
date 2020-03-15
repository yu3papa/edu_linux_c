#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int main() {
	int status;
	pthread_t tid;
	void *thread_result;
	int i;
	
	//쓰레드 생성
	status = pthread_create(&tid, NULL, thread_function, (void *)NULL);
	if(status !=0){
		perror("pthread_create");
		exit(1);
	}
	
	for(i=1; i<=10; i++){
		printf("Parent thread %d!!\n", i);
		sleep(1);
	}

	//쓰레드 종료 처리 대기
	status = ............
	if(status != 0){
		perror("pthread_join");
		exit(1);
	}
	printf("Thread joined, it returned %s\n", (char *)thread_result);
	return 0;
}

void *thread_function(void *arg){
	int i;
	pid_t tpid, pid;
	
	for(i=1; i<=5; i++){
		printf("\tChild thread %d\n", i);
		sleep(1);
	}
	return "Good Bye";
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int cnt = 0;

int main() {
	int status;
	pthread_t tid;
	void *thread_result;
	int i;

	//쓰레드 생성
	status = pthread_create(&tid, NULL, thread_function, NULL);
	if (status != 0) {
		perror("pthread_create");
		exit(1);
	}

	for (i = 1; i <= 5; i++) {
		printf("Parent thread %d!!%d\n", i, cnt);
		sleep(1);
	}
	//return 0;
	pthread_exit(NULL);
}

void *thread_function(void *arg) {
	int i;
	pid_t tpid, pid;

	for (i = 1; i <= 10; i++) {
		cnt = i;
		printf("\tChild thread %d~~%d\n", i, cnt);
		sleep(1);
	}
	return NULL;
}

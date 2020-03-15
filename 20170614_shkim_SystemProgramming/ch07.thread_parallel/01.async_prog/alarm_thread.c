#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

typedef struct alarm_tag {
	int seconds;
	char message[64];
} alarm_t;

void * alarm_thread(void *arg)
{
	______ = (alarm_t*)arg;
	int status;

#if 0
	status = ...............
	if(status != 0) {
		perror("pthread_detach() error");
		return (void*)3;
	}
#endif
	........
	printf("(%d) %s\n", ........);
	____(alarm);
	return NULL;
}
	

int main(int argc, char *argv[])
{
	int seconds;
	char line[128];
	alarm_t *alarm;
	pthread_t tid;
	int status;
	
	while(1) {
		printf("Alarm> ");
		if(fgets(line, sizeof(line), stdin) == NULL) exit(0);
		if(strlen(line) <= 1) continue;

		if(!strncmp(line, "exit", 4)) exit(0);

		alarm = (alarm_t*)malloc(sizeof(alarm_t));
		if(alarm == NULL) {
			perror("malloc() error");
			exit(1);
		}
		
		if(sscanf(line, "%d %64[^\n]", &alarm->seconds, alarm->message) < 2) {
			fprintf(stderr, "Bad command\n");
			free(alarm);
		} else {
			status = _________(&tid, NULL, ______, ______);
			if(status != 0) {
				perror("pthread_create() error");
				exit(2);
			} 
		} // end of if-else
	} //end of while
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	pid_t pid;

	switch (pid = fork()) {
		case -1:
			perror("fork failed");
			break;
		case 0:
			printf("CHILD PROCESS : %d\n", getpid());
			execl("./mytask", "mytask", "5", (char*)0);
			// execl("./mytask", "mytask", "10", NULL);
			perror("execl failed");
		default:
			system("ps -l");
			printf("PARENT PROCESS : %d\n", getpid());
			wait((int *) 0);
			printf("parent : ls completed!\n");
			exit(0);
	}
	return 0;
}

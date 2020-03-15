#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(void) {
	pid_t ret1, ret2, ret_pid;
	int i = 0;
	int j = 0;
	int child1 = 0;
	int child2 = 0;
	int repeat1 = 0;

	switch (ret1 = fork()) {
	case -1:		// fork error
		perror("fork");
		exit(1);
		break;
	case 0:
		while (1) {
			// printf("Child1 long process --- (%d)\n", getpid());
			// sleep(1);
			if (child1 == 5000) {
				write(1, "*", 1); // ���۸� ����....
				child1 = 0;
			}
			child1++;
			repeat1++;
			if (repeat1 == 5000000) {
				break;
			}
		}
		exit(0);
		break;
	default:
		switch (ret2 = fork()) {
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			for (i = 0; i < 5; i++) {
				printf("\tChild2 short process---(%d)\n", getpid());
				sleep(1);
			}
			exit(0);
			break;
		}
		while (1) {
			while ((ret_pid = waitpid(-1, NULL, WNOHANG)) > 0) {
				printf("PID returned from waitpid = %d\n", ret_pid);
			}
			if (errno == ECHILD) {
				printf("No Child\n");
				break;
			}
			if (errno == EINTR) {
				printf("INTR\n");
				break;
			}
			if (j == 5000) {
				write(1, ".", 1);
				j = 0;
			}
			j++;
		}
		break;
	}
	return 0;
}

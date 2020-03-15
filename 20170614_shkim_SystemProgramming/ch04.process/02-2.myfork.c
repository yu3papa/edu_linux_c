#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	switch (pid = fork())
	{
	case -1:
		perror("fork");
		exit(1);
	case 0:
		printf("CHILD PROCESS---- (%d)\n", getpid());
		sleep(3);
		system("echo Child");
		system("ps -l");
		exit(0);
		break;
	default:
		printf("PARENT PROCESS ---(%d)\n", getpid());
		printf("Returned PID = %d\n", pid);
		sleep(5);
		system("echo Parent");
		system("ps -l");
		getchar();
		exit(0);
		break;
	}

	return 0;
}

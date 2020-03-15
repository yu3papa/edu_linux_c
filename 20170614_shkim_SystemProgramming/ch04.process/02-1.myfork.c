#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	printf("Before fork(pid:%d, ppid:%d)\n", getpid(), getppid());

	pid = fork();

	printf("After fork(pid:%d, ppid:%d, return_pid:%d)\n", getpid(), getppid(), pid);

	while (1);

	return 0;
}

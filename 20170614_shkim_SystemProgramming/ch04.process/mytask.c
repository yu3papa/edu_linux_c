#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	for (i = 1; i <= atoi(argv[1]); i++)
	{
		printf("MyTask_%d!!(pid:%d, ppid(:%d\n", i, getpid(), getppid());
		sleep(1);
	}
	return 0;
}

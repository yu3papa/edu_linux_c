#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo)
{
	printf("Received Signal no - %d\n", signo);
	while (1)
	{
		printf("Press Control-C\n");
		sleep(1);
	}
}

int main(int argc, char *argv[])
{
	int a, b;

	signal(SIGFPE, handler);

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	if (b == 0) raise(SIGFPE);
	printf("divide....\n");
	a = a / b;
	printf("after divide....\n");

	return 0;
}

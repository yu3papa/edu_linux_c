#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void myhandler(int signo)
{
	printf("Signal received ~~~~%d\n", signo);
}

int main()
{
	int i;

	signal(SIGINT, myhandler);

	for (i = 1; i <= 5; i++)
	{
		printf("signal test\n");
		sleep(1);
	}

	signal(SIGINT, SIG_DFL);

	for (i = 1; i <= 5; i++)
	{
		printf("signal test\n");
		sleep(1);
	}

	return 0;
}

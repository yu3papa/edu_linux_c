#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int count = 0;

void handler(int signo)
{
	int i;
	count++;
	for (i = 1; i <= 3; i++)
	{
		printf("handler_%d!!\n", i);
		sleep(1);
	}
}

int main(void)
{
	int i = 0;
	struct sigaction act, oldact;

	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT); // 핸들러 함수가 돌고 있을때 SIGINT 시그널을 블로킹
	sigaddset(&act.sa_mask, SIGQUIT);// 핸들러 함수가 돌고 있을때 SIGQUIT 시그널을 블로킹
	act.sa_flags = SA_RESTART;

	sigaction(SIGINT, &act, &oldact);

	while (i < 10)
	{
		printf("signal test_%d\n", i);
		sleep(1);
		i++;
	}
	sigaction(SIGINT, &oldact, NULL);
	printf("count = %d\n", count);
	return 0;
}


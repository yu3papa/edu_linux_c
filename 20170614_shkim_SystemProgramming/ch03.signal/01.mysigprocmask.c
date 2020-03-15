#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{
	sigset_t set1, set2;

	sigfillset(&set1); // 시그널 집합 모두 1로 설정
	sigemptyset(&set2); // 시그널 집합 모두 0으로 설정
	sigaddset(&set2, SIGINT); // SIGINT 2번 SIGNAL 만 masking

	sigprocmask(SIG_BLOCK, &set1, NULL);    // 모든 SIGNAL 블로킹 설정
											// signal() 함수를 이용하여 무시할수도 있음
	printf("signal block start \n");
	sleep(5);

	sigprocmask(SIG_UNBLOCK, &set2, NULL); // SIGINT 2번  시그널을 블로킹 해제

	while (1)
	{
		printf("Hello Signal\n");
		sleep(1);
	}

	return 0;
}

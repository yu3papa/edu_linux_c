#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int alarm_flag = 1;

void alarm_handler(int signo)
{
	printf("\e[31mAlarm Handler ----\e[0m\n");
	alarm_flag = 0;
}

int main()
{
	signal(SIGALRM, alarm_handler);
	// alarm(5);
	pause();

	while (alarm_flag)
	{
		printf("Alarm test-----\n");
		sleep(1);
	}
	printf("Alarm test completed-----\n");
}

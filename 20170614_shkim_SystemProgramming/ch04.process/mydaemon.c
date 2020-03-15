#include <stdio.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <syslog.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	unsigned long cnt = 0;

	if ((pid = fork()) != 0) exit(0); // Parent Process는 종료

	setsid(); //  세션을 다시 설정
	if (chdir("/") != 0)
	{
		perror("chdir");
		exit(1);
	}

	syslog(LOG_INFO | LOG_DAEMON, "Test Daemon Process Start(%d)...\n", getpid());
	while (1)
	{
		sleep(1);
		syslog(LOG_INFO | LOG_DAEMON, "Test Daemon Process(%d)...\n", ++cnt);
	}

	return 0;
}

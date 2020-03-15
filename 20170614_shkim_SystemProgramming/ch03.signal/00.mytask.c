#include <stdio.h>
#include <unistd.h>

/**
  * 입력받은 정수 만큼 Sleep
 * SIGNAL 데모로 사용하는 프로그램
 */
int main(int argc, char *argv[])
{
	int i;
	for (i = 1; i < atoi(argv[1]); i++)
	{
		printf("MyTask_%d\n", i);
		sleep(1);
	}
	return 0;
}

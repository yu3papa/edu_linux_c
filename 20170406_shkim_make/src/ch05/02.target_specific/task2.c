//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//
//int main(int argc, char *argv[])
//{
//	int i;
//	for (i = 1; i <= atoi(argv[1]); i++)
//	{
//		printf("Task2_%d!!\n", i);
//		sleep(2);
//	}
//	return 0;
//}

#include <stdio.h>

int max(int a, int b);
int min(int a, int b);

int main(void)
{
	printf("Task2_Execute!!!\n");

	printf("max(5, 2) : %d\n", max(5, 2));
	printf("min(5, 2) : %d\n", min(5, 2));

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	int i;
	for(i=1; i<atoi(argv[1]); i++)
	{
		printf("MyTask_%d\n", i);
		sleep(1);
	}
	return 0;
}
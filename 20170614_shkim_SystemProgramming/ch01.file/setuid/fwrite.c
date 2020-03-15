#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
	{
		printf("Usage : %s string\n", argv[0]);
		exit(1);
	}

	printf("fwrite => uid:%d, euid:%d\n", getuid(), geteuid());

	if ((fp = fopen("bb", "a")) == NULL)
	{
		perror("file open error!!");
		exit(-1);
	}

	fprintf(fp, "%s\n", argv[1]);
	printf("file write done!!\n");
	fclose(fp);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

/**
 * 표준출력을 리다이렉션
 */
int main(int argc, char *argv[])
{
	int fd;
	char *buf = "This is a dup() demonstration\n";

	if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		perror("open");
		exit(1);
	}

	dup2(fd, 1);

	close(fd);
	write(1, buf, strlen(buf));
	printf("Hello World ~~~\n");
	fprintf(stdout, "This is the output to stdout\n");

	return 0;
}

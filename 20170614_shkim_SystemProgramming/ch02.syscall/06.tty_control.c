#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char data1[100] = "Hello, Kim!!\n";
	char data2[100] = "Hi, Leerν rv\n";
	int fd;
	fd=open("/dev/pts/11", O_WRONLY | O_CREAT);
	write(fd, &data1, strlen(data1));
	write(fd, &data2, strlen(data2));
	close(fd);
	return 0;
}

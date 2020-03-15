#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int pd[2], read_fd, write_fd;
	pid_t pid;
	char tx_buf[100], rx_buf[100];
	if (pipe(pd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	read_fd = pd[0];
	write_fd = pd[1];

	switch (pid = fork())
	{
		case 0:
			strcpy(tx_buf, "Pipe Connected!!");
			write(write_fd, tx_buf, strlen(tx_buf) + 1);
			printf("Child-write:%s\n", tx_buf);
			sleep(1);
			read(read_fd, rx_buf, sizeof(rx_buf));
			printf("Child-read (from Parent):%s\n", rx_buf);
			exit(0);
		default:
			read(read_fd, rx_buf, sizeof(rx_buf));
			printf("Parent-read (from Child):%s\n", rx_buf);
			strcpy(tx_buf, "Ok, Good~~~");
			write(write_fd, tx_buf, strlen(tx_buf) + 1);
			printf("Parent-write:%s\n", tx_buf);
			sleep(2);
			exit(0);
	}
}

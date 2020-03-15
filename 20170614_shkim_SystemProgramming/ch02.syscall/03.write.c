#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "00.info.h"

int main(int argc, char *argv[])
{
	INFO data[5] = { "kim", 20, 170.1F,
					 "lee", 25, 180.3F,
					 "park", 21, 176.2F,
					 "choi", 28, 167.9F,
					 "kang", 25, 172.5F };
	int fd;
	int i;

	if ((fd = open(argv[1], O_WRONLY | O_CREAT)) < 0)
	{
		perror("open");
		exit(1);
	}
#if 1
	// 5번 루프를 돌면서 레코드 1개씩 저장
	for(i=0; i<5; i++)
	{
		if( write(fd, &data[i], sizeof(INFO)*1) != sizeof(INFO)*1) {
			perror("write");
			close(fd);
			exit(2);
		}
	}
#else
	// 한번에 저장
	if (write(fd, &data[0], sizeof(INFO) * 5) != sizeof(INFO) * 5)
	{
		perror("write");
		close(fd);
		exit(2);
	}
#endif

	close(fd);
	return 0;
}

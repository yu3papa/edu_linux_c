#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd;
	char buf[128];
	int count = 0;

	if (mkfifo("/tmp/myfifo", S_IRUSR | S_IWUSR) == -1)
	{
		perror("mkfifo");
		exit(1);
	}

	if ((fd = open("/tmp/myfifo", O_RDWR)) == -1)
	{
		perror("open");
		exit(1);
	}

	while (1)
	{
		memset(buf, 0, sizeof(buf));
		read(fd, buf, sizeof(buf));
		printf("\e[31mRx - %d: %s\e[0m\n", ++count, buf);
		if (strstr(buf, "end"))
		{
			break;
		}
	}
	close(fd);
	unlink("/tmp/myfifo"); // 파일 삭제

	return 0;
}

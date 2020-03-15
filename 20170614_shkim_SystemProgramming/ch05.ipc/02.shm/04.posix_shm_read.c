#include <stdio.h>
#include <unistd.h>  
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define  MEM_SIZE    1024

int main() {
	int fd;
	void *shm_addr;
	int count = 0;

	fd = shm_open("/mydata", O_RDWR | O_CREAT, 0777);
	if (fd == -1) {
		perror("shm_open");
		exit(1);
		//return EXIT_FAILURE;
	}

	//�޸� ��ü ũ�� ����
	if (ftruncate(fd, MEM_SIZE) == -1) {
		perror("ftruncate");
		return EXIT_FAILURE;
	}

	//�޸� ��ü ����
	shm_addr = mmap(0, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (shm_addr == (void *) -1) {
		perror("mmap error");
		return EXIT_FAILURE;
	}

	printf("Map addr is %p\n", shm_addr);

	while (1) {
		printf("\e[31mRead counter %s\e[0m\n", (char *) shm_addr);
		if (!strcmp(shm_addr, "end")) {
			break;
		}
		sleep(1);
	}

	munmap(shm_addr, MEM_SIZE);
	close(fd);
	return 0;
}

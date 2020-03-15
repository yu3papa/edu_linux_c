#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define  MEM_SIZE    1024

int main() {
	int fd;
	void *shm_addr;
	int count;

	//�޸� ��ü ����
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

	printf("enter to mmap()...");
	getchar();

	//�޸� ��ü ����
	shm_addr = mmap(0, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (shm_addr == (void *) -1) {
		perror("mmap error");
		return EXIT_FAILURE;
	}

	printf("Map addr is %p\n", shm_addr);
	printf("enter to write()...");
	getchar();

	for (count = 11; count <= 20; count++) {
		// write counter to shared memory
		sprintf((char *) shm_addr, "%d", count);
		sleep(1);
	}
	sprintf((char *) shm_addr, "end");

	printf("Input Enter to unmap shm...");
	getchar();

	munmap(shm_addr, MEM_SIZE);
	close(fd);

	shm_unlink("/mydata");

	return 0;
}

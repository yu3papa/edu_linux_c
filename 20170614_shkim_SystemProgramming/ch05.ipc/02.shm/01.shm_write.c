#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define  KEY_NUM     0x2222
#define  MEM_SIZE    1024

int main()
{
	int shm_id;
	void *shm_addr, *shm_addr_dt;
	int count;

	if ((shm_id = shmget((key_t) KEY_NUM, MEM_SIZE, IPC_CREAT | 0666)) == -1)
	{
		perror("shmget");
		exit(1);
	}

	printf("Please enter to attach shared memory ->\n");
	getchar();

	if ((shm_addr = shmat(shm_id, NULL, 0)) == (void*) -1)
	{
		perror("shmat");
		exit(1);
	}

	printf("---------->shm_addr:%p\n", shm_addr);
	//shm_addr = shm_addr_dt;
	shm_addr_dt = shm_addr;
	for (count = 11; count <= 20; count++)
	{
		sprintf((char*) shm_addr, "%d", count);
		shm_addr = shm_addr + sizeof(int);
		sleep(1);
	}

	sprintf((char*) shm_addr, "end");

	printf("Please enter to detach shared memory ->\n");
	getchar();
	if (shmdt(shm_addr_dt) != 0)
	{
		perror("shmdt");
		exit(2);
	}

	getchar(); // heap memory���� ���ŵǴ°� Ȯ��

	if (shmctl(shm_id, IPC_RMID, NULL) == -1)
	{
		perror("shmctl");
		exit(2);
	}

	return 0;
}

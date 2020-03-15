#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY_NUM     0x2222
#define	MEM_SIZE	1024
static int semid;

void p() {
	struct sembuf pbuf;			//set of semaphore *sops
	pbuf.sem_num = 0;			//�������� ��ȣ
	pbuf.sem_op = -1;			//�������� ������
	pbuf.sem_flg = SEM_UNDO;	//���μ����� ����Ǹ� �ý��ۿ��� �������� ������ �������·� ����
	if (semop(semid, &pbuf, 1) == -1) {
		perror("p()-semop");
	}
}

void v() {
	struct sembuf vbuf;			//set of semaphore *sops
	vbuf.sem_num = 0;			//�������� ��ȣ
	vbuf.sem_op = 1;			//�������� ������
	vbuf.sem_flg = SEM_UNDO;	//���μ����� ����Ǹ� �ý��ۿ��� �������� ������ �������·� ����
	if (semop(semid, &vbuf, 1) == -1) {
		perror("v()-semop");
	}
}

int main() {
	int shm_id;
	void *shm_addr;
	int i, j;
	struct shmid_ds shm_stat;
	union senum {
		int val;
		struct semid_ds *buf;
		unsigned short int *array;
	} sem_ctrl;
	//struct sembuf sem_ops;

	printf("Started --------------------\n");
	if ((shm_id = shmget((key_t) KEY_NUM, MEM_SIZE, IPC_CREAT | 0666)) == -1) {
		perror("shmget");
		exit(1);
	}

	if ((semid = semget((key_t) 0x1234, 1, IPC_CREAT | 0666)) == -1) {
		perror("shmget");
		exit(1);
	}
	sem_ctrl.val = 1;
	semctl(semid, 0, SETVAL, sem_ctrl);

	if ((shm_addr = shmat(shm_id, NULL, 0)) == (void *) -1) {
		perror("shmat");
		exit(1);
	}

	for (i = 0; i < 300; i++) {
		p(); // lock
		sprintf((char *) shm_addr, "%d", getpid());
		for (j = 0; j < 3000000; j++) {
		}
		if (getpid() == atoi(shm_addr))
			putchar('0');
		else
			putchar('X');
		fflush(stdout);
		v(); // unlock
	}

	if (shmdt(shm_addr) != 0) {
		perror("shmdt");
		exit(2);
	}

	// if(shmctl(shm_id, IPC_RMID, NULL) == -1){
	// perror("shmctl");
	// exit(2);
	// }

	return 0;
}

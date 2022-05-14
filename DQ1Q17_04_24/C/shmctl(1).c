#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 19991214L

int main()
{
	int shmid;
	key_t key;
	int size=666;
	int shmflg;
	int rtn;
	int cmd;

	struct shmid_ds shmid_ds, *buf;

	buf = &shmid_ds;

	key = SHMKEY;

	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	    perror("shmget() :");
	    return 1;
	}

	do{
		printf("Commands:\n");
		printf("[0] - IPC_STAT (status)\n");
		printf("[1] - IPC_RMID (remove)\n> ");
		scanf("%d",&cmd);
	} while (cmd < 0 || cmd > 1);

	switch (cmd)
	{
	    case 0: rtn = shmctl(shmid, IPC_STAT, buf);
                printf("\nSegment status: %ld\n",buf->shm_segsz);
                break;

	    case 1: rtn = shmctl(shmid, IPC_RMID, NULL);
		        printf("\nSegment (%d) removed!\n", shmid);
	}

	return 0;
}

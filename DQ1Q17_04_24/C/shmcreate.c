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

	key = SHMKEY;

	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	   printf("Segment created!\n");
	   shmflg = 00666 | IPC_CREAT;
	   if ((shmid=shmget(key, size, shmflg)) < 0) {
	      perror("shmget() :");
	      return 1;
	   }
       printf("shmID: %d\n", shmid);
	} 

    else 
       printf("Segment already exists!\n");

	return 0;
}

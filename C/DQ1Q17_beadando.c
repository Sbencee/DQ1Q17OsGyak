#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    struct msgbuf1 {
	long mtype;
	long pid;
    } sendbuf, *msgp;


    int pid = getpid();
    int msgid = msgget(ftok("/user/bence",1),00666|IPC_CREAT);
    if(msgid==-1){
        perror(": msgget() nem sikerült!");
    exit(-1);
    }
    printf("PID = %d\n", pid);
    msgp        = &sendbuf;
	msgp->mtype = 1;
    while(1) {
        printf("%d\n", pid);
        pid += 2;
        sleep(1);
    msgp->pid = pid;
    msgsnd(msgid,(struct msgbuf1*)msgp,sizeof(msgp->pid),0666);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main(int argc, char **argv) {
    struct msqid_ds ds, *buf;
    struct msgbuf1 {
	long mtype;
	long pid;
    } recvbuf, *msgp;    

    int pid;
    int msgid = msgget(ftok("/user/bence",1),00666|IPC_CREAT);
    if(msgid==-1){
        perror(": msgget() nem sikerült!");
    exit(-1);
    }

    msgp = &recvbuf;	/* uzenetfogado buffer cime */
	buf = &ds;		/* uzenetsor jellemzo adataihoz */
    int	msgsz = 20;		/* max hossz */
    int	mtype = 0;
	

	 msgctl(msgid, IPC_STAT, buf); /* uzenetsor adatokat lekerdezem */
	printf("Az uzenetek szama az uzenetsorban: %d\n", buf->msg_qnum);

	while (buf->msg_qnum) {		/* van-e uzenet?*/
		/* veszem a kovetkezo uzenetet: */
		msgrcv(msgid,(struct msgbuf *)msgp, msgsz, mtype, 0666);
		printf("msgrcv() visszaadta: , a kapott uzenet: %d\n", msgp->pid);
		msgctl(msgid, IPC_STAT, buf); /* uzenetsor adatokat lekerdezem,
						     benne azt is, hany uzenet van meg */
	}


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 19991214L

struct msgbuf1
{
    long mtype;
    char mtext[512];
} sendbuf, *msgp;

int main()
{
    int msgid, msgflg, ret, msgsz;
    key_t key;

    key = MSGKEY;
    msgflg = 00666 | IPC_CREAT;
    msgid = msgget(key, msgflg);

    if (msgid == -1){
        perror("msgget() :");
        exit(-1);
    }

    printf("> msgid: %d\n", msgid);

    msgp = &sendbuf;
    msgp->mtype = 1;
    strcpy(msgp->mtext,"Sarosi Bence");
    msgsz = strlen(msgp->mtext) + 1;
    ret = msgsnd(msgid,(struct msgbuf *)msgp, msgsz, msgflg);

    printf("\n1. msgsnd() recieved: ");
    printf("%s\n", msgp->mtext);

    strcpy(msgp->mtext,"DQ1Q17");
    msgsz = strlen(msgp->mtext) + 1;
    ret = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);

    printf("2. msgsnd() recieved: ");
    printf("%s\n", msgp->mtext);

    return 0;
}


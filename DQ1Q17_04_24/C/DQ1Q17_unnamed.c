#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
     int pipefd[2];
     pid_t cpid;
     char buf;
     char szoveg[32];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(-1);
    }

    printf("%d: fd1: %d, fd2: %d\n",getpid(),pipefd[0],pipefd[1]);

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(-1);
    }

    if (cpid == 0) {
        printf("\n%d: >> child <<\n",getpid());
        close(pipefd[1]);

        printf("%d: recieved message:\n%d: ",getpid(),getpid());
        while (read(pipefd[0], &buf, 1) > 0) {
            printf("%c",buf);
        }

        printf("\n%d: Pipe closed!\n",getpid());

        close(pipefd[0]);
        exit(0);
    }

    else {
        printf("\n%d: >> parent <<\n",getpid());
        close(pipefd[0]);

        strcpy(szoveg,"Sarosi Bence DQ1Q17\0");
        printf("%d: message: %s [%ld]\n",getpid(),szoveg,strlen(szoveg));

        write(pipefd[1], szoveg, strlen(szoveg));

        close(pipefd[1]);
        wait(NULL);
        exit(0);
    }
}


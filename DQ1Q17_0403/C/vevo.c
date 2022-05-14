#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void do_nothing();

int main()
{
    printf("PID = %d\n", getpid());
    signal(SIGTERM, do_nothing);
    printf("Waiting\n");
    pause();
    printf("Alarm recieved\n");
    return 0;
}

void do_nothing() {
    printf("do_nothing() running\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void kezelo(int i) {
    printf("Signal kezeles: %d\n", i);
    return;
}

int main()
{
    printf("PID = %d\n", getpid());
    printf("Signal kezeles atvetele: %d\n", signal(SIGTERM, &kezelo));
    while(1) {
        printf("lepes\n");
        sleep(3);
    }
    return 0;
}

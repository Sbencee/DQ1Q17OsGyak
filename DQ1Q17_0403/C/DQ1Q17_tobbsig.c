#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void handlerSignals(int sig);

int main()
{
    printf("PID = %d\n", getpid());

    if(signal(SIGINT, handlerSignals) == SIG_ERR) {
        printf("[SIGINT] : ERROR\n");
        return 0;
    }

    if(signal(SIGQUIT, handlerSignals) == SIG_ERR) {
        printf("[SIGQUIT] : ERROR\n");
        return 0;
    }

    while(1) {
        pause();
    }

    return 0;
}

void handlerSignals(int sig)
{
    if(sig == SIGINT) {
        printf("\nSIGINT signal: %d\n", sig);
        signal(SIGINT, SIG_DFL);
    }

    else if(sig == SIGQUIT) {
        printf("\nSIGQUIT signal: %d\n", sig);
        signal(SIGQUIT, SIG_DFL);
    }
}

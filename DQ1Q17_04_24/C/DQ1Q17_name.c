#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd, ret;
    char buf[32];
    buf[0] = 0;

    ret=mkfifo("DQ1Q17",00666);

    if (ret == -1){
        perror("mkfifo()");
        exit(-1);
    }

    fd=open("DQ1Q17",O_RDWR);

    if (fd == -1){
        perror("open() hiba!");
        exit(-1);
    }

    strcpy(buf,"Sárosi Bence\0");
    printf("write(): %s [%ld]\n",buf,strlen(buf));
    write(fd,buf,strlen(buf));

    ret=read(fd,buf,32);
    printf("read(): olvasott %d byteot, ami a kovetkezo: %s\n",ret,buf);

    close(fd);
    unlink("DQ1Q17");
    
    return 0;
}


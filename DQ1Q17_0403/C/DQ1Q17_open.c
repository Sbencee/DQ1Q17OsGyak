#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd, ret;
    char buf[50];
    buf[0] = 0;

    fd = open("AUGHMI.txt", O_RDWR);

    if(fd == -1) {
        perror("ERROR ");
        exit(-1);
    }

    ret = read(fd, buf, sizeof(buf));
    printf("byte: %d\n%s\n", ret, buf);
    strcpy(buf, "AUGHMI");

    ret = lseek(fd, 0, SEEK_SET);
    printf("lseek() : %d\n", ret);

    ret = write(fd, buf, 6);
    printf("write() : %d\n", ret);

    close(fd);
    return 0;
}

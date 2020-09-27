#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd = 0, ret = 0;

    fd = open(argv[1], O_RDWR);

    if(fd == -1)
    {
        printf("unable to open file..\n");
    }
    ret = lseek(fd, 1024, SEEK_END);
    printf("%d", ret);


    write(fd, " ",1 );
    close(fd);
    return 0;
}


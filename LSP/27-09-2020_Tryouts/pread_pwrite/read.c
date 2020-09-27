#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    char buffer[30];
    int ret = 0;
    char path[60] = {'\0'};

    fd = open("data.txt", O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open\n");
        return -1;
    }

    lseek(fd, 10, SEEK_SET);

    ret = read(fd, buffer, 30);

    if(ret == -1)
    {
        printf("Unable to read\n");
        return -1;
    }


    write(1, buffer, ret);
    
    close(fd);
    return 0;
}


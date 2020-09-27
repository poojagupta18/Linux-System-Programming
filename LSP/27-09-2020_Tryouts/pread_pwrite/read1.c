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
        printf("Unable to create symbolic link\n");
        return -1;
    }

    //lseek(fd, 10, SEEK_SET);

    //ret = read(fd, buffer, 30);

    //Inbetween lseek and read context switch may happen.So that data may get change while reading(if some process writes in the same file).
    //So to make this two system calls atomic function pread() is introduced
    //pread() atomic read operation

    ret = pread(fd, buffer, 30, 10);
    //1: file descriptor
    //2: address of buffer
    //3: no of bytes to read
    //4: offset from where we want to read

    if(fd == -1)
    {
        printf("Unable to open symbolic link\n");
        return -1;
    }


    write(1, buffer, ret);

    close(fd);
    return 0;
}


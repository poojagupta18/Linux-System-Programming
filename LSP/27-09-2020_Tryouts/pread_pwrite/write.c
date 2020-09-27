#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    char buffer[30] = "Hello";
    int ret = 0;
    char path[60] = {'\0'};

    fd = open("data1.txt", O_WRONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    lseek(fd, 10, SEEK_SET);

    ret = write(fd, buffer, 10);

   // ret = pwrite(fd, buffer, 30, 10);
    //1: file descriptor
    //2: address of buffer
    //3: no of bytes to read
    //4: offset from where we want to read

   if(ret == -1)
    {
        printf("Unable to write\n");
        return -1;
    }
   
    close(fd);
    return 0;
}


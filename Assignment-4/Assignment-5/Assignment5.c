//Write a program which accept directory name from user and copy 10 bytes from all regular file into newly created file named demo.txt.

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{

    int fd = 0;
    int bytes = 0;
    int readStatus = 0;
    char buf[21];

    if(argc != 3)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }


    fd = open(argv[1], O_RDONLY);
    bytes = atoi(argv[2]);
    if(fd == -1)
    {
        printf("Unable to open %s file ...\n", argv[1]);
    }

    lseek(fd,bytes, SEEK_SET);

    readStatus = read(fd, buf, 20);

    if(readStatus > 0)
    {
        printf("%s", buf);
    }

    close(fd);
    return 0;
}

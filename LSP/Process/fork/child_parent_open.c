#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{

    int fd = 0;

    fd = open("Hello.txt", O_WRONLY);

    if(fork() == 0)
    {
        write(fd, "Child", 5);
    }
    else
    {
        write(fd, "Parent", 6);
    }


    exit(0);
}


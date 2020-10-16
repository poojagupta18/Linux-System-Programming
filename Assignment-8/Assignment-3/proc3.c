//Write a program which creates a process which will accepts directory name and rename all the files as 1.txt, 2.txt etc.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char* argv[], char *env[])
{
    int fd = 0;
    int status;

    if(fork() == 0)
    {
        printf("child process A created...PID is %d\n", getpid());
        execl("./a.out","A", argv[1], NULL);
    }
    else
    {
        printf("Parent process created...PID is %d\n", getpid());
        wait(&status);
        printf("Child process A Terminated...");

    }

    printf("Parent process Terminated...");

    return 0;
}


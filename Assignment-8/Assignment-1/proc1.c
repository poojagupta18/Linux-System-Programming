//Write a program which creates new process which will write all the filenames present on desktop

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#


int main(int argc, char* argv[], char *env[])
{
    int fd = 0;
    int status;

    if(fork() == 0)
    {
        printf("child process created...PID is %d\n", getpid());
        execl("./a.out", argv[1], NULL);
    }
    else
    {
        printf("Parent process created...PID is %d\n", getpid());
        wait(&status);
        printf("Child process Terminated...");
    }

    return 0;
}


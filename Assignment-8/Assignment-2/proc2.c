//Write a program which creates new process which will write capital letter count in count.txt file
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
        printf("child process A created...PID is %d\n", getpid());
        execl("./a.out","A", argv[1], NULL);
    }
    else
    {
        if(fork() == 0)
        {
            printf("child process B created...PID is %d\n", getpid());
            execl("./a.out","B", argv[2], NULL);
        }

        printf("Parent process created...PID is %d\n", getpid());
        wait(&status);
        printf("Child process A Terminated...\n");
        printf("Child process B Terminated...\n");

    }

    printf("Parent process Terminated...PID:  %d\n", getpid());

    return 0;
}


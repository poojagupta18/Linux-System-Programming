#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{

    if(fork() == 0)
    {
        printf("Child A is Running....\n");
        printf("Parent process for 1st child is running with PID: %d\n", getppid());
        exit(0);
    }
    else
    {
        printf("Parent process A is running with PID: %d\n", getpid());
        wait(NULL);
        printf("Child A is Terminated....\n");

    }
    if(fork() == 0)
    {
        printf("Child B is Running....\n");
        printf("Parent process for 2nd child is running with PID: %d\n", getppid());
        exit(0);
    }
    else
    {
        printf("Parent process A is running with PID: %d\n", getpid());
        wait(NULL);
        printf("Child Process B Terminated\n");
    }

    printf("Common Flow for ALL Process and PID is %d\n", getpid());

    exit(0);
}


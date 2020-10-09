#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{

    if(fork() == 0)
    {
        printf("Inside child process 1 with PID : %d\n", getpid());

        if(fork() == 0)
        {
            printf("Inside child process 2 with PID: %d\n", getpid());
            
            if(fork == 0)
            {
                printf("Inside child process 3 with PID: %d", getpid());
            }
            else{
                printf("Inside Process 3 with PID : %d\n", getpid());
                wait(NULL);
                printf("Child 3 is terminated..\n ");
            }
        }
        else{
            printf("Inside Process 2 with PID : %d\n", getpid());
            wait(NULL);
            printf("Child 2 is terminated..\n ");
        }
    }
    else
    {
        printf("Inside Process 1 with PID : %d\n", getpid());
        wait(NULL);
        printf("Child 1 Process Terminated...\n");
    }

    printf("Normal flow of PID : %d\n", getpid());

    exit(0);
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{

    if(fork() == 0)
    {
        execl("./demoexe","10","1", "A", NULL);
    }
    else
    {
        printf("Parent process A is running with PID: %d\n", getpid());
        if(fork() == 0)
        {
            execl("./demoexe","20","1", "B", NULL);
        } else {
           // printf("Parent process  A is running with PID: %d\n", getpid());
        }
        if(fork() == 0)
        {
            execl("./demoexe","50","1", "C", NULL);
        } else {
           // printf("Parent process  A is running with PID: %d\n", getpid());
        }
    }
    exit(0);
}


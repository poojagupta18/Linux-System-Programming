

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int ret = 0;
    int pid = 0, status =0;
    ret = fork();
    
    if(ret == 0)
    {
        printf("Child process created...\n");
        execl("./myexe", argv[1], NULL);
    } 
    else
    {
        printf("Parent process waits...\n");
        pid = wait(&status);
        printf("Terminating the parent process\n");
    }    
    
    
    return 0;
}


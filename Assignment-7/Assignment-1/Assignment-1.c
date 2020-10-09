#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{

   if(fork() == 0)
   {
       printf("inside child process with PID : %d\n", getpid());
   }
   else
   {
       printf("Inside Parent Process with PID : %d\n", getpid());
       wait(NULL);
       printf("Child Process Terminated...\n");
   }

   printf("Normal flow of PID : %d\n", getpid());

    exit(0);
}


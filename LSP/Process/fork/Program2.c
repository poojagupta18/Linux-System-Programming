#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
   int ret = 0;
   
   ret = fork(); //fork return 2 values, process id of child to parent and 0 to childjhjh
   
   if(ret == 0) //child process is running
   {
       printf("Child process is running with PID : %d\n", getpid());
       printf("Parent of child process  : %d\n", getppid());
       printf("Child says : value of ret is : %d\n", ret);
   }
   else   // Parent process is running
   {
       printf("Parent process is running with PID : %d\n", getpid());
       printf("Parent of parent process(Terminal) is running with PID : %d\n", getppid());
       printf("Parent says: value of ret is %d\n", ret);   
   }
   

    exit(0);
}


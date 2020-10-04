#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//execl creates new process with new stack, data, text section

int main(int argc, char* argv[])
{

       if(fork() == 0)
       {
          // execl("./demo1exe","", "Python","Golang", NULL); //argv[0] = "", argv[1]="Python", argv[2]="Golang"
           execl("./demo1exe","Python","Golang", NULL);
       }
       else
       {
           printf("Parent process is running with PID: %d\n", getpid());
       }



    exit(0);
}


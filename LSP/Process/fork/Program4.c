#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{

       if(fork() == 0)
       {
           execl("./demoexe", "", NULL);
       }
       else
       {
           printf("Parent process is running\n");
       }



    exit(0);
}


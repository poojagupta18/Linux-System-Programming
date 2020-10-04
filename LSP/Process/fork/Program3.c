#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
   
       printf("Hello\n");

       if(fork() == 0) //child
          printf("A\n");
       else            //parent
          printf("B\n");

       exit(0);
}


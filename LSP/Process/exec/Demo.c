

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int no = 10;

   printf("Child Process : %d\n", no);
   printf("PID of Demo process is %d\n", getpid());

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
    int ret = 0;

    printf("Parent process (Terminal) PID is: %d\n", getppid());

    printf("Curent process PID is : %d\n", getpid());

    for(;;)  //Infinite loop
    {}

    exit(0);
}


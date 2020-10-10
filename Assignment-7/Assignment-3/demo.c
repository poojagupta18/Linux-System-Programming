#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("sum of %d and %d for child process %s : %d is  %d\n", atoi(argv[0]), atoi(argv[1]), argv[2], getpid(), (atoi(argv[0]) + atoi(argv[1])));
    
    exit(0);
}


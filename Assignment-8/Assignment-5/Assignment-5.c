//Write a program which is used to increase priority.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[], char *env[])
{
    int ret = 0;
    
    ret = nice(-5);
    
    printf("Increased the priority of current Process by 5 is %d",ret );
    
    return 0;
}


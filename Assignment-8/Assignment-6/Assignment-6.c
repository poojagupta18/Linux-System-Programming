//Write a program which prints environment info.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[], char *env[])
{

    while(*env != NULL)
    {
      printf("%s\n", *env);
      env++;
    }

    return 0;
}


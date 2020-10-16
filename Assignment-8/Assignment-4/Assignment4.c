#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>


int main(int argc, char* argv[], char *env[])
{
    printf("Priority of current Process is %d", nice(0));

    return 0;
}


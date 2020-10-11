

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int ret = 0;
    int no = 10;

    ret = fork();

    if(ret == 0)
    {
        printf("Child process..%d\n", no);
    } 
    else
    {
        printf("Parent process...%d\n", no);
        
    }


    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int ret = 0;
    int no =10;

    ret = vfork();

    if(ret == 0)
    {
        execl("./myexe", "", NULL);
    } 
    else
    {
	printf("PID of child process(ret)...%d\n", ret);
        printf("PID of Parent process...%d\n", getpid());
        printf("Parent process...%d\n", no);
        
    }


    return 0;
}


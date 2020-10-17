//Write a program which is used to create simple thread by using pthread library.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void* Fun(void *p)
{
    printf("Inside thread with function Fun\n");

    pthread_exit(NULL);
}

int main(int argc, char* argv[], char *env[])
{
    pthread_t thread;
    int ret = 0;

    printf("Inside main\n");
    ret = pthread_create(&thread, NULL, Fun, NULL);

    if(ret != 0)
    {
        printf("Unable to create thread\n");
    }

    pthread_join(thread, NULL);

    printf("At the end of main\n");
    return 0;
}


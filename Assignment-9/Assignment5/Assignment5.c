//Write a program which is used to get thread id inside its thread function.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>


void* fun(void *p)
{

    printf("Thread id of fun is %lu\n", pthread_self());
    pthread_exit(NULL);
}

int main(int argc, char* argv[], char *env[])
{
    pthread_t thread1;
    int ret = 0;

    printf("Inside main\n");
    ret = pthread_create(&thread1, NULL, fun, NULL);

    if(ret != 0)
    {
        printf("Unable to create thread: thread1\n");
    }

    pthread_join(thread1, NULL);
    printf("At the end of main\n");
    return 0;
}


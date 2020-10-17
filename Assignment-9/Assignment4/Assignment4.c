//Write a program which creates single thread and we have to pass
//parameter to that thread from main thread.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

struct Arguments
{
    int no1;
    int no2;
    int result;
};

void* fun(void *arguments)
{
    struct Arguments *arg = arguments;

    printf("Inside thread fun:\n 1st arguments is %d\n 2nd Argument is %d\n",  arg->no1, arg->no2);
    arg->result = arg->no1 + arg->no2;

    pthread_exit(NULL);
}

int main(int argc, char* argv[], char *env[])
{
    pthread_t thread1;
    int ret = 0;
    struct Arguments argument1;
    
    argument1.no1 = 5;
    argument1.no2 = 500;

    printf("Inside main\n");
    ret = pthread_create(&thread1, NULL, fun, (void*)&argument1);

    if(ret != 0)
    {
        printf("Unable to create thread: thread1\n");
    }

    pthread_join(thread1, NULL);

    printf("Summation of %d and %d is %d", argument1.no1, argument1.no2, argument1.result);
    printf("At the end of main\n");
    return 0;
}


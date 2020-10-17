//Write a program which creates single thread and we have to pass
//parameter to that thread from main thread.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

struct Arguments
{
    int start;
    int end;
};

void* fun(void *arguments)
{
    struct Arguments *arg = (struct Arguments*)arguments;

    printf("Inside thread fun:\n 1st arguments is %d\n 2nd Argument is %d\n",  arg->start, arg->end);

    pthread_exit(NULL);
}

int main(int argc, char* argv[], char *env[])
{
    pthread_t thread1;
    int ret = 0;
    struct Arguments *argument1;

    argument1 = (struct Arguments*) malloc(sizeof(struct Arguments) * 1);

    argument1->start = 1;
    argument1->end = 500;
    
    printf("Inside main\n");
    ret = pthread_create(&thread1, NULL, fun, (void*)argument1);

    if(ret != 0)
    {
        printf("Unable to create thread: thread1\n");
    }
    
    pthread_join(thread1, NULL);

    printf("At the end of main\n");
    free(argument1);
    return 0;
}


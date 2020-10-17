//Write a program which creates 4 number of threads and our main thread
 //waits till all the thread terminates.
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>


void* fun(void *p)
{

    printf("Inside thread: %d\n",(int)p);
    pthread_exit(NULL);
}

int main(int argc, char* argv[], char *env[])
{
    pthread_t thread[4];
    int ret = 0;
    int i = 0;

    printf("Inside main thread\n");

    for(i = 1; i <= 4; i++)
    {
        ret = pthread_create(&thread[i], NULL, fun, (void*)i);

        if(ret != 0)
        {
            printf("Unable to create thread: thread1\n");
        }
    }

    for(i = 1; i <= 4; i++)
    {
        pthread_join(thread[i], NULL);
    }

    printf("At the end of main thread\n");
    return 0;
}


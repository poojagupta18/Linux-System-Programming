//Write a program which is used to predict the problem due to lack of
//synchronization.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

int count;


void* threadProc(void* p)
{
   int i = 0;
   count++;
   printf("Thread %d started\n", count);
   for(;i < 0xffffffff; i++);
    printf("Thread %d ended\n", count);

}

int main(int argc, char* argv[], char *env[])
{
    pthread_t thread1;
    pthread_t thread2;
    int ret = 0;

    printf("Inside main\n");

    ret = pthread_create(&thread1, NULL, threadProc, NULL);

        if(ret != 0)
        {
            printf("Unable to create thread: thread1\n");
        }

    ret = pthread_create(&thread2, NULL, threadProc, NULL);

    if(ret != 0)
    {
        printf("Unable to create thread: thread2\n");
    }   

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);



    printf("At the end of main\n");
    return 0;
}


//Write a program which creates two thread , and by using appropriate
//synchronization technique avoid the scheduling problem.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

int count;
pthread_mutex_t lock;

void* threadProc(void* p)
{
   int i = 0;
   pthread_mutex_lock(&lock);
   count++;


   printf("Thread %d started\n", count);
   for(;i < 0xffffffff; i++);
   printf("Thread %d ended\n", count);
   pthread_mutex_unlock(&lock);

}

int main(int argc, char* argv[], char *env[])
{
    pthread_t thread1;
    pthread_t thread2;
    int ret = 0;

    printf("Inside main\n");

    pthread_mutex_init(&lock, NULL);
    
    
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

    pthread_mutex_destroy(&lock);

    printf("At the end of main\n");
    return 0;
}


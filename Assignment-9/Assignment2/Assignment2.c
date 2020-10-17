//Write a program which creates two thread , first thread print numbers
//from 1 to 500 & other thread print the numbers from 500 to 1.

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

void* printDigit1(void *arguments)
{
    struct Arguments *arg = (struct Arguments*)arguments;
    
    int i = arg->start; 

    printf("Inside thread with Print Digit 1-->Prints from %d to %d\n", i, arg->end);

    for(; i <= (int)arg->end; i++)
    {
        printf("%d\n", i);
    }

    pthread_exit(NULL);
}

void* printDigit2(void *arguments)
{
    struct Arguments *arg = (struct Arguments*)arguments;

    int i = arg->start;

    printf("Inside thread with Print Digit 2 --->Prints from %d to %d\n", i, arg->end);

    for(; i <= (int)arg->end; i++)
    {
        printf("%d\n", i);
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[], char *env[])
{
    pthread_t thread1;
    pthread_t thread2;
    int ret = 0;
    struct Arguments *argument1;
    struct Arguments *argument2;

    argument1 = (struct Arguments*) malloc(sizeof(struct Arguments) * 1);
    argument2 = (struct Arguments*) malloc(sizeof(struct Arguments) * 1);

    argument1->start = 1;
    argument1->end = 500;
    
    argument2->start = 501;
    argument2->end = 1000;

    printf("Inside main\n");
    ret = pthread_create(&thread1, NULL, printDigit1, (void*)argument1);

    if(ret != 0)
    {
        printf("Unable to create printDigit1\n");
    }

    ret = pthread_create(&thread2, NULL, printDigit2, (void*)argument2);

    if(ret != 0)
    {
        printf("Unable to create printDigit2\n");
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("At the end of main\n");
    free(argument1);
    free(argument2);
    return 0;
}


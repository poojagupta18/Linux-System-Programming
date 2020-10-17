/* Write a program which creates two threads by using pthread API, where
   one thread count number of capital characters from demo.txt file and other
   threads count number of small characters from same file.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

int capitalCount = 0;
int smallCount = 0;

void* countCapitalCharacters(void *p)
{
    int fd = 0;
    int ret = 0;
    int count = 0;
    char buffer[1024];
    int i = 0;

    printf("Inside thread: CapitalCount\n");

    fd = open("demo.txt", O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the demo.txt for CapitalCount\n");
    }

    while((ret = read(fd, buffer, 1024)) != 0)
    {
        i = 0;
        for(; i < strlen(buffer); i++)
        {
            if(buffer[i] >= 'A' && buffer[i] <= 'Z')
            {
		//printf("buffer[i] = %c inside capital\n", buffer[i]);
                count++;
            }
        }
    }

    capitalCount = count;
    //printf("Count of Capital letters inside thread is %d\n", count);
    pthread_exit(NULL);
}

void* countSmallCharacters(void *p)
{

    int fd = 0;
    int ret = 0;
    int count = 0;
    char buffer[1024];
    int i = 0;

    printf("Inside thread: SmallCharacterCount\n");

    fd = open("demo.txt", O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the demo.txt for small Count\n");
    }

    while((ret = read(fd, buffer, 1024)) != 0)
    {
        i = 0;
        for(; i < strlen(buffer); i++)
        {
            if(buffer[i] >= 'a' && buffer[i] <= 'z')
            {
		//printf("buffer[i] = %c inside small\n", buffer[i]);
                count++;
            }
        }
    }

    smallCount = count;
    //printf("Count of small letters inside threads is %d\n", count);
    pthread_exit(NULL);
}


int main(int argc, char* argv[], char *env[])
{
    pthread_t thread1;
    pthread_t thread2;

    int ret = 0;

    printf("Inside main\n");

     ret = pthread_create(&thread1, NULL, countCapitalCharacters, NULL);

        if(ret != 0)
        {
            printf("Unable to create thread: thread1\n");
        }
    ret = pthread_create(&thread2, NULL, countSmallCharacters, NULL);

    if(ret != 0)
    {
        printf("Unable to create thread: thread1\n");
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);


    printf("Capital Character Count is %d\n", capitalCount);
    printf("Small Character Count is %d\n", smallCount);

    printf("At the end of main\n");
    return 0;
}


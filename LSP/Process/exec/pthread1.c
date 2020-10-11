

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

//callback methods for thread
void* Fun(void* p) //child thread
{
    int i =0;
    printf("Inside thread with fun \n");

    for(i =0 ; i < (int)p; i++)
    {
        printf("Fun : %d\n", i);
    }
    pthread_exit(NULL);
}

void* Gun(void* p) //child thread
{
    int i = 0;
    printf("Inside thread with Gun\n");

    for(i =0 ; i < (int)p; i++)
    {
        printf("Gun : %d\n", i);
    }
    pthread_exit(NULL); //terminate the thread
}

int main(int argc, char* argv[])
{

    pthread_t thread1;
    pthread_t thread2;
    int ret = 0;
    int no1 = 1000, no2 = 2000;

    printf("Inside main thread\n");
    ret = pthread_create(&thread1, //Address of pthread
                         NULL,    //Attribute of thread
                         Fun,    //Address of Callback function
                         (void*) no1 );  //Parameter of Callback function
    if(ret != 0) //If thread is not created
    {
        printf("Unable to create 1st thread\n");
    }

    ret = pthread_create(&thread2, //Address of pthread
                         NULL,    //Attribute of thread
                         Gun,    //Address of Callback function
                         (void *) no2);  //Parameter of Callback function
    if(ret != 0)
    {
        printf("Unable to create 2nd thread\n");
    }
    //sleep(10); BAD programming

    pthread_join(thread1,  //pthread_t pointer
                 NULL);   //status of

    pthread_join(thread2,  //pthread_t pointer
                 NULL);   //status of thread

    printf("At the end of main thread\n");
    return 0;
}


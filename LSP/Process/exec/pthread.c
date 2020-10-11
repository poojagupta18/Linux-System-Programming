

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

//callback methods for thread
void* Fun(void* p) //child thread
{
    printf("Inside thread with fun\n");

    pthread_exit(NULL);
}

void* Gun(void* p) //child thread
{
    printf("Inside thread with Gun\n");

    pthread_exit(NULL); //terminate the thread
}

int main(int argc, char* argv[])
{

    pthread_t thread1;
    pthread_t thread2;
    int ret = 0;

    printf("Inside main thread\n");
    ret = pthread_create(&thread1, //Address of pthread
                         NULL,    //Attribute of thread
                         Fun,    //Address of Callback function
                         NULL );  //Parameter of Callback function
    if(ret != 0) //If thread is not created
    {
        printf("Unable to create 1st thread\n");
    }

    ret = pthread_create(&thread2, //Address of pthread
                         NULL,    //Attribute of thread
                         Gun,    //Address of Callback function
                         NULL );  //Parameter of Callback function
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


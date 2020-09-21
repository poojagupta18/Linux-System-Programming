#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{

    int dirStatus = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }
    
    dirStatus = mkdir(argv[1], 07777);

    if(dirStatus != -1)
    {
        printf("%s directory created successfully....\n", argv[1]);
    }
    else
    {
        printf("Unable to create %s directory....\n", argv[1]);
        return -1;
    }

    return 0;
}

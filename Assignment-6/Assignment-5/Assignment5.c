//program which accepts Directory name and offset from user and remove data from that offset.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    int offset = atoi(argv[2]);

    if(argc != 3)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }
    printf("Insufficient arguments1111111111...\n");

    printf("%s\n", argv[1]);

    fd = open(argv[1],  O_TRUNC | O_RDWR );

    if(fd == -1)
    {
        printf("Unable to open file...\n");
    }

    truncate(argv[1], offset);


    return 0;
}

//program which accepts Directory name from user and creates file in that directory.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#include <malloc.h>
#include <dirent.h>
#include <memory.h>

int main(int argc, char* argv[])
{
    DIR *dirp;
    struct dirent *entry;
    char fileName[256];
    int fd = 0;


    if(argc != 3)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

    if((dirp = opendir(argv[1]) )== NULL)
    {
        printf("Unable to open directory...\n");
    }

    sprintf(fileName, "%s/%s", argv[1], argv[2]);

    fd = creat(fileName, 0777);

    if(fd == -1)
    {
        printf("Unable to create File...\n");
    }

    printf("File created successfully...\n");

    close(fd);
    closedir(dirp);

    return 0;
}

//program which accepts Directory name from user and deleted all files whoes size is greater than 100 bytes.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#include <malloc.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    struct stat fileStat;
    int ret = 0;
    long int fileSize = 0;
    char *buf;
    int readStatus, writeStatus = 0;
    DIR *dirp;
    struct dirent *entry;
    char fileName[256];
    char fileName1[256];
    int fd1 = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

    if((dirp = opendir(argv[1]) )== NULL)
    {
        printf("Unable to open directory...\n");
    }


    while((entry = readdir(dirp)) != NULL)
    {
       
        sprintf(fileName, "%s/%s", argv[1], entry->d_name);

        ret = stat(fileName, &fileStat);

        if(ret == 0)
        {
            if(fileStat.st_size > 100)
            {
                fd1 = remove(fileName);
                if(fd1 == 0)
                {
                    printf("File name : %s deleted successfully...\n", fileName);
                }

            }
        }

    }

    closedir(dirp);

    return 0;
}

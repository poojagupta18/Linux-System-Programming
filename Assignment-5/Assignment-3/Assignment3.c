//program which accepts Directory name from user and write information of all the regular file in and read from that file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#include <malloc.h>
#include <dirent.h>
#include <memory.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    struct stat fileStat;
    int ret = 0;
    char *buf;
    int readStatus, writeStatus = 0;
    DIR *dirp;
    struct dirent *entry;
    char fileName[256];
    char fileName1[256];
    int fd1 = 0;
    char inodeData[50];
    char fileSize[50];
    char linkCountData[50];
    char fileSystemNumber[50];
    char noOfBlockAllocated[50];
    char permission[50];

    if(argc != 2)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

    printf("Insufficient arguments.111111111..\n");
    if((dirp = opendir(argv[1]) )== NULL)
    {
        printf("Unable to open directory...\n");
    }

    //sprintf(fileName1, "%s/demo.txt", argv[1]);

    fd1 = open("Demo.txt", O_RDWR | O_APPEND | O_CREAT, 0777);

    if(fd1 == -1)
    {
        printf("Unable to open File...\n");
    }
    printf("Insufficient argument22222222..\n");

    while((entry = readdir(dirp)) != NULL)
    {
        printf("entry");
        sprintf(fileName, "%s/%s", argv[1], entry->d_name);

        ret = stat(fileName, &fileStat);

        printf("ret of stat = %d\n", ret);
        if(ret == 0)
        {
            if(S_ISREG(fileStat.st_mode))
            {
                printf("%s is a regular file with size = %ld", fileName, fileStat.st_size);
		sprintf(fileName1, "\nFileName is %s\n", fileName);
                write(fd1, fileName1, strlen(fileName1));
                sprintf(inodeData, "Inode Number : %ld\n", fileStat.st_ino);
                write(fd1,inodeData, strlen(inodeData));
                sprintf(fileSize,"File Size is %ld\n", fileStat.st_size);
                write(fd1, fileSize, strlen(fileSize));
                sprintf(noOfBlockAllocated, "No of Blocks allocated is %ld\n", fileStat.st_blocks);
                write(fd1, noOfBlockAllocated, strlen(noOfBlockAllocated));
                sprintf(fileSystemNumber, "File System number is %ld\n", fileStat.st_dev);
                write(fd1, fileSystemNumber, strlen(fileSystemNumber));
                write(fd1, "--------------------", strlen("--------------------"));
            }
        }
    }

    lseek(fd1, 0, SEEK_SET);

    printf("while for entry close\n");

    while((readStatus = read(fd1, buf, 255)) != 0)
    {
        if(readStatus != 0)
        {
            printf("%s", buf);

        }
    }

    close(fd1);
    closedir(dirp);

    return 0;
}

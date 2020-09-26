//program which accepts Directory name from user and write information of all the regular file in and read from that file.

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

        printf("Insufficient arguments.111111111..\n");
    if((dirp = opendir(argv[1]) )== NULL)
    {
        printf("Unable to open directory...\n");
    }

    //sprintf(fileName1, "%s/demo.txt", argv[1]);

    fd1 = open("Demo1.txt", O_RDWR | O_APPEND | O_CREAT, 0777);

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

	printf("%d", ret);
        if(ret == 0)
        {
            if(S_ISREG(fileStat.st_mode))
            {
                printf("%s is a regular file with size = %ld", fileName, fileStat.st_size);
                buf = (char*) malloc(sizeof(char) * fileStat.st_size);
                fd = open(fileName, O_RDONLY);

                if(fd != -1)
                {
                    readStatus = read(fd , buf, fileStat.st_size);

                    if(readStatus > 0)
                    {
                        printf("%s is a regular file with size = %ld\n", fileName, fileStat.st_size);

                        if ((writeStatus = write(fd1, buf, fileStat.st_size)) > 0)
                        {
                            printf("Written in file succesfully.%s data.\n", buf);

                        }
                    }

                    free(buf);
                    close(fd);

                }
            }
        }

    }

    while((readStatus = read(fd1, buf, 255)) != 0)
    {
        printf("%s", buf);
    }

    close(fd1);
    closedir(dirp);

    return 0;
}

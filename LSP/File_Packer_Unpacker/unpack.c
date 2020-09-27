/*
 * Application which is used to combine all regular file form directory into one regular file.
 *
 */
#include <stdio.h>
#include <unistd.h> //micro
#include <stdlib.h> //for library function
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <memory.h>

struct FileInfo
{
    char filename[256]; //File name
    long int fSize;          //File size
};

//myexe DirectoryName FileName
//argv[0] argv[1]       argv[2]
//argv[1] : Name of Directory that we want to open
//argv[2] : Name of file that we want to create
int main(int argc, char* argv[])
{

    DIR *dp = NULL;
    struct dirent *dip =NULL;
    struct stat sobj;
    char name[256] = {'\0'};
    int ret = 0;
    int fdDest = 0, fdSrc = 0;
    struct FileInfo fObj;
    char *buffer;
    long filesize;
    int readStatus, writeStatus = 0;

    if(argc != 2)
    {
        printf("Error: Insufficient arguments\n");
        printf("Usage: Directory_name File_name\n");
        printf("Directory_name: Name of directory which contains the file that we want to combine\n");
        printf("File_name: File name which contains data of all files\n");
        return -1;
    }

    fdSrc = open(argv[1], O_RDONLY);

    if(fdSrc == -1)
    {
        printf("Unable to open file %s\n", argv[1]);
    }

    printf("Size of fileInfo structure %zu\n", sizeof(fObj));

    while((ret = read(fdSrc, &fObj, sizeof(fObj))) != 0)
    {
        printf("FileName : %s and Size = %zu\n------------------\n",fObj.filename, fObj.fSize );

        fdDest = creat(fObj.filename, 0777);


        if(fdDest == -1)
        {
            printf("Unable to open %s file \n", fObj.filename);
        }

        buffer = (char*)malloc(fObj.fSize);

        //filesize  = fObj.fSize;
        readStatus = (int) read(fdSrc, buffer, fObj.fSize);

        printf("\nBuffer value:\n %s\n", buffer);


        if(readStatus == -1)
        {
            printf("Unable to read buffer of a file");
        }

        writeStatus = (int) write(fdDest, buffer, fObj.fSize);

        if(writeStatus == -1)
        {
            printf("Unable to write buffer of a file");
        }

        free(buffer);

        close(fdDest);

    }

    close(fdSrc);
    return 0;
}


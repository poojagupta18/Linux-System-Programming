/*
 * Application which is used to combine all regular file form directory into one regular file.
 * logic : [Write the Each filename, filesize as a structure[header] and write the data of file in one(packer) file.]
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
    char buffer[1024];
    int writeStatus = 0;

    if(argc != 3)
    {
        printf("Error: Insufficient arguments\n");
        printf("Usage: Directory_name File_name\n");
        printf("Directory_name: Name of directory which contains the file that we want to combine\n");
        printf("File_name: File name which contains data of all files\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open the directory i.e %s\n", argv[1]);
        return -1;
    }

    fdDest = creat(argv[2], 0777);

    if(fdDest == -1)
    {
        printf("Unable to open the file i.e %s\n", argv[2]);
        closedir(dp);
        return -1;
    }

    printf("Names of the files are:\n");
    while((dip = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s", argv[1], dip->d_name); //create relative path
        ret = stat(name, &sobj);

        if(S_ISREG(sobj.st_mode))
        {

            //fills structure which contains file information
            strcpy(fObj.filename, dip->d_name);

            fObj.fSize = sobj.st_size;

            printf("\nFilename : %s and size = %ld", fObj.filename, fObj.fSize);

            //writes fileinfo structure in file
            write(fdDest, &fObj, sizeof(fObj));

            fdSrc = open(name, O_RDONLY);

            memset(&fObj, 0, sizeof(fObj)); //zero out te memory

            //copies the content of all file
            while((ret = (int) read(fdSrc, &buffer, 1024)) != 0)
            {
                printf("Readn data of file %s is %s:\n", name, buffer);

                writeStatus = write(fdDest, &buffer, (int)ret);

                if(writeStatus == -1)
                {
                    printf("\nUnable to write in a file\n");
                }
            }
            memset(&buffer, 0, sizeof(buffer));
	    close(fdSrc);
            //printf("Name : %s size = %ld\n",dip->d_name, sobj.st_size);

        }



    }
    close(fdDest);
    closedir(dp);

    return 0;
}


/*
 * Implemention of CP command which is used to copy content from one file into another file
 *
 * Usage:
 * cp file1.txt file2.txt
 * file1.txt contains data
 * We have to create file2.txt and write all the data from file1.txt into it.
 *
 */
#include <stdio.h>
#include <unistd.h> //micro
#include <stdlib.h> //for library function
#include <fcntl.h>

int main(int argc, char* argv[])
{

    int fdSrc = 0;
    int fdDest = 0;
    char buffer[1024] = "\0";
    int ret = 0;
    int ret1 = 0;

    if(argc != 3)
    {
        printf("Error: Invalid argument\n");
        printf("Usage: CP source.txt destination.txt\n");
        return -1;
    }

    fdSrc = open(argv[1], O_RDONLY);

    if(fdSrc == -1)
    {
        printf("Unable to open source file ie %s\n", argv[1]);
        return -1;
    }

    fdDest = creat(argv[2], 0777);

    while((ret = read(fdSrc, buffer, sizeof(buffer))) != 0)
    {
	 if(ret == -1)
	{
		printf("Error while reading from the file....\n");
                close(fdSrc);
		close(fdDest);	
		return -1;
	}	

       ret1 =  write(fdDest, buffer, ret);

       if(ret1 == -1)
	{
		printf("Error while writing in the file....\n");
                close(fdSrc);
		close(fdDest);	
		return -1;
	}	
    }

    if(fdDest == -1)
    {
        printf("Unable to create destination file ie %s\n", argv[2]);
        return -1;
    }

    close(fdSrc);
    close(fdDest);

    printf("Copy Suceessful....\n");


    return 0;
}


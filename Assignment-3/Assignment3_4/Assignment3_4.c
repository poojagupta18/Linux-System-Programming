#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int retRead = 0;
    int retWrite = 0;
    char *buf = NULL;
    int fileSize = 0;
    int cursor = 0;

    if(argc != 3)
    {
        printf("Insufficient argument...\n");
        return -1;
    }

    fd1 = open(argv[1], O_RDONLY);

    if(fd1 == -1)
    {
        printf("Unable to open the existing file....\n");
        return -1;
    }

    fd2 = creat(argv[2], 0x7777);

    if(fd2 == -1)
    {
        printf("Unable to create the new file....\n");
        return -1;
    }

    fileSize = lseek( fd1, 0, SEEK_END);

    cursor = lseek(fd1,0,SEEK_SET);

   // printf("File size is % d and argv value is %s and file descriptor is %d, Current cursor is %d ", fileSize, argv[1], fd1, cursor);

    buf = (char*) calloc(fileSize, sizeof(char));

    retRead = read(fd1, buf, fileSize);

    if(retRead > 0)
    {
        printf("File has been read successfully and contents are %s", buf);
    }

    retWrite = write(fd2, buf, fileSize);

    if(retWrite < 0)
    {
        printf("Failed to write in a file...\n");
	return-1;
    }

        printf("File has been Written successfully and contents are %s", buf);
    return 0;
}

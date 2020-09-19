#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{

int fd = 0;
int fileSize = 0;
int readStatus = 0;
char *buf = NULL;
int cursor = 0;

fd = open(argv[1], O_RDONLY);

fileSize = lseek( fd, 0, SEEK_END);

cursor = lseek(fd,0,SEEK_SET);

printf("File size is % d and argv value is %s and file descriptor is %d, Current cursor is %d ", fileSize, argv[1], fd, cursor);

buf = (char*) calloc(fileSize, sizeof(char));

readStatus = read(fd, buf, fileSize);

if(readStatus > 0)
{
printf("File has been read successfully and contents are %s", buf);
}

return 0;
}

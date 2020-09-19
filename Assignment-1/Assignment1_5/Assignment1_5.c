#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char* argv[])
{

int fd = 0;
char *buf = NULL;
buf = (char*) calloc(5 , sizeof(char));
int count = atoi(argv[2]);
int statusOfRead = 0;
char buf1;
 
if(argc != 3)
{
 printf("Unable to open the file...\n");
 return -1;
}

fd = open(argv[1], O_RDONLY);

if(fd == -1)
{
 printf("Unable to open the file...as open status is -1...\n");
 return -1;
}
statusOfRead = read(fd, buf, count);

printf("status of read = %d \n ", statusOfRead);

if(statusOfRead > 0)
{
 printf("First %d characters of file are %s \n" ,count, buf);
}

free(buf);

return 0;
}




#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
int fd = 0;

if(argc != 3)
{
printf("Invalid arguments...\n");
return -1;
}
fd = open(argv[1],  O_CREAT | O_WRONLY);

if(fd == -1)
{
	return -1;
}

printf("File opened successfuly with file decriptor %d.\n", fd);

int writeStatus = write(fd, argv[2], strlen(argv[2]));

if(writeStatus > 0)
{
printf("File written successfuly with %d characters.\n",  writeStatus);
}

close(fd);

return 0;
}

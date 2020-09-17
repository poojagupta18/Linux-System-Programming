#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int fd = 0;
	
	if(argc != 3)
	{
		printf("Insufficient arguments...\n");
		return -1;
	} 

	if( 0 == strcmp(argv[2], "read"))
	{
		fd = open(argv[1], O_RDONLY);
	}
	else if(strcmp(argv[2], "write") == 0)
	{
		fd = open(argv[1], O_WRONLY);
	}
	else if(strcmp(argv[2], "readwrite") == 0)
	{
		fd = open(argv[1], O_RDWR);
	}
	else{
		printf("Mode is invalid...\n");
		return -1;
	}
	if(fd == -1)
	{
		printf("Unable to open the file....\n");
		return -1;
	}

	printf("File Opened successfully with file descriptor %d\n", fd);
	return 0;
}

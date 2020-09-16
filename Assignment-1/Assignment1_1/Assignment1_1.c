#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	int fd = 0;

	if(argc != 2)
	{
		printf("Insufficient arguments...\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open the file...\n");
		return -1;
	}

	printf("File opened successfully with file descriptor %d\n",fd);

	close(fd);

	return 0;
}

#include<stdio.h>
#include<string.h>
#include<unistd.h> 
#include<errno.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<fcntl.h> 


int main(int argc, char* argv[])
{
	int fd = 0;
	int isFileExist = 0;
	
	if(argc != 3)
	{
		printf("Insufficent Arguments....");
		return -1;
	}

	//Here, for access() function, the first argument takes the path to the directory/file and the second argument takes flags R_OK, W_OK, X_OK or F_OK.

    	//F_OK flag : Used to check for existence of file.
   	// R_OK flag : Used to check for read permission bit.
   	// W_OK flag : Used to check for write permission bit.
   	// X_OK flag : Used to check for execute permission bit.

	
	isFileExist = access(argv[1], F_OK);
	
	//If the file does not exist, the value of fd will become -1. 
	if(isFileExist == -1)
	{
		printf("File does not exist...");
		return -1;
	}
	
	if( 0 == strcmp(argv[2], "read"))
	{
		fd = access(argv[1], R_OK);
	}
	else if(strcmp(argv[2], "write") == 0)
	{
		fd = access(argv[1], W_OK);
	}
	else if(strcmp(argv[2], "execute") == 0)
	{
		fd = access(argv[1], X_OK);
	}
	else{
		printf("Mode is invalid...\n");
		return -1;
	}
	
	if(fd == -1)
	{
		printf("Process do not have permission to access the given file....%d\n", fd);//The file descriptor value is -1
		return -1;
	}
	
	printf("Process have permission to access the given file....%d\n",fd); //The file descriptor value is 0
	
	return 0;
}

//Write a program which accept directory name from user and copy 10 bytes from all regular file into newly created file named demo.txt.
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char* argv[])
{

    struct stat file1stat;
    struct dirent *dir;
    DIR *dirp;
    int fd1 = 0;
    int fd2 = 0;
    int readByte1 = 0;
    int flag = 1;
    int readStatus = 0;
    char name[256];
    char buf[10];
    int writeStatus = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

    if((dirp = opendir(argv[1])) == NULL)
    {
        printf("Unable to open directory...\n");
    }

    fd1 = open("demo.txt", O_CREAT| O_RDWR | O_APPEND, 0777 );

    if(fd1 == -1)
    {
        printf("Unable to open demo.txt...\n");
    }

    while( (dir = readdir(dirp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],dir->d_name);
        
        stat(name, &file1stat);
        //printf("%s", file1stat.st_mode);

        if(S_ISREG(file1stat.st_mode))
        {

            fd2 = open(name, O_RDONLY);

            readStatus = read(fd2, buf, 10);
	   // printf("%s with fd = %d with readStatus = %d with data = %s.\n",name, fd2, readStatus, buf);
            writeStatus = write(fd1,buf, 10);
	    
	/*if( writeStatus > 0)
		{
			printf("Demo.txt with fd = %d with writeStatus = %d with data = %s.\n", fd1, writeStatus, buf);
		}
	*/

        }

      //  printf("%s\n", dir->d_name);
    }

    close(fd1);
    close(fd2);
    closedir(dirp);
    return 0;
}

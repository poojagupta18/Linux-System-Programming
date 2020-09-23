//program which accepts two filenames from user and checks whther the content of two files are same or not

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{

    struct stat file1stat;
    struct stat file2stat;
    int fd1 = 0;
    int fd2 = 0;
    int readByte1 = 0;
    int readByte2 = 0;
    char buf1[256];
    char buf2[256];
    int flag = 1;
	
	int i =0;

    if(argc != 3)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

	fd1 = open(argv[1], O_RDONLY);

    if(  fd1 == -1 )
    {
        printf("Unable to open 1st file....\n");
        return -1;
    }
    if((fd2 = open(argv[2], O_RDONLY)) == -1)
    {
        printf("Unable to open 2nd file....\n");
        return -1;
    }

    printf("fd1 = open(argv[1], O_RDONLY) = %d\n", open(argv[1], O_RDONLY));

    printf("fd2 = open(argv[2], O_RDONLY) = %d\n\n", open(argv[2], O_RDONLY));


    if((stat(argv[1], &file1stat) == -1)  || (stat(argv[2], &file2stat) == -1))
    {

        printf("unable to fetch file informations....\n");
        return -1;
    }
   // printf("file1stat->st_size = %ld & file2stat->st_size = %ld\n\n", file1stat.st_size , file2stat.st_size);

    if(file1stat.st_size != file2stat.st_size)
    {
        printf("File data are not same....\n");
        close(fd1);
        close(fd2);
        return -1;
    }

    while((readByte1 = read(fd1, buf1, 255)) && (readByte2 = read(fd2, buf2, 255)))
    {

          //  printf("buf1 = %s readByte1 = %d \t buf2  = %s readByte2 = %d\t", buf1,readByte1, buf2, readByte2);

          
		while(readByte1 <= i) //loop continues till readByte1 value
		{
			if(buf1[i] != buf2[i])
			{
				flag = 0;
				break;
			}
		}

    }

    if(flag == 0)
    {
        printf("File data are not same....\n");
        close(fd1);
        close(fd2);
        return -1;
    }
    else
    {
        printf("FIle data are same...\n");
	close(fd1);
        close(fd2);
    }

    return 0;
}

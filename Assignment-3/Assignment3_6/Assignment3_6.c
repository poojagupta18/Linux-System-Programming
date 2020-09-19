#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
    int fd1 = 0;
    DIR *d = NULL;
    DIR *d2 = NULL;
    struct dirent *dir = NULL;
    int directory2 = 0;
    int readStatus = 0;
    int writeStatus = 0;
    char buf[1024];

    if(argc != 3)
    {
        printf("Insufficient argument..\n");
        return -1;
    }

    if((d = opendir(argv[1])) == NULL)
    {
        printf("Unable to open the directory...\n");
        return -1;
    }

    if((d2 = opendir(argv[2])) == NULL)
    {
        printf("Unable to open the directory...\n");
        return -1;
    }
    if(d)
    {
        while((dir = readdir(d)) != NULL)
        {
            fd1 = open(dir, O_RDONLY);
            if(fd1 == -1)
            {
                printf("Unable to open file %s ...\n", dir->d_name);
            }
            readStatus = read(fd1, buf, 1023);

            if(readStatus == -1)
            {
                printf("Unable to read file %s ...\n", dir->d_name);

            }
		
	    directory2 = opendir(d2)

	

        }
        closedir(d);
    }



    return 0;
}


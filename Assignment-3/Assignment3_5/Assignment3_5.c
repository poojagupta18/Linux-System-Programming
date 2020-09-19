#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    DIR *d = NULL;
    struct dirent *dir = NULL;
    int isPresent = 0;

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

    if(d)
    {
        while((dir = readdir(d)) != NULL)
        {
            if(strcmp(dir->d_name, argv[2]) == 0)
            {
                isPresent = 1;
                break;
            }

        }
	closedir(d);
    }



    if(isPresent == 1 )
    {
        printf("Given file %s is present in %s directory.\n", argv[2],argv[1]);
    }
    else
    {
        printf("Given file %s is not present in %s directory.\n", argv[2],argv[1]);
        return -1;
    }

    return 0;
}


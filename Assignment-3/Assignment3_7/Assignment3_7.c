#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    DIR *d;
    struct dirent *dir;
    struct stat buf;
    int j = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

    d = opendir(argv[1]);

    printf("Files before deletion....\n");
    if (d)
    {
        while ((dir = readdir(d)) != NULL )
        {

            printf(" file name is %s and size = %ld\n", dir->d_name, buf.st_size);


        }
        closedir(d);
    }


    d = opendir(argv[1]);

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {

            if( buf.st_size == 0)
            {
                unlink(dir->d_name);
            }

        }
        closedir(d);
    }


    d = opendir(argv[1]);
    printf("Files After deletion....\n");

    if (d)
    {
        while ((dir = readdir(d)) != NULL )
        {

                printf(" file name is %s and size = %ld\n", dir->d_name, buf.st_size);


        }
        closedir(d);
    }
    return 0;
}

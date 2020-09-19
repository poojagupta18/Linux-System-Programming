#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    DIR *d;
    struct dirent *dir;
    int fd = 0;
    struct stat buf;

    if(argc != 2)
    {
        printf("Insufficient arguments...");
        return -1;
    }

    d = opendir(argv[1]);

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s is a", dir->d_name);
            fd = stat(dir->d_name, &buf);

            if(S_ISREG(buf.st_mode))
            {
                printf("Regular file\n");
            }
            else if(S_ISDIR(buf.st_mode))
            {
                printf("Directory File\n");
            }
        }
        closedir(d);
    }

    return 0;
}

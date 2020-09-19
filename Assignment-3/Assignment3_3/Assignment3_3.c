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
    int count = 0;
    long *blockSize = NULL;
    int i,j = 0;
    long max = 0;
    int maxValueindex = -1;


    if(argc != 2)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

    d = opendir(argv[1]);

    printf("Open dir = %p", d);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            count++;
        }
        closedir(d);
    }

    blockSize = (long*) malloc(count * sizeof(long));


    d = opendir(argv[1]);

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {

            fd = stat(dir->d_name, &buf);

            blockSize[i] = buf.st_size;

          //  printf("\n%s and size = %ld\n", dir->d_name, buf.st_size);
        }
        closedir(d);
    }

   /* for(i = 0; i < count; i++)
    {
        printf("Blcksize at index %d is %ld\n", i, blockSize[i]);
    }
   */

    for(i = 0; i < count; i++)
    {
        if(blockSize[i] > max )
        {
            max = blockSize[i];
            maxValueindex = i;
        }
    }

    //printf(" maxValueindex = %d  and max value is %ld\n",maxValueindex, max );

    d = opendir(argv[1]);

    if (d)
    {
        while ((dir = readdir(d)) != NULL )
        {

            fd = stat(dir->d_name, &buf);
            if(j == maxValueindex)
            {
                printf("\nLargest file name is %s and size = %ld\n", dir->d_name, buf.st_size);
            }
            j++;

        }
        closedir(d);
    }
    return 0;
}

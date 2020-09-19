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
    int i = 0;

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
 	    printf("%s and size = %ld\n", dir->d_name, buf.st_size);        
        }
        closedir(d);
    }


    return 0;
}

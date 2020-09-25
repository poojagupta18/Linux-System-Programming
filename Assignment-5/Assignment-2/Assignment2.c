#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#include <malloc.h>
int main(int argc, char* argv[])
{
    int fd = 0;
    struct stat fileStat;
    int ret = 0;
    long int fileSize = 0;
    char *buf;
    int readStatus = 0;

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

   // printf("File opened successfully with file descriptor %d\n",fd);

    ret = stat(argv[1], &fileStat);

    if(ret == -1)
    {
        printf("File stat failed with %d status.\n",ret);
    }


   // printf("Mode = %d\n", S_ISREG(fileStat.st_mode));
   // printf("File size = %ld\n", fileStat.st_size);

    fileSize = fileStat.st_size;

    buf = (char*) malloc(fileSize * sizeof(char));

    readStatus = read(fd, buf, fileSize);

    if(readStatus == -1)
    {
        printf("Unable to read the file.");
	free(buf);
        close(fd);
    }

    printf("Employee Data is : \n%s", buf);

    close(fd);
    free(buf);

    return 0;
}

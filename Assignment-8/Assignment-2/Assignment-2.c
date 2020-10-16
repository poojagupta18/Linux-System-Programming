//Write a program which counts capital letters.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char* argv[], char *env[])
{
    int fd1 = 0;
    int count = 0;
    int ret = 0;
    char buffer[1024];
    int i =0;
    int writeStatus = 0;
    char fileInfo[1024];

    printf("child process %s Started...PID is %d\n",argv[0], getpid());

    fd1 = open(argv[1], O_RDONLY);

    if(fd1 == -1)
    {
        printf("Unable to open file %s\n", argv[1]);
        return -1;
    }
    
    while((ret = read(fd1, buffer, 1024)) != 0)
    {
        for(  i = 0; i < ret; i++)
        {
            if(buffer[i] >= 'A' && buffer[i] <= 'Z')
            {
		printf(" %c ", buffer[i]);
                count++;
            }
        }
    }

    close(fd1);
    
    fd1 = open("count.txt", O_WRONLY | O_APPEND);

    if(fd1 == -1)
    {
        printf("Unable to open file count.txt\n");
        return -1;
    }
    
    sprintf(fileInfo, "Capital letter count of file %s is %d\n", argv[1], count);
    writeStatus = write(fd1, fileInfo, strlen(fileInfo));
    
    if(writeStatus == -1)
    {
        printf("Unable to write in file %s\n", argv[1]);
        return -1;
    }
    else
    {
        printf("\nCapital letter count for file %s written successfully in count.txt.\n", argv[1]);

    }
    close(fd1);

    return 0;
}


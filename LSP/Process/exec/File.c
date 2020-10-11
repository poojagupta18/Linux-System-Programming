//File subsystems Application

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
    int fd = 0;
    char buffer[1024] = {'\0'};
    int ret = 0;

    fd = open(argv[0], O_RDONLY); //as we are taking from command line arguments from the program so argv[0]


    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Data from the file is:\n");

    while((ret = read(fd, buffer, sizeof(buffer))) != 0)
    {
        write(1, buffer, ret);
    }

    printf("End of the process\n");
    return 0;
}


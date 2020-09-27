#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    char buffer[30];
    int ret = 0;
    char path[60] = {'\0'};

    fd = symlink("data.txt", "MyShortcut1.txt");

    if(fd == -1)
    {
        printf("Unable to create symbolic link\n");
        return -1;
    }

    printf("symbolic link created..\n");

    fd = open("MyShortcut1.txt", O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open symbolic link\n");
        return -1;
    }

    ret = read(fd, buffer, 30);

    printf("Data from symbolic link is:\n");
    write(1, buffer, ret);

    ret = readlink("MyShortcut1.txt", path, 60);

    if(ret == -1)
    {
        printf("failed....");
    }

    printf("Data from symbolic link through readlink is:\n");
    write(1, path, ret);



    close(fd);
    return 0;
}


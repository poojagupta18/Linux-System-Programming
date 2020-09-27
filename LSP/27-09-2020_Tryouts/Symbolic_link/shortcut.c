#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd = 0;

    fd = symlink("data.txt", "MyShortcut.txt");

    if(fd == -1)
    {
        printf("Unable to create symbolic link\n");
        return -1;
    }

    printf("symbolic link created..\n");

    return 0;
}


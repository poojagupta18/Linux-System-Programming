//Write a program login user name and home directory.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pwd.h>

int main(int argc, char* argv[], char *env[])
{
    struct passwd *pw = getpwuid(getuid());

    printf("Home dir name is %s\n",pw->pw_dir);
    printf("Login user name is %d\n", getuid());

    return 0;
}


//Write a program which  accepts directory name and rename all the files as 1.txt, 2.txt etc.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>


int main(int argc, char* argv[], char *env[])
{
    int ret = 0;
    DIR *dirp;
    struct dirent *entry;
    int i = 1;
    char renamedfilename[255];
    char filname[255];
    struct stat filestat;

    printf("Child Process Started with PID: %d/n", getpid());

    if((dirp = opendir(argv[1])) == NULL)
    {
        printf("Unable to open the directory...\n");
        return -1;
    }

    while((entry = readdir(dirp)) != NULL)
    {
        //printf("%s\n", entry->d_name);
        sprintf(renamedfilename, "%s/%d.txt", argv[1],i);
        sprintf(filname, "%s/%s", argv[1], entry->d_name);
       // printf("%s ===> %s\n", filname, renamedfilename);
        stat(filname, &filestat);

        if(S_ISREG(filestat.st_mode))
        {
            ret = rename(filname, renamedfilename);
            if(ret != 0)
               printf("Unable to rename\n");
            i++;
        }

    }

   // printf("ret = %d", ret);
    return 0;
}


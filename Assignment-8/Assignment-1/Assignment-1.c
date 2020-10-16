//Write a program which writes all the file names of desktop in newly created demo.txt file

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char* argv[], char *env[])
{
    int fd = 0;
    DIR *dir = NULL;
    struct dirent *entry;
    int i = 0;
    printf("Before loop\n");
    char *str;
    char *str1;
    char *Path;
    int writeStatus = 0;
    int ret = 0;

    printf("Child process starts.....PID = %d\n", getpid());
    while (env[i] != NULL)
    {

        //printf("%s \n", env[i]);
        if(strcmp(env[i],"HOME=/home/sonu") == 0)   //here put the username like /xyz
        {
            str = strtok(env[i], "=");

            while(str != NULL)
            {
                str1 = str;
                str = strtok(NULL, "=");
            }
        }
        i++;
    }


    strcat(str1,"/Desktop");
    //printf("str = %s & str1 = %s\n", str, str1);

    if((dir = opendir(str1)) == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    if(creat(argv[0] ,0777) == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    fd = open(argv[0], O_WRONLY);
    
    if(fd == -1)
    {
        printf("Unable to open file\n");
         return -1;
    }
    
    while((entry = readdir(dir)) != NULL)
    {
        //printf("Filename: %s ", entry->d_name);
        
        ret = write(fd, entry->d_name, strlen(entry->d_name));
        
        if(ret == -1)
        {
            printf("Unable to write filenames in the file..\n");
        }
        write(fd, "\n" , strlen("\n"));
    }

    printf("after loop\n");

    return 0;
}


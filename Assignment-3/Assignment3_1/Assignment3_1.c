#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(int argc, char* argv[])
{
    DIR *d;
    struct dirent *dir;

   if(argc != 2)
   {
	printf("Insufficient arguments...");
	return -1;
   }

    d = opendir(argv[1]);

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }

return 0;
}

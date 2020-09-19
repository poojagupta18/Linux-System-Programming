#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {

    int fd = 0;
    struct stat buf; //A structure where data about the file will be stored


    if(argc != 2)
    {
        printf("Insufficient arguments....");
        return -1;
    }

    fd = stat(argv[1], &buf);
	
	printf("argv[2] = %s\n", argv[2]);

    if(fd < 0)                  //Returns a negative value on failure.
    {
	printf("fie not found....");
	return -1;
    }

    printf("Inode number = %ld\n", buf.st_ino);
    printf("Blocksize for file system IO = %ld\n", buf.st_blksize);

    printf("Total size in bytes = %ld\n", buf.st_size);

    printf("User Id = %d\n", buf.st_uid);
    printf("Group Id = %d\n", buf.st_gid);

    printf((buf.st_mode & S_IRUSR)? "r":"-");
    printf((buf.st_mode & S_IWUSR)? "w":"-");
    printf((buf.st_mode & S_IXUSR)? "x":"-");
    printf("\n");
    printf("\nFile Permissions Group\n");
    printf((buf.st_mode & S_IRGRP)? "r":"-");
    printf((buf.st_mode & S_IWGRP)? "w":"-");
    printf((buf.st_mode & S_IXGRP)? "x":"-");
    printf("\n");
    printf("\nFile Permissions Other\n");
    printf((buf.st_mode & S_IROTH)? "r":"-");
    printf((buf.st_mode & S_IWOTH)? "w":"-");
    printf((buf.st_mode & S_IXOTH)? "x":"-");
    printf("\n");
   // printf("Last time of access = %f\n", buf.st_atim);
   // printf("Last modifion icattime  = %ld\n", buf.st_mtim);
   // printf("Last time of access = %ld\n", buf.st_atim);
    //printf("Last status change = %d\n", buf.st_ctim);
    return 0; 
}

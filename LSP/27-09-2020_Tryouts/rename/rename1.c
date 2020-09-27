#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int ret = 0;
    
    //oldfile, newfile
    ret = rename("data1.txt", "lsp1/RenamedData1.txt");
    
    if(ret == -1)
    {
        printf("Rename failed %d", ret);
    }
    printf("Rename successful with ret %d", ret);

    return 0;
}


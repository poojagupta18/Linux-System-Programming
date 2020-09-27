#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    int ret = 0;

    ret = truncate(argv[1], 20);
    
    if(ret == -1)
    {
        printf("Unable to truncate");
    }
	
    printf("ret = %d", ret);
    
    return 0;
}


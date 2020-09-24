//program which writes structure in a file. Structure should contain information of Employee.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
struct Employee
{
    int employeeId;
    char *name;
    long mobileNumber;

};

int main(int argc, char* argv[])
{

    int fd = 0;
    char buf[21];
    int writeStatus = 0;
    struct Employee emp;
    char data[100];


    if(argc != 2)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }


    fd = open(argv[1], O_RDWR | O_APPEND);

    if(fd == -1)
    {
        printf("Unable to open %s file ...\n", argv[1]);
        return -1;
    }

    emp.employeeId = 1;
    emp.mobileNumber = 999999299;
    emp.name = "abc";

    sprintf(data, "Employee Id : %d\nEmployee Name: %s\nEmployee MobileNumber = %ld\n ",emp.employeeId,emp.name, emp.mobileNumber);

    writeStatus =  write(fd, data, strlen(data));

    if(writeStatus < 0)
    {
        printf("Employee structure written failed in the %s file\n", argv[1]);
        close(fd);
        return -1;
    }

    printf("Employee structure written successfully in the %s file\n", argv[1]);

    close(fd);


    return 0;
}

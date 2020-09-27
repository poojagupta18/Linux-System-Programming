#include <stdio.h>

int main()
{
    int no1 = 0;
    int no2 = 0;
    int no3 = 0;
    int ans = 0;

    printf("Enter 3 numbers:\n");

    scanf("%d %d %d", &no1, &no2, &no3);

    ans = no1 + no2 + no3;

    printf("Addition is %d\n", ans);
	
    return 0;
}


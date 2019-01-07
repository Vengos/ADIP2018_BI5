#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1;
    int j = 1;
    for(i; i <= 10; i++)
    {
        for(j; j <= 10; j++)
        {
            printf("%d x %d = %d\n", j,i, j*i);
        }
        printf("\n");
        j = 1;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    int count = 0;
    int i = 0;

    printf("Input your number:");
    scanf("%d", &number);

    for (i = 2; i <= number; i++)
    {
        while(number%i == 0)
        {
            if(count == 0)
            {
                printf("%d",i);
                count++;
            }
            else
            {
                printf(" x %d",i);
            }
            number/=i;
        }
    }

    return 0;
}

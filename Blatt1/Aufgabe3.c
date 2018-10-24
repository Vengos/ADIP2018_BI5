#include <stdio.h>
#include <stdlib.h>


int main()
{
    int number = 0;
    int i = 0;
    printf("Input your prime number: ");
    scanf("%d", &number);

    if(number < 0)
    {
        printf("The number is negative");
    }
    else if( number > 0 && number < 2)
    {
         printf("%d is not a prime number.\n", number);
    }

    else
    {
        for(i = 2; i <= number; i++)
        {
            if(number % i == 0 && number != i)
            {
                printf("%d is not a prime number.\n", number);
                break;
            }
            else if( number % i != 0 || number == i)
            {
                printf("%d is a prime number.\n", number);
                break;
            }
        }
    }
    return 0;
}



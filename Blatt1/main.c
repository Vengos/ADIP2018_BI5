#include <stdio.h>
#include <stdlib.h>

int sum(int number)
{
    int calc = 0;
    int result = 0;

    calc = number*(number+1);
    result = calc/2;

    return result;
}

int squaresum(int number)
{
    int calc = 0;
    int result = 0;

    calc = (number*(number+1))*(2*number+1);
    result = calc/6;

    return result;
}

int main()
{
    int number = 0;
    int action = 0;

    printf("For sum from 1 to n print 1.\n");
    printf("For sum from 1 to n^2 print 2.\n");
    scanf("%d", &action);
    printf("Input your number:");
    scanf("%d", &number);

    if(action == 1)
    {
        printf("Sum is: %d", sum(number));
    }
    else if(action == 2)
    {
          printf("Sum is: %d", squaresum(number));
    }
    else
    {
        printf("Wrong choice");
    }

    return 0;
}

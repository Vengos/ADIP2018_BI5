#include <stdio.h>
#include <stdlib.h>

unsigned long fib_rec(unsigned long n)
{
    if ( n == 0 )
    {
        return 0;
    }
    else if ( n == 1 )
    {
        return 1;
    }
    else
    {
        return ( fib_rec(n-1) + fib_rec(n-2) );
    }
}

int main()
{

    unsigned long n = 0;
    int i = 0;

    printf("How much Fibonacci series do you want to have? ");

    scanf("%i",&n);

    printf("Fibonacci series:\n");

    for ( i = 0 ; i < n ; i++ )
    {
        printf("%lu\n", fib_rec(i));
    }

    return 0;
}

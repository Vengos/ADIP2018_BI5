#include <stdio.h>
#include <stdlib.h>



int main()
{
    int a;
    int n;
    int result = 1;
    printf("Geben Sie die Basis a ein: ");
    scanf("%d", &a);
    printf("Geben Sie den Exponent n ein: ");
    scanf("%d", &n);
//Teilaufgabe a
    int i;
    for (i = 0; i < n; i++)
    {
        result = result * a;
    }
    printf("a) %d^%d = %d mit %d Schritten\n", a, n, result , i);

//Teilaufgabe b
    i = 0;
    result = 1;
    int tempA = a;
    int tempN = n;
    while (tempN != 0)
    {
        i++;
        if (tempN % 2 == 0)
        {
            tempA = tempA * tempA;
            tempN = tempN / 2;
        }
        else
        {
            tempN = tempN - 1;
            result = result * tempA;
        }
    }
    printf("b) %d^%d = %d mit %d Schritten\n", a, n, result , i);
    return 0;
}

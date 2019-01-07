#include <stdio.h>
#include <stdlib.h>

int teilerSumme(int n)
{
    int summe = 0;
    int i = 0;
    for (i = 1; i <= n/2; i++)
    {
        if(n%i == 0)
        {
            summe = summe + i;
        }
    }
    return summe;
}

int isPerfect(int n)
{
    if(teilerSumme(n) == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isDeficient(int n)
{
    if(teilerSumme(n) < n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printAllPerfect(int r)
{
    int i = 0;
    for (i = 0; i < r; i += 1)
    {
        if (isPerfect(i))
        {
            printf("%d ", i);
        }
    }
}

void printAllDeficient(int r)
{
    int i = 0;
    for (i = 0; i < r; i += 1)
    {
        if (isDeficient(i))
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int n;
    printf("Geben Sie die Zahl ein: ");
    scanf("%d", &n);
    if(isPerfect(n))
    {
       printf("%d ist eine perfekte Zahl.\n", n);
    }
    else
    {
        printf("%d ist keine perfekte Zahl.\n", n);
    }

    if(isDeficient(n))
    {
       printf("%d ist eine defiziente Zahl.\n", n);
    }
    else
    {
        printf("%d ist keine defiziente Zahl.\n", n);
    }

    int r = 0;
    printf("Geben Sie eine Zahl ein fuer die sie alle kleinen Zahlenueberpruefen wollen: ");
    scanf("%d", &r);
    printf("Alle perfekte Zahlen < r: ");
    printAllPerfect(r);
    printf("\n");
    printf("Alle defiziente Zahlen < r: ");
    printAllDeficient(r);
    return 0;
}

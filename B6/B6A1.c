#include <stdio.h>
#include <stdlib.h>

int main(void)
{
/* Statische Alloziierung zweier gegebener 4x4-Matrizen mit expliziten Werten und einer mit Nullen initalisierten Loesungs-Matrix */
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    printf("Geben sie Anzahl von Zeilen fuer Matrix A: \n");
    scanf("%d",&i);
    printf("Geben sie Anzahl von Spalten fuer Matrix A: \n");
    scanf("%d",&j);
    printf("Geben sie Anzahl von Zeilen fuer Matrix B: \n");
    scanf("%d",&k);
    printf("Geben sie Anzahl von Spalten fuer Matrix B: \n");
    scanf("%d",&l);


    float a[i][j];
    float b[k][l];
    float c[i][l];

    if(j!=k)
    {
        printf("Die Spaltenanzahl der Matrix A ungleich der Zeilenanzahl der Matrix B ist!");
        return 0;
    }

    float input;
    int n;
    int m;
    int p;

    printf("Geben Sie Werte der Matrix A ein: \n");

    for(n=0;n<i;n++)
    {
        for(m=0;m<j;m++)
        {
            printf("%d Zeile und %d Spalte: \n", n+1,m+1);
            scanf("%f",&input);
            a[n][m]=input;
        }
    }
    printf("Geben Sie Werte der Matrix B ein: \n");
    for(n=0;n<k;n++)
    {
        for(m=0;m<l;m++)
        {
            printf("%d Zeile und %d Spalte : \n", n+1,m+1);
            scanf("%f",&input);
            b[n][m]=input;
        }
    }

    for(n=0;n<i;n++)
    {
        for(m=0;m<l;m++)
        {
            c[n][m]=0;
        }
    }

        for(n=0;n<i;n++)
        {
            for(m=0;m<j;m++)
            {
              for(p=0;p<k;p++)
              {
                c[n][m]+=a[n][p]*b[p][m];
              }
              printf("%f    ", c[n][m]);
            }
            printf("\n");
        }
    return 0;
}

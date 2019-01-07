#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nachname[30];
    float note;
} student;

int main()
{
    int action = 0;
    float temp;

    printf("Anzahl von Studenten:\n");
    scanf("%i", &action);

    student stud[action];

    for(int i = 0;i<action;i++)
    {
        printf("Nachname von Student %i:\n", i+1);
        scanf("%30s", stud[i].nachname);
        printf("Note von Student %i:\n", i+1);
        scanf("%3f", &stud[i].note);

        while(stud[i].note < 1 || stud[i].note > 5)
        {
            printf("Die Note muss zwischen 1.0 und 5.0 liegen!\n");
            printf("Note von Student %i:\n", i+1);
            scanf("%1f", &stud[i].note);
        }
    }

    for(int i = 1;i<action;i++)
    {
        if(stud[i-1].note <= stud[i].note)
        {
            temp = stud[i-1].note;
        }
        else
        {
            continue;
        }
    }

    printf("Beste/n Student/en:\n");
    for(int i = 0;i<action;i++)
    {
        if(stud[i].note == temp)
        {
            printf("Nachname: %s\n", stud[i].nachname);
            printf("Note: %.1f\n", stud[i].note);
        }
        else
        {
            continue;
        }
    }

    temp = 0;
    for(int i = 0;i<action;i++)
    {
        temp += stud[i].note;
    }
    printf("Durschnittsnote: %.1f\n", temp/action);

    return 0;
}

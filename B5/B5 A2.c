#include <stdio.h>
#include <stdlib.h>
#define DYNARRAY_INITIAL_CAPACITY 10
#define DYNARRAYMIN_INITIAL_CAPACITY 10


typedef struct
{
    int size;
    int capacity;
    int *data;
}DynArray;

typedef struct
{
    int size;
    int capacity;
    int *data;
}DynArrayMin;

void dynArray_init(DynArray *dynArray)
{
    dynArray->size = 0;
    dynArray->capacity = DYNARRAY_INITIAL_CAPACITY;

    dynArray->data = malloc(sizeof(int) * dynArray->capacity);
}

void dynArray_add(DynArray *dynArray, int value)
{
    if (dynArray->size >= dynArray->capacity)
    {
        dynArray->capacity *= 2;
        dynArray->data = realloc(dynArray->data, sizeof(int) * dynArray->capacity);
    }

    dynArray->data[dynArray->size++] = value;
}

void print_dynArray(DynArray *dynArray)
{
    int i = 0;

    for(i = 0; i < dynArray->capacity; i++)
    {
        printf("%i ", dynArray->data[i]);
    }
}

void dynArray_free(DynArray *dynArray)
{
    free(dynArray->data);
}

void dynArrayMin_init(DynArrayMin *dynArrayMin)
{
    dynArrayMin->size = 0;
    dynArrayMin->capacity = DYNARRAYMIN_INITIAL_CAPACITY;

    dynArrayMin->data = malloc(sizeof(int) * dynArrayMin->capacity);
}

void dynArrayMin_add(DynArrayMin *dynArrayMin, int value)
{
    while(dynArrayMin->size >= dynArrayMin->capacity)
    {
        dynArrayMin->capacity++ ;
        dynArrayMin->data = realloc(dynArrayMin->data, sizeof(int) * dynArrayMin->capacity);
    }

    dynArrayMin->data[dynArrayMin->size++] = value;
}

void print_dynArrayMin(DynArrayMin *dynArrayMin)
{
    int i = 0;

    for(i = 0; i < dynArrayMin->capacity; i++)
    {
        printf("%i ", dynArrayMin->data[i]);
    }
}


void dynArrayMin_free(DynArrayMin *dynArrayMin)
{
    free(dynArrayMin->data);
}

int main()
{
    DynArray dynArray;
    DynArrayMin dynArrayMin;

    dynArray_init(&dynArray);
    dynArrayMin_init(&dynArrayMin);

    int i;
    for (i = 0; i < 50; i++)
    {
        dynArray_add(&dynArray, i);
    }

    for (i = 0; i < 50; i++)
    {
        dynArrayMin_add(&dynArrayMin, i);
    }

    printf("\nDynArray:");
    print_dynArray(&dynArray);
    printf("\nDynArrayMin:");
    print_dynArrayMin(&dynArrayMin);

    dynArray_free(&dynArray);
    dynArrayMin_free(&dynArrayMin);

    return 0;
}

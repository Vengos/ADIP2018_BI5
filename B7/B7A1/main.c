#include <stdio.h>
#include <stdlib.h>

/*
a.)
L1:|11|-|07|-|03|




L2: |14|-|05|*/

typedef struct DoubleNode
{
    struct DoubleNode *next;
    double data;
} DoubleNode;

DoubleNode *insertFirst(DoubleNode *head , double d)
{
    DoubleNode *tmp;
    tmp = malloc(sizeof(DoubleNode));
    tmp ->data = d;
    tmp ->next = head;
    return tmp;

}

DoubleNode *reverseList(DoubleNode *head)
{

    DoubleNode *newNext = NULL;
    DoubleNode *cursor = head;
    DoubleNode *oldNext = cursor ->next;
    while (cursor != NULL)
    {
        oldNext = cursor ->next;
        cursor ->next = newNext;
        newNext = cursor;
        cursor = oldNext;

    }
    return newNext;

}

DoubleNode *reverseListCon(DoubleNode *head)
{
    DoubleNode *cursor = head;
    DoubleNode *reversedList = NULL;
    while (cursor != NULL)
    {
        reversedList = insertFirst(reversedList , cursor ->data);
        cursor = cursor ->next;

    }
    return reversedList;

}

DoubleNode *insertLast(DoubleNode *head , double d)
{
    DoubleNode *tmp = malloc(sizeof(DoubleNode));
    tmp ->data = d;
    tmp ->next = NULL;

    if (head == NULL) return tmp;

    DoubleNode *cursor = head;
    while (cursor ->next != NULL)
    {
        cursor = cursor ->next;

    }
    cursor ->next = tmp;
    return head;

}

DoubleNode *delete(DoubleNode *head , int position)
{
    if (head == NULL) return head;
    if (position == 0)
    {
        DoubleNode *tmp = head ->next;
        free(head);
        return tmp;

    }

    int i = 0;
    DoubleNode *cursor = head;
    while (cursor ->next != NULL && i <= position - 2)
    {
        cursor = cursor ->next;
        i += 1;

    }
    if (i != position - 1) return head;
    DoubleNode *tmp = cursor ->next;
    cursor ->next = cursor ->next ->next;
    free(tmp);
    return head;

}

DoubleNode *insert(DoubleNode *head , double d, int position)
{
    if (head == NULL && position != 0) return head;
    if (position == 0) return insertFirst(head , d);

    int i = 0;
    DoubleNode *cursor = head;
    while (cursor ->next != NULL && i <= position - 2)
    {
        cursor = cursor ->next;
        i += 1;

    }
    if (i != position - 1) return head;
    DoubleNode *tmp = malloc(sizeof(DoubleNode));
    tmp ->data = d;
    tmp ->next = cursor ->next;
    cursor ->next = tmp;
    return head;

}


void printList(DoubleNode *head)
{
    for (DoubleNode *tmp = head; tmp != NULL; tmp = tmp ->next)
    {
        printf("%lf, ", tmp ->data);

    }
    printf("\n");

}

int main(int argc , char *argv[])
{
    DoubleNode *L2, *L1 = NULL;

    L1 = insertFirst(L1, 2.0);
    L1 = insertFirst(L1, 7.1);
    L1 = insertFirst(L1, 3.2);
    L2 = reverseListCon(L1);
    L1 = reverseList(L1);
    L2 = insertFirst(L2, 4.0);

    printList(L1);
    printList(L2);

    L1 = delete(L1, 2.0);
    printList(L1);
    printList(L2);

    L1 = insert(L1, 6.6, 1);
    printList(L1);
    printList(L2);
    return 0;

}

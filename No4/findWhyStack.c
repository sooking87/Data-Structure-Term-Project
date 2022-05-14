#include <stdio.h>
#include <string.h>
#include <stdlib.H>

typedef struct
{
    int id;
    char name[10];
    char grade;
} element;

typedef struct stackNode
{
    element data;
    struct stackNode *link;
} stackNode;

void push(stackNode **top, element data)
{
    stackNode *temp;
    temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = data;
    temp->link = *top;
    *top = temp;
}

int main()
{
    stackNode *top = NULL;
    element data1, data2, data3, data4;

    data1.id = 1;
    strcpy(data1.name, "LEE");
    data1.grade = 'A';

    data2.id = 2;
    strcpy(data2.name, "Park");
    data2.grade = 'B';

    printf("push data1 : (%d, %s, %d)\n", data1.id, data1.name, data1.grade);
    push(&top, data1);

    printf("push data1 : (%d, %s, %d)\n", data2.id, data2.name, data2.grade);
    push(&top, data2);

    return 0;
}
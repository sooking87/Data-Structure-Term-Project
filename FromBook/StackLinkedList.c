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

element pop(stackNode **top)
{
    stackNode *temp;
    element data;
    temp = *top;
    if (temp == NULL)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    else
    {
        data = temp->data;
        *top = temp->link;
        free(temp);
        return data;
    }
}

element peek(stackNode *top)
{
    element data;
    if (top == NULL)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    else
    {
        data = top->data;
        return data;
    }
}

void delete (stackNode **top)
{
    stackNode *temp;
    if (*top == NULL)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    else
    {
        temp = *top;
        *top = (*top)->link;
        free(temp);
    }
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

    data3 = peek(top);
    printf("peek data2 : (%d, %s, %d)\n", data3.id, data3.name, data3.grade);
    delete (&top);
    printf("delete data2\n");
    data4 = pop(&top);
    printf("pop data1 : (%d, %s, %d)\n", data4.id, data4.name, data4.grade);

    return 0;
}

#include <stdio.h>
#define STACK_SIZE 100

/* 1차원 배열을 이용한 stack 구현 */

typedef int element; // element를 int 타입으로 정의
element stack[STACK_SIZE];

void push(int *top, element item)
{
    if (*top >= STACK_SIZE - 1)
    {
        printf("Stack if FULL\n");
        return;
    }
    stack[++(*top)] = item;
}

element pop(int *top)
{
    if (*top == 01)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    else
        return stack[(*top)--];
}

int isEmpty(int *top)
{
    if (*top == -1)
        return 1;
    else
        return 0;
}

void delete (int *top)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    else
        (*top)--;
}

element peek(int top)
{
    if (top == -1)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    else
        return stack[top];
}

int main()
{
    int top = -1;
    element data1, data2;
    printf("push data1: %d\n", 1);
    push(&top, 1);
    printf("push data 2: %d\n", 2);
    push(&top, 2);
    data2 = peek(top);
    printf("peek data2: %d\n", data2);
    delete (&top);
    printf("delete data2\n");
    data1 = pop(&top);
    printf("pop data1: %d\n", data1);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define STACK_SIZE 100

typedef char element; // element를 char 타입으로 정의

// -> ok
int isEmpty(int *top)
{
    if (stack[*top] == '\0') // top이 바뀌어도 수정할 필요 없음
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
int isFull(int *top)
{
    if (*top >= STACK_SIZE) // top이 바뀌어도 수정할 필요 없음
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
void push(int *top, element item)
{
    // printf("push 함수에서 item: %d\n", item);
    if (isFull(top) == 1)
    {
        printf("Stack is FULL\n");
        exit(1);
    }
    // printf("push 이전 &top: %d\n", *top);
    stack[++(*top)] = item;
    // printf("push 이후 &top: %d\n", *top);
}

// -> ok
element pop(int *top)
{
    int data;
    if (isEmpty(top) == 1)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    data = stack[*top];
    stack[(*top)--] = '\0';

    // printf("pop 이후 &top: %d\n", *top);
    return data;
}

element peek(int *top)
{
    printf("peek *top: %d\n", *top);
    if (isEmpty(top) == 1)
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    else
    {
        return stack[*top];
    }
}

void delAll(int *top)
{
    if (isEmpty(top) == 1)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    for (int i = 0; stack[i] != '\0'; i++)
    {
        stack[(*top)--] = '\0';
    }
}
void printAll(int *top)
{
    if (isEmpty(top) == 1)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    // NULL 인덱스 찾기
    for (int i = 0; i < 14; i++)
    {
        if (stack[i] == '\0')
        {
            printf("NULL index is %d\n", i);
        }
        printf("stack[%d] : %c\n", i, stack[i]);
    }

    for (int i = 0; stack[i] != '\0'; i++)
    {
        printf("stack[%d] : %d\n", i, stack[i]);
    }
}

int main()
{
    int top = -1;
}
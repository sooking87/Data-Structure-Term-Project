#include <stdio.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];

void push(int *top, int item)
{
    if (*top >= STACK_SIZE - 1)
    {
        printf("Stack ks FULL\n");
        return;
    }
    stack[++(*top)] = item;
}

int pop(int *top)
{
    if (isEmpty(&top) == 1)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    else
        return stack[(*top)--];
}

int isEmpty(int *top)
{
    if (*top <= -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infix_to_postfix(char[] F_original) {
    while (true) {

    }
}

char getToken(char[] F_original) {
    
}


int main()
{
    int top = -1;
}
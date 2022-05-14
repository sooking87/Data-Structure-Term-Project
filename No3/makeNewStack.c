#include <stdio.h>
#define STACK_SIZE 100
// 포인터를 이용해서 배열을 만들 예정

typedef int element;
typedef struct
{
    int top;
    int length;
} createHeader;

char *makeNewNode()
{
    char *stack[STACK_SIZE] = {'\0'};
    createHeader *HeaderNode;
    HeaderNode->top = -1;
    HeaderNode->length = 0;
    stack[++(HeaderNode->top)] = HeaderNode;
    return stack;
}

void push(int *top, element item)
{
    // printf("push함수에서 item: %d\n", item);
    if (isFull(top) == 1)
    {
        printf("Stack is FULL\n");
        exit(1);
    }
    // printf("push 이전 &top: %d\n", *top);
    stack[++(*top)] = item;
    stack[0]++;
    // printf("push 이후 &top: %d\n", *top);
}

int main()
{
    char stack[] = makeNewNode();
    push()
}


// 헤더 노드 만들기 -> 길이 정보를 담고 있음 따라서 stack[0]은 길이를 말함.
// -> ok
/*
void createStack(int *top)
{
    int len = 0;
    *top = -1;
    stack[++(*top)] = len;
    // printf("createHeader 이후 &top: %d\n", *top);
}
*/
// -> ok
#include <stdio.h>
#define STACK_SIZE 100
// �����͸� �̿��ؼ� �迭�� ���� ����

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
    // printf("push�Լ����� item: %d\n", item);
    if (isFull(top) == 1)
    {
        printf("Stack is FULL\n");
        exit(1);
    }
    // printf("push ���� &top: %d\n", *top);
    stack[++(*top)] = item;
    stack[0]++;
    // printf("push ���� &top: %d\n", *top);
}

int main()
{
    char stack[] = makeNewNode();
    push()
}

// ��� ��� ����� -> ���� ������ ��� ���� ���� stack[0]�� ���̸� ����.
// -> ok
/*
void createStack(int *top)
{
    int len = 0;
    *top = -1;
    stack[++(*top)] = len;
    // printf("createHeader ���� &top: %d\n", *top);
}
*/
// -> ok
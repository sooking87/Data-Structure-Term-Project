#include <stdio.h>
#include <stdlib.H>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Header
{
    int length;
    Node *top; // ù ��° ��带 ����Ŵ
    Node *tail;
} linkedList;

linkedList *createStack()
{
    linkedList *H;
    H = (linkedList *)malloc(sizeof(linkedList));
    H->length = 0;
    H->top = NULL;
    H->tail = NULL;
    printf("�� ���� ����\n");
    return H;
}

int isEmpty(linkedList *stack)
{
    return (stack->top == NULL);
}
void push(linkedList *stack, int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;

    if (isEmpty(stack))
    {
        stack->tail = newNode;
    }
    stack->length++;
}

int main()
{
    linkedList *str;
    str = createStack();
    printf("length: %d\n", str->length);
    printf("isEmpty(str): %d\n", isEmpty(str));
    push(str, 1);
    printf("===============1�߰�============\n");
    printf("length: %d\n", str->length);
    printf("isEmpty(str): %d\n", isEmpty(str));
    printf("str->tail: %p\n", str->tail);
    printf("str->top: %p\n", str->top);
    printf("str->top->data: %d\n", str->top->data);
    push(str, 2);
    printf("===============2�߰�============\n");
    printf("length: %d\n", str->length);
    printf("str->tail: %p\n", str->tail);
    printf("str->top: %p\n", str->top);
    printf("str->top->data: %d\n", str->top->data);
    push(str, 3);
    printf("===============3�߰�============\n");
    printf("length: %d\n", str->length);
    printf("str->tail: %p\n", str->tail);
    printf("str->top: %p\n", str->top);
    printf("str->top->data: %d\n", str->top->data);
}
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
    Node *top; // 첫 번째 노드를 가리킴
    Node *tail;
} linkedList;

linkedList *createStack()
{
    linkedList *H;
    H = (linkedList *)malloc(sizeof(linkedList));
    H->length = 0;
    H->top = NULL;
    H->tail = NULL;
    printf("빈 스택 생성\n");
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
        fprintf(stderr, "메모리 할당 에러\n");
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
    printf("===============1추가============\n");
    printf("length: %d\n", str->length);
    printf("isEmpty(str): %d\n", isEmpty(str));
    printf("str->tail: %p\n", str->tail);
    printf("str->top: %p\n", str->top);
    printf("str->top->data: %d\n", str->top->data);
    push(str, 2);
    printf("===============2추가============\n");
    printf("length: %d\n", str->length);
    printf("str->tail: %p\n", str->tail);
    printf("str->top: %p\n", str->top);
    printf("str->top->data: %d\n", str->top->data);
    push(str, 3);
    printf("===============3추가============\n");
    printf("length: %d\n", str->length);
    printf("str->tail: %p\n", str->tail);
    printf("str->top: %p\n", str->top);
    printf("str->top->data: %d\n", str->top->data);
}
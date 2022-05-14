#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
    int data;
    struct stackNode *llink;
    struct stackNode *rlink;
} Node;

typedef struct Header
{
    int length;
    Node *top;
    Node *tail;
} linkedList;

linkedList *createStack()
{
    linkedList *H;
    H = (linkedList *)malloc(sizeof(linkedList));
    H->length = 0;
    H->top = NULL;
    H->tail = NULL;
    printf("�� ���� ���� �Ϸ�\n");
    return H;
}

int isEmpty(linkedList *stack)
{
    // printf("stack->top == NULL: %d\n", stack->top == NULL); // 1 : true, 0 : false
    return (stack->tail == NULL);
}

void push(linkedList *stack, int data)
{
    printf("push ȣ��\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = data;
    printf("data �ְ�\n");
    newNode->rlink = stack->top; // ù ����� rlink = NULL�� ù ��尡 �ƴϸ� top�� ����Ű�� ��带 ����Ŵ
    printf("���ο� ��� ������ ��ũ�� ���� top ��忡 ����\n");
    stack->top = newNode;
    printf("top�� ���ο� ��忡 ����\n");

    if (isEmpty(stack))
    {
        printf("ù ��� push���\n");
        newNode->llink = stack->tail;
        stack->tail = newNode;
    }
    else
    {
        printf("ù ��尡 �ƴ϶��\n");
        newNode->rlink->llink = newNode;
        newNode->llink = NULL;
    }
    stack->length++;
}

int pop(linkedList *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    else
    {
        Node *remove = stack->top;
        int data = remove->data;
        stack->top = remove->rlink;
        // stack�� ���̰� 1�̶�� ���� pop�ϸ� stack�� �����ִ� ��尡 �����Ƿ� �ٷ� data ����
        // stack�� ���̰� 1�� �ƴϸ� remove�� llink�� NULL�� ������ش�.
        if (stack->length != 1)
        {
            stack->top->llink = NULL; // ���� ��带 ����Ű�� ��ũ
            stack->length--;
        }
        free(remove);
        return data;
    }
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
    pop(str);
    printf("===========pop===========\n");
    printf("length: %d\n", str->length);
    printf("isEmpty(str): %d\n", isEmpty(str));
    printf("str->tail: %p\n", str->tail);
    printf("str->top: %p\n", str->top);
    printf("str->top->data: %d\n", str->top->data);
    pop(str);
    printf("===========pop===========\n");
    printf("length: %d\n", str->length);
    printf("isEmpty(str): %d\n", isEmpty(str));
    printf("str->tail: %p\n", str->tail);
    printf("str->top: %p\n", str->top);
    printf("str->top->data: %d\n", str->top->data);
    printf("%d\n", pop(str));
}
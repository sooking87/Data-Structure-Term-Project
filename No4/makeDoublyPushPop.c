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
    printf("빈 스택 생성 완료\n");
    return H;
}

int isEmpty(linkedList *stack)
{
    // printf("stack->top == NULL: %d\n", stack->top == NULL); // 1 : true, 0 : false
    return (stack->tail == NULL);
}

void push(linkedList *stack, int data)
{
    printf("push 호출\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }
    newNode->data = data;
    printf("data 넣고\n");
    newNode->rlink = stack->top; // 첫 노드의 rlink = NULL로 첫 노드가 아니면 top이 가리키던 노드를 가리킴
    printf("새로운 노드 오른쪽 링크를 원래 top 노드에 연결\n");
    stack->top = newNode;
    printf("top을 새로운 노드에 연결\n");

    if (isEmpty(stack))
    {
        printf("첫 노드 push라면\n");
        newNode->llink = stack->tail;
        stack->tail = newNode;
    }
    else
    {
        printf("첫 노드가 아니라면\n");
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
        // stack의 길이가 1이라는 것은 pop하면 stack에 남아있는 노드가 없으므로 바로 data 리턴
        // stack의 길이가 1이 아니면 remove의 llink는 NULL로 만들어준다.
        if (stack->length != 1)
        {
            stack->top->llink = NULL; // 지울 노드를 가리키던 링크
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
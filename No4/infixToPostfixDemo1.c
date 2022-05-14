#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // printf("빈 스택 생성 완료\n");
    return H;
}

int isEmpty(linkedList *stack)
{
    // printf("stack->top == NULL: %d\n", stack->top == NULL); // 1 : true, 0 : false
    return (stack->tail == NULL);
}

void push(linkedList *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }
    newNode->data = data; // data 넣고
    printf("push할 data: %c or %d\n", newNode->data);
    newNode->rlink = stack->top; // 첫 노드의 rlink = NULL로 첫 노드가 아니면 top이 가리키던 노드를 가리킴
    stack->top = newNode;        // top을 새로운 노드에 연결

    if (isEmpty(stack)) // 첫 노드 push라면
    {
        newNode->llink = stack->tail;
        stack->tail = newNode;
    }
    else // 첫 노드가 아니라면
    {
        newNode->rlink->llink = newNode;
        newNode->llink = NULL;
    }
    stack->length++;
    printf("stack->length: %d\n", stack->length);

    // 스택에 들어있는 data를 출력하기 위한 반복문
    Node *ptr = stack->tail;
    int cnt = 0;
    // 이 반복문이 문제 -> 왜? 정상종료 안됨?
    while (ptr->llink != NULL)
    {
        printf("tail에서부터 %d번째 인덱스: %c\n", cnt, ptr->data);
        cnt++;
        ptr = ptr->llink;
        // printf("다음 노드의 data: %c or %d\n", ptr->data);
    }
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
        // stack의 길이가 1이 아니면 remove의 llink는 NULL로 만들어준다.
        if (stack->length != 1)
        {
            stack->top->llink = NULL; // 지울 노드를 가리키던 링크
        }
        // stack의 길이가 1이라는 것은 pop하면 stack에 남아있는 노드가 없으므로 스택 초기화 시키고(NULL) 바로 data 리턴
        else
        {
            stack->top = NULL;
            stack->tail = NULL;
        }
        stack->length--;
        free(remove);
        return data;
    }
}

int peek(linkedList *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    else
    {
        return stack->top->data;
    }
}

// 스택 내 우선순의
int operator(char op)
{
    // printf("operator 함수에서의 op: %c\n", op);
    switch (op)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infix_to_postfix(char exp[], linkedList *str)
{
    int i = 0;
    char ch, opTopElement; // 스택 op의 top 요소
    int len = strlen(exp);
    linkedList *op = createStack();

    for (i = 0; i < len; i++)
    {
        ch = exp[i];
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty(op) && (operator(ch) <= operator(peek(op))))
            {
                push(str, pop(op));
            }
            push(op, ch);
            break;
        case '(':
            push(op, ch);
            break;
        case ')':
            opTopElement = pop(op);
            while (opTopElement != '(')
            {
                push(str, opTopElement);
                opTopElement = pop(op);
            }
            break;
        default:
            push(str, ch);
            break;
        }
    }
    while (!isEmpty(op))
    {
        push(str, pop(op));
    }
}

int main()
{
    printf("I am Sohn Soo Kyoung\n");
    printf("This Project is No_4 :: Expression Stack using Linked List.\n");
    printf("Please Cheer Up ! Until 2022.05.23\n\n");

    char *data;
    data = (char *)malloc(sizeof(char) * 100);
    linkedList *str; // postfix가 들어가있는 스택
    str = createStack();

    printf("계산할 연산식을 입력해주세요.: ");
    gets(data);

    infix_to_postfix(data, str);
    printf("\nPostfix: %s\n", str);
    // 스택에 들어있는 data를 출력하기 위한 반복문
    Node *ptr = str->tail;
    int cnt = 0;
    while (ptr->llink != NULL)
    {
        printf("tail에서부터 %d번째 인덱스: %c\n", cnt, ptr->data);
        cnt++;
        ptr = ptr->llink;
        // printf("다음 노드의 data: %c or %d\n", ptr->data);
    }
}
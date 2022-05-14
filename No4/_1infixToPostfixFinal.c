/* ============================================================================================================================================================================= */
/*
프로젝트명 : Project #4 :: Expression Stack using Linked List.
작성자 : IT공학전공_2116313_손수경
작성일 : 2022-05-07~2022-05-09
사용언어 : C언어
알고리즘 설명 :
참고한 알고리즘 : 수업 시간에 다룬 infix_to_postfix 알고리즘 및 개념, 수업 교재
도움을 준 동료 : 없음
*/
/* ============================================================================================================================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    // printf("push할 data: %c or %d\n", newNode->data, newNode->data);
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
    // printf("stack->length: %d\n", stack->length);
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

int Calculate(linkedList *str)
{
    char ch;
    int num;                // operand를 저장하기 위한 임시 변수
    int operand1, operand2; // 연산자가 나타났을 경우 pop한 두 피연산자를 넣을 임시 변수
    int result;
    linkedList *cal = createStack(); // 후위 표기식을 계산하기 위한 스택
    Node *ptr = str->tail;

    for (int i = 0; i < str->length; i++)
    {
        ch = ptr->data;
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^')
        {
            num = ch - '0'; // int형으로 변환
            push(cal, num);
        }
        else
        {
            operand2 = pop(cal);
            operand1 = pop(cal);
            // printf("operand2: %d, operand1: %d\n", operand2, operand1);
            switch (ch)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = (int)pow(operand1, operand2);
                break;
            }
            push(cal, result);
        }
        ptr = ptr->llink;
    }
    return pop(cal);
}

int main()
{
    printf("I am Sohn Soo Kyoung\n");
    printf("This Project is No_4 :: Expression Stack using Linked List.\n");
    printf("Please Cheer Up ! Until 2022.05.23\n\n");

    char *data; // 입력받은 infix 수식
    data = (char *)malloc(sizeof(char) * 100);
    linkedList *str; // postfix가 들어가있는 스택
    str = createStack();

    printf("계산할 연산식을 입력해주세요.: ");
    gets(data);

    infix_to_postfix(data, str);
    int result = Calculate(str);
    printf("%s = %d\n", data, result);
}
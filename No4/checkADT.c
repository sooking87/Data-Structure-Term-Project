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

/*
int isEmpty
int isFUll
void push
int pop
int peek
int operator
void infix_to_postfix
int Calculate
*/

typedef struct stackNode
{
    int data;
    struct stackNode *next;
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
/* ============================================================================================================================================================================= */
/*
������Ʈ�� : Project #4 :: Expression Stack using Linked List.
�ۼ��� : IT��������_2116313_�ռ���
�ۼ��� : 2022-05-07~2022-05-09
����� : C���
�˰��� ���� :
�ֿ� ���� / �迭 ����
    - char *data : �Է¹��� infix ����
    - linkedList* str : postfix�� ���� ����
    - linkedList* op : infix_to_postfix �������� �����ڸ� �ӽ÷� �־� ���� ����
    - linkedList* cal : ���� ǥ����� �����ϴ� �������� ���̴� ����
����Ʈ ���� ����
 -> �ܼ� ���� ���� ����Ʈ ����
    ��� ��� ���� : length, top, tail�� �����Ǿ� �ֽ��ϴ�.
        -   ����Ʈ ���� : ���α׷� �ۼ� �߿� ���ÿ� ��尡 ���� ������ ���ؼ� ����, ������ ��带 ���� ���������� �ľ��� �� �ֽ��ϴ�. ���� ���� ǥ������� length��ŭ �ݺ����� �����ϸ鼭 ����մϴ�.
        -   top : ������ top ��带 ����Ű�� �������Դϴ�.
        -   tail : ������ ù ��带 ����Ű�� �����ͷμ�, ���� ǥ����� ����ϴ� �������� ������ ù ������ �����ϱ� ���ؼ� �־����ϴ�. (������ ��带 ���ϱ� ���� �ݺ����� ������ ���� �ʾƵ� �˴ϴ�.)
    �ܼ� ���� ���� ����Ʈ ���� ����
        ��� ����� ���¿����� Ȯ���� �� �ֵ��� tail���� top���� �̵��ϸ鼭 ����� �����ϰ��� �Ͽ����Ƿ� llink�� �߰��Ͽ� �ܼ� ���� ���� ����Ʈ�� ���ؼ� ������ ����� �Ͽ����ϴ�.
�Լ� ����
    -   linkedList *createStack() : ���ο� ������ ������ܰ� ���ÿ� �ش� ��带 �ʱ�ȭ ���� �ݴϴ�.
    -   int isEmpty(int *top) : ������ ������� ������� �������� �Ǻ����ݴϴ�.
    -   void push(linkedList *stack, int data) : stack�� data�� �־��ݴϴ�.
    -   int pop(linkedList *stack) : stack�� top �κ��� �����մϴ�. ������ free()�� ���ؼ� ���� �޸� �Ҵ��� ���� ���ѹ����� �ٸ� ���ÿ��� ���� ���� ����� �� �����Ƿ� ���Ḹ ���� ������ pop()�� ��������ϴ�.
    -   int peek(linkedList *stack) : stack�� top�� �ִ� ���Ҹ� �����մϴ�. (���� ���� ���� �� �κп� �ִ� ���Ҹ� Ȯ���մϴ�.
    -   int operator(char op) : op�� ���� ���� �� �켱������ �����մϴ�.
    -   void infix_to_postfix(char exp[], linkedList *str) : ���� ǥ���(�Է� ���� ��)�� exp�� ���� ǥ������� �ٲپ� ���� str�� �־��ݴϴ�.
    -   int Calculate(linkedList *str) : ���� ǥ������� �ٲ� exp�� ������ִ� �Լ��Դϴ�.
��ü���� �Լ� ���� ����
    -  �Է¹��� ���� ǥ����� ���� ǥ������� �ٲپ� �ݴϴ�. (infix_to_postfix())
    -  ���� ǥ����� ������ Calculate()�� ����Ͽ��� ����մϴ�.

������ �˰��� : ���� �ð��� �ٷ� infix_to_postfix �˰��� �� ����, ���� ����
������ �� ���� : ����
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
    // printf("�� ���� ���� �Ϸ�\n");
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
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = data; // data �ְ�
    // printf("push�� data: %c or %d\n", newNode->data, newNode->data);
    newNode->rlink = stack->top; // ù ����� rlink = NULL�� ù ��尡 �ƴϸ� top�� ����Ű�� ��带 ����Ŵ
    stack->top = newNode;        // top�� ���ο� ��忡 ����

    if (isEmpty(stack)) // ù ��� push���
    {
        newNode->llink = stack->tail;
        stack->tail = newNode;
    }
    else // ù ��尡 �ƴ϶��
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
        // stack�� ���̰� 1�� �ƴϸ� remove�� llink�� NULL�� ������ش�.
        if (stack->length != 1)
        {
            stack->top->llink = NULL; // ���� ��带 ����Ű�� ��ũ
        }
        // stack�� ���̰� 1�̶�� ���� pop�ϸ� stack�� �����ִ� ��尡 �����Ƿ� ���� �ʱ�ȭ ��Ű��(NULL) �ٷ� data ����
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

// ���� �� �켱����
int operator(char op)
{
    // printf("operator �Լ������� op: %c\n", op);
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
    char ch, opTopElement; // ���� op�� top ���
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
    int num;                // operand�� �����ϱ� ���� �ӽ� ����
    int operand1, operand2; // �����ڰ� ��Ÿ���� ��� pop�� �� �ǿ����ڸ� ���� �ӽ� ����
    int result;
    linkedList *cal = createStack(); // ���� ǥ����� ����ϱ� ���� ����
    Node *ptr = str->tail;

    for (int i = 0; i < str->length; i++)
    {
        ch = ptr->data;
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^')
        {
            num = ch - '0'; // int������ ��ȯ
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

    char *data; // �Է¹��� infix ����
    data = (char *)malloc(sizeof(char) * 100);
    linkedList *str; // postfix�� ���ִ� ����
    str = createStack();

    printf("����� ������� �Է����ּ���.: ");
    gets(data);

    infix_to_postfix(data, str);
    int result = Calculate(str);
    printf("%s = %d\n", data, result);
}

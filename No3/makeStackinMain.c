#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define STACK_SIZE 100

typedef char element; // element�� char Ÿ������ ����
element stack[100];

// �����ϴ� top�� strTop�̳� calTop�̳Ŀ� ���� �ٸ��� �� ��
// -> ok
int isEmpty(int *top)
{
    if (*top == -1) // top�� �ٲ� ������ �ʿ� ����
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
int isFull(int *top)
{
    if (*top >= STACK_SIZE) // top�� �ٲ� ������ �ʿ� ����
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
void push(char stack[], int *top, element item)
{
    // printf("push �Լ����� item: %d\n", item);
    // printf("push ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", top, *top);
    if (isFull(top) == 1)
    {
        printf("Stack is FULL\n");
        exit(1);
    }
    // printf("push ���� &top: %d\n", *top);
    stack[++(*top)] = item;
    // printf("push ���� &top: %d\n", *top);
}

// -> ok
element pop(char stack[], int *top)
{
    // printf("pop ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", top, *top);
    int data;
    if (isEmpty(top) == 1)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    data = stack[*top];
    stack[(*top)--] = '\0';

    // printf("pop ���� &top: %d\n", *top);
    return data;
}

element peek(char stack[], int *top)
{
    // printf("peek *top: %d\n", *top);
    if (isEmpty(top) == 1)
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    else
    {
        return stack[*top];
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

void infix_to_postfix(char exp[], char str[], int *top)
{
    int i = 0;
    int k = 0;
    char ch, top_op;
    int len = strlen(exp);
    char op[] = {'\0'}; // �����ڸ� �ӽ÷� �־���� ����

    // printf("strlen(exp): %d\n", len);

    for (i = 0; i < len; i++)
    {
        // printf("=====%d=====\n", i);
        // printf("infix_to_postfix ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", top, *top);
        ch = exp[i];
        // printf("infix_to_postfix ch : %c\n", ch);

        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            while (!isEmpty(top) && (operator(ch) <= operator(peek(op, top)))) // ������ �켱������ ������ stack�� ch�� ���ߵ� -> ���ÿ� �ִ� �����ڸ� ����, ch�� ����
            {
                str[k++] = pop(op, top);
            }

            push(op, top, ch);
            break;
        case '(':
            push(op, top, ch);
            break;
        case ')':
            top_op = pop(op, top);
            while (top_op != '(')
            {
                str[k++] = top_op;
                top_op = pop(op, top);
            }
            break;
        // ������ ���
        default:
            str[k++] = ch;
            break;
        }
    }
    while (!isEmpty(top))
    {
        // printf("%c", peek(str, top));
        str[k++] = pop(op, top);
        // printf("str �迭 ���\n");
    }
}

int Calculate(char exp[])
{
    char ch;
    int num;
    int operand1, operand2;
    int result;
    int calTop = -1;
    char cal[100] = {'\0'};
    for (int i = 0; i < strlen(exp); i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            num = ch - '0'; // int������ ��ȯ
            push(cal, &calTop, num);
        }
        else
        {
            operand2 = pop(cal, &calTop);
            operand1 = pop(cal, &calTop);
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
            push(cal, &calTop, result);
        }
        // printf("calTop: %d\n", calTop);
    }
    return pop(cal, &calTop);
}

int main()
{
    int strTop = -1;
    char str[100] = {'\0'}; // postifx�� �״�� �� ����

    char *data;
    data = (char *)malloc(sizeof(char) * 100);
    printf("����� : ");
    gets(data);
    // printf("�Լ� ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", &strTop, strTop);

    infix_to_postfix(data, str, &strTop);
    printf("\nPostfix: %s\n", str);
    int result = Calculate(str);
    printf("result: %d\n", result);
}
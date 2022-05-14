/* ========================================================= */
/*
������Ʈ�� : Project #3 :: Expression Stack using Array.
�ۼ��� :
�ۼ��� :
����� :
�˰��� ���� :
������ �˰��� :
������ �� ���� :
*/
/* ========================================================= */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define STACK_SIZE 100

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
void push(char stack[], int *top, int item)
{
    printf("push �Լ����� item: %c or %d\n", item, item);
    printf("push ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", top, *top);
    if (isFull(top) == 1)
    {
        printf("Stack is FULL\n");
        exit(1);
    }
    printf("push ���� &top: %d\n", *top);
    stack[++(*top)] = item;
    printf("push ���� &top: %d\n", *top);
}

// -> ok
int pop(char stack[], int *top)
{
    // printf("pop ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", top, *top);
    int data;
    if (isEmpty(top) == 1)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    data = stack[(*top)--];
    printf("pop �Լ����� item: %c or %d\n", data, data);

    // printf("pop ���� &top: %d\n", *top);
    return data;
}

int peek(char stack[], int *top)
{
    // printf("peek *top: %d\n", *top);
    printf("peek stack[(*top)]: %c or %d\n", stack[(*top)], stack[(*top)]);
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
    char op[100] = {'\0'}; // �����ڸ� �ӽ÷� �־���� ����

    // printf("strlen(exp): %d\n", len);

    for (i = 0; i < len; i++)
    {
        printf("===========%d===========\n", i);
        // printf("infix_to_postfix ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", top, *top);
        ch = exp[i];
        printf("infix_to_postfix ch : %c\n", ch);

        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            while (!isEmpty(top) && (operator(ch) <= operator(peek(op, top)))) // ������ �켱������ ������ stack�� ch�� ���ߵ� -> ���ÿ� �ִ� �����ڸ� ����, ch�� ����
            {
                printf("ù ��° pop\n");
                str[k++] = pop(op, top);
            }

            push(op, top, ch);
            break;
        case '(':
            push(op, top, ch);
            break;
        case ')':
            printf("�� ��° pop -> ��ȣ �ݴ� �Ÿ� ������ pop �ʿ�\n");
            top_op = pop(op, top);
            printf("top_op : %c\n", top_op);
            while (top_op != '(')
            {
                str[k++] = top_op;
                printf("top_op : %c\n", top_op);
                for (int idx = 0; op[idx] != '\0'; idx++)
                {
                    printf("op[%d] : %c\n", idx, op[idx]);
                }
                printf("�� ��° pop\n");
                top_op = pop(op, top);
            }
            break;
        // ������ ���
        default:
            str[k++] = ch;
            break;
        }
        for (int idx = 0; str[idx] != '\0'; idx++) // str�迭�� ����� ������ Ȯ��.
        {
            printf("str[%d] = %c\n", idx, str[idx]);
        }
        for (int idx2 = 0; op[idx2] != '\0'; idx2++)
        {
            printf("op[%d] = %c\n", idx2, op[idx2]);
        }
    }
    while (!isEmpty(top))
    {
        // printf("%c", peek(str, top));
        printf("������ ��° pop\n");
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
    printf("I am Sohn Soo Kyoung\n");
    printf("This Project is No_3 :: Expression Stack using Array.\n");
    printf("Please Cheer Up ! Until 2022.05.23\n\n");

    int strTop = -1;
    char str[100] = {0}; // postifx�� �״�� �� ����

    char *data;
    data = (char *)malloc(sizeof(char) * 100);
    printf("����� ������� �Է����ּ���.: ");
    gets(data);
    // printf("�Լ� ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", &strTop, strTop);

    infix_to_postfix(data, str, &strTop);
    printf("\nPostfix: %s\n", str);
    for (int idx = 0; str[idx] != '\0'; idx++) // str�迭�� ����� ������ Ȯ��.
    {
        printf("str[%d] = %c\n", idx, str[idx]);
    }
    int result = Calculate(str);
    printf("result: %d\n", result);
}
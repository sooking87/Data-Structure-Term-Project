#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define STACK_SIZE 100

// ��� ����
typedef char element;               // element�� int Ÿ������ ����
element stack[STACK_SIZE] = {'\0'}; // stack�� �̹� 100��ŭ ������� ����

void createStack(int *top)
{
    int len = 0;
    *top = -1;
    stack[++(*top)] = len;
    // printf("createHeader ���� &top: %d\n", *top);
}

int isEmpty(int *top)
{
    if (*top <= -1) // ù ��° ���Ҵ� ���̸� �ǹ�
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
int isFull(int *top)
{
    if (*top >= STACK_SIZE) // ù ��° ���Ҵ� �� ���� ������ �ǹ�
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
void push(int *top, element item)
{
    // printf("push�Լ����� item: %d\n", item);
    if (isFull(top) == 1)
    {
        printf("Stack is FULL\n");
        exit(1);
    }
    printf("push ���� &top: %d\n", *top);
    stack[++(*top)] = item;
    stack[0]++;
    printf("push ���� &top: %d\n", *top);
}

// -> ok
element pop(int *top)
{
    int data;
    if (isEmpty(top) == 1)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    data = stack[(*top)--];
    stack[0]--;
    // printf("pop ���� &top: %d\n", *top);
    return data;
}

// -> ok
element peek(int *top)
{
    printf("peek *top: %d\n", *top);
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
    printf("operator �Լ������� op: %c\n", op);
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

    // printf("strlen(exp): %d\n", len);

    for (i = 0; i < len; i++)
    {
        printf("=====%d=====\n", i);
        ch = exp[i];
        printf("infix_to_postfix ch : %c\n", ch);
        printf("operator(peek(%d)): %d\n ->\n", &top, operator(peek(top)));
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            while (!isEmpty(top) && (operator(ch) <= operator(peek(top)))) // ������ �켱������ ������ stack�� ch�� ���ߵ� -> ���ÿ� �ִ� �����ڸ� ����, ch�� ����
            {
                str[k++] = pop(top);
            }

            push(top, ch);
            break;
        case '(':
            push(top, ch);
            break;
        case ')':
            top_op = pop(top);
            while (top_op != '(')
            {
                str[k++] = top_op;
                top_op = pop(top);
            }
            break;
        // ������ ���
        default:
            str[k++] = ch;
            break;
        }
    }
    for (int j = 0; str[j] != '\0'; j++) // str�迭�� ����� ������ Ȯ��.
    {
        printf("str[%d] = %c\n", j, str[j]);
    }
    while (!isEmpty(top))
    {
        printf("%c", peek(top));
        str[k++] = pop(top);
        for (int j = 0; str[j] != '\0'; j++) // str�迭�� ����� ������ Ȯ��.
        {
            printf("str[%d] = %c\n", j, str[j]);
        }
    }
    // *top = 0; // ���� �ʱ�ȭ
}

int Calculate(char exp[], int *top)
{
    char ch;
    int num;
    int operand1, operand2;
    for (int i = 0; i < strlen(exp); i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            num = ch - '0'; // int������ ��ȯ
            push(top, num);
        }
        else
        {
            operand2 = pop(top);
            operand1 = pop(top);
            printf("operand2: %d, operand1: %d\n", operand2, operand1);
            switch (ch)
            {
            case '+':
                push(top, operand2 + operand1);
                break;
            case '-':
                push(top, operand2 - operand1);
                break;
            case '*':
                push(top, operand2 * operand1);
                break;
            case '/':
                push(top, operand2 / operand1);
                break;
            case '^':
                push(top, (int)pow(operand2, operand1));
                break;
            }
        }
        for (i = 0; exp[i] != '\0'; i++) // str�迭�� ����� ������ Ȯ��.
        {
            printf("exp[%d] = %c\n", i, exp[i]);
        }
    }
}
void printAll()
{
    printf("%d���� ���Ұ� �ֽ��ϴ�.\n", stack[0]);

    // i = 0�� ���̸� �ǹ��ϴ� �����̹Ƿ�
    for (int i = 1; i <= stack[0]; i++)
    {
        printf("stack[%d] : %d\n", i, stack[i]);
    }
}

int main()
{
    int top = 0;
    char *data;
    char str[100] = {'\0'}; // �ٲ� postfix���� ������ char��
    data = (char *)malloc(sizeof(char) * 100);
    printf("����� : ");
    gets(data);

    infix_to_postfix(data, str, &top);

    int i = 0;
    printf("\n%s\n", str);
    for (i = 0; str[i] != '\0'; i++) // str�迭�� ����� ������ Ȯ��.
    {
        printf("str[%d] = %c\n", i, str[i]);
    }
    int result = Calculate(str, &top);
}
/* ============================================================================================================================================================================= */
/*
������Ʈ�� : Project #3 :: Expression Stack using Array.
�ۼ��� : IT��������_2116313_�ռ���
�ۼ��� : 2022-05-05~2022-05-06
����� : C���
�˰��� ���� :
    �ֿ� ���� / �迭 ����
        1. char* data : �Է¹��� infix ����
        2.1 int strTopIndex : postfix�� ���ִ� �迭�� top�� ����Ű�� ����
        2.2 char str[100] : postfix�� �� �ִ� ����
        3.1 int opTopIndex, opTopElement : ���� op�� top �ε���, ���
        3.2 char op[100] : infix_to_postfix �������� �����ڸ� �ӽ÷� �־� ���� ����
        4.1 int calTopIndex : ���� cal�� top �ε���
        4.2 char cal[100] : ���� ǥ����� �����ϴ� �������� ���̴� ����
    ���� ǥ��Ŀ��� ���� ǥ������� �ٲٱ�
        1. ���Ŀ��� �ǿ����ڸ� ������ ���� str�� �־��ݴϴ�.
        2. ���Ŀ��� ������(ch)�� ������ ���� �� �켱������ ���ؼ� ���� op�� �־��ݴϴ�. �̶�,
            -	���� ������(ch) �켱���� <= ���� op�� �ִ� ������ �켱������� ������ �켱������ Ŀ�� ������ ���� op���� �����ڸ� ���� str�� �ֽ��ϴ�.
            -	���� ������(ch) �켱���� > ���� op�� �ִ� ������ �켱������� �ٷ� �����ڸ� ���� str�� �ֽ��ϴ�.
            -	������ ��(���� ��� ���ÿ� ���� ���� �켱������ 0���� 4�� �ٲ�Ƿ� �ۼ��� ������ �� �켱������ ���� �����ϴ�. �׷��Ƿ� ������ ���� op�� ������ push ���ݴϴ�.
            -	������ ��)���� ���� �ʿ���� �������̹Ƿ� ���� op �Ǵ� ���� str�� ���� �ʰ� ������ ��(���� ���� ��(pop�� ������)���� ���� op�� �ִ� �����ڸ� ���� str�� �־��ݴϴ�.
    ���� ǥ����� �����ϱ�
        1. ���� ǥ����� ����ִ� ���� str���� �տ������� �ϳ��� ���ڸ� �����ͼ� �� ���ڰ� ��������, ���������� Ȯ���մϴ�.
            -	���࿡ �� ���ڰ� ���ڶ�� ���� cal�� push�մϴ�.
            -	���࿡ �� ���ڰ� �����ڶ�� ���� cal�� �ִ� �ǿ����� 2���� pop �ؼ� �ش� �����ڿ� �°� ����� �� �ٽ� ���� cal�� push ���ݴϴ�.
        2. ���� str�� �ִ� ����� �����ٸ� ���� cal�� �����ִ� ���ڴ� ���� ����̹Ƿ� ������ ���ڸ� ��ȯ���ݴϴ�.

������ �˰��� : ���� �ð��� �ٷ� infix_to_postfix �˰��� �� ����, ���� ����
������ �� ���� : ����
*/
/* ============================================================================================================================================================================= */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define STACK_SIZE 100

// �����ϴ� top�� strTop�̳� calTopIndex�̳Ŀ� ���� �ٸ��� �� ��
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
    // printf("push �Լ����� item: %c or %d\n", item, item);
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
    // printf("pop �Լ����� item: %c or %d\n", data, data);

    // printf("pop ���� &top: %d\n", *top);
    return data;
}

int peek(char stack[], int *top)
{
    // printf("peek *top: %d\n", *top);
    // printf("peek stack[(*top)]: %c or %d\n", stack[(*top)], stack[(*top)]);
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

void infix_to_postfix(char exp[], char str[])
{
    int i = 0;
    int strTopIndex = 0;   // ���� str�� top �ε���
    char ch, opTopElement; // ���� op�� top ���
    int opTopIndex = -1;   // ���� op�� top �ε���
    int len = strlen(exp);
    char op[100] = {'\0'}; // �����ڸ� �ӽ÷� �־���� ����

    // printf("strlen(exp): %d\n", len);

    for (i = 0; i < len; i++)
    {
        // printf("===========%d===========\n", i);
        // printf("infix_to_postfix ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", top, *top);
        ch = exp[i];
        // printf("infix_to_postfix ch : %c\n", ch);

        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty(&opTopIndex) && (operator(ch) <= operator(peek(op, &opTopIndex)))) // ������ �켱������ ������ stack�� ch�� ���ߵ� -> ���ÿ� �ִ� �����ڸ� ����, ch�� ����
            {
                // printf("ù ��° pop\n");
                str[strTopIndex++] = pop(op, &opTopIndex);
            }

            push(op, &opTopIndex, ch);
            break;
        case '(':
            push(op, &opTopIndex, ch);
            break;
        case ')':
            // printf("�� ��° pop -> ��ȣ �ݴ� �Ÿ� ������ pop �ʿ�\n");
            opTopElement = pop(op, &opTopIndex);
            // printf("opTopElement : %c\n", opTopElement);
            while (opTopElement != '(')
            {
                str[strTopIndex++] = opTopElement;
                /*
                printf("opTopElement : %c\n", opTopElement);
                for (int idx = 0; op[idx] != '\0'; idx++)
                {
                    printf("op[%d] : %c\n", idx, op[idx]);
                }
                printf("�� ��° pop\n");
                */
                opTopElement = pop(op, &opTopIndex);
            }
            break;
        // ������ ���
        default:
            str[strTopIndex++] = ch;
            break;
        }
        /*
        for (int idx = 0; str[idx] != '\0'; idx++) // str�迭�� ����� ������ Ȯ��.
        {
            printf("str[%d] = %c\n", idx, str[idx]);
        }
        for (int idx2 = 0; op[idx2] != '\0'; idx2++)
        {
            printf("op[%d] = %c\n", idx2, op[idx2]);
        }
        */
    }
    while (!isEmpty(&opTopIndex))
    {
        // printf("%c", peek(str, top));
        // printf("������ ��° pop\n");
        str[strTopIndex++] = pop(op, &opTopIndex);
        // printf("str �迭 ���\n");
    }
}

int Calculate(char exp[])
{
    char ch;
    int num;                // operand�� �����ϱ� ���� �ӽ� ����
    int operand1, operand2; // �����ڰ� ��Ÿ���� ��� pop�� �� �ǿ����ڸ� ���� �ӽ� ����
    int result;
    int calTopIndex = -1;   // ���� cal�� top �ε���
    char cal[100] = {'\0'}; // ���� ǥ����� ����ϱ� ���� ����
    for (int i = 0; i < strlen(exp); i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^')
        {
            num = ch - '0'; // int������ ��ȯ
            push(cal, &calTopIndex, num);
        }
        else
        {
            operand2 = pop(cal, &calTopIndex);
            operand1 = pop(cal, &calTopIndex);
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
            push(cal, &calTopIndex, result);
        }
        // printf("calTopIndex: %d\n", calTopIndex);
    }
    return pop(cal, &calTopIndex);
}

int main()
{
    printf("I am Sohn Soo Kyoung\n");
    printf("This Project is No_3 :: Expression Stack using Array.\n");
    printf("Please Cheer Up ! Until 2022.05.23\n\n");

    char *data; // �Է� ���� infix�� ���� ����
    data = (char *)malloc(sizeof(char) * 100);

    char str[100] = {0}; // postifx�� �״�� �� ����
    printf("����� ������� �Է����ּ���.: ");
    gets(data);
    // printf("�Լ� ȣ�� �� strTop �ּ�: %p, �ε���: %d\n", &strTop, strTop);

    infix_to_postfix(data, str);
    printf("\nPostfix: %s\n", str);
    /*
    for (int idx = 0; str[idx] != '\0'; idx++) // str�迭�� ����� ������ Ȯ��.
    {
        printf("str[%d] = %c\n", idx, str[idx]);
    }
    */
    int result = Calculate(str);
    printf("%s = %d\n", data, result);
    free(data);
}
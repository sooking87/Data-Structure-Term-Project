#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

// ��� ���� ����
typedef struct
{
    int item;
    struct StackNode *link;
} StackNode;
typedef struct
{
    StackNode *top;
} LinkedStackType;

// ���� �ʱ�ȭ �Լ�
void init(LinkedStackType *s)
{
    s->top = NULL;
}

// ������ ����ִ��� �˻��ϴ� �Լ�
int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}

// ���ÿ� ��带 ������ �Լ�
void push(LinkedStackType *s, int item)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    if (temp == NULL) // �޸� �Ҵ��� ���� �ʾ����� ������ �߻���Ŵ.
    {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        return;
    }
    else // �Ҵ��� ������ ���� ���� ��������ش�.
    {
        temp->item = item;
        temp->link = s->top;
        s->top = temp;
    }
}

// ���ÿ� ������ ���� �����ϰ� �����ϴ� �Լ�
int pop(LinkedStackType *s)
{
    if (is_empty(s)) // ��尡 ������� �����Ű�� �ʴ´�.
    {
        fprintf(stderr, "������ �������.\n");
        exit(1);
    }
    else // ��尡 �����ϸ� �ֻ��� ��带 �ҷ����� ���� �����ϰ� ������.
    {
        StackNode *temp = s->top;
        int item = temp->item;
        s->top = s->top->link;
        free(temp);
        return item;
    }
}

// ���� ������ ���� Ȯ��, �����ϴ� �Լ�
int peek(LinkedStackType *s)
{
    if (is_empty(s)) // ��尡 ������� �����Ű�� �ʴ´�.
    {
        fprintf(stderr, "������ �������.\n");
        exit(1);
    }
    else // �ֻ��� ����� ���� ������
    {
        return s->top->item;
    }
}

// �������� �켱������ ��ȯ�ϴ� �Լ�
int prec(char op)
{
    switch (op) // ������ �켱������ 0,1,2�� ���Ͻ�Ŵ.
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
    }
    return -1;
}

// �Է¹��� ����ǥ��� �迭�� ����ǥ��� �ٲ��ִ� �Լ�. 2��° ���ڿ� ��ȯ�� ���� �����Ѵ�.
void infix_to_postfix(char exp[], char str[])
{
    int i = 0, k = 0;      // i : loop�� ���� ����, k : �迭 ��ġ�� ���� ����
    char ch, top_op;       // ch : �迭���ڰ� ����� �ӽú���, top_op : ���ð��� ����� �ӽú���
    int len = strlen(exp); // �迭�� ���̸� ������ ����
    StackNode *s;

    init(&s); // ���� �ʱ�ȭ
    for (i = 0; i < len; i++)
    {
        ch = exp[i]; // �Է¹��� �迭�� 1ĭ�� ������Ű�鼭 ���ڸ� Ȯ���ϰ�
        switch (ch)  // �Ʒ��� case����� ���ǽ���, Ȥ�� default�� ���� ó����.
        {
        case '+':
        case '-':
        case '*':
        case '/': // ������
            // ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
            {
                str[k++] = pop(&s);
                // printf("%c", pop(&s));
            }
            push(&s, ch);
            break;
        case '(':
            push(&s, ch);
            break;
        case ')':
            top_op = pop(&s); // ���� ��ȣ�� ���� ������ ���
            while (top_op != '(')
            {
                str[k++] = top_op;
                // printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:
            str[k++] = ch;
            //	printf("%c", ch);
            break;
        }
    }
    while (!is_empty(&s))
    {
        str[k++] = pop(&s);
        // printf("%c", pop(&s));
    }
}

// ����ǥ����� ������ �Լ�
int eval(char exp[])
{
    int op1, op2, value, i = 0; // op1,2 : ����� ���ڸ� pop�� ����, value : ����� ���ڸ� push�� ����, i : loop�� ���� ����
    char ch;                    // �迭 ���ڰ� ����� �ӽ� ����
    StackNode *s;

    init(&s); // ���� �ʱ�ȭ
    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            value = ch - '0'; // int������ ��ȯ
            push(&s, value);
        }
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) // �����ڸ� �����Ͽ� �׿� �°� ó����.
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    char *data;                                // �Է¹��� ����ǥ����� ����� char�� �����ͺ���
    char str[100] = {'\0'};                    // �ٲ� ����ǥ����� ������ char�� �迭
    int result;                                // ���갪�� ����� ����
    int i = 0;                                 // loop�� �����
    data = (char *)malloc(sizeof(char) * 100); // �迭�� ũ�� �Ҵ�
    printf("����ǥ������� �ٲ� ����ǥ����� �Է��ϼ���. : ");
    gets(data);

    infix_to_postfix(data, str); // ����ǥ����ȯ�Լ� ȣ��

    printf("\n%s\n", str);
    for (i = 0; str[i] != '\0'; i++) // str�迭�� ����� ������ Ȯ��.
    {
        printf("str[%d] = %c\n", i, str[i]);
    }
    result = eval(str); // ����ǥ��� �����Լ� ȣ��
    printf("\n��� ��� : %d\n", result);

    return 0;
}

// https://gist.github.com/blood72/81a76690b64d3022bc9868c19454dd9f
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define STACK_SIZE 100

// 노드 선언
typedef char element;               // element를 int 타입으로 정의
element stack[STACK_SIZE] = {'\0'}; // stack은 이미 100만큼 만들어져 있음

void createStack(int *top)
{
    int len = 0;
    *top = -1;
    stack[++(*top)] = len;
    // printf("createHeader 이후 &top: %d\n", *top);
}

int isEmpty(int *top)
{
    if (*top <= -1) // 첫 번째 원소는 길이를 의미
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
int isFull(int *top)
{
    if (*top >= STACK_SIZE) // 첫 번째 원소는 총 원소 개수를 의미
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
void push(int *top, element item)
{
    // printf("push함수에서 item: %d\n", item);
    if (isFull(top) == 1)
    {
        printf("Stack is FULL\n");
        exit(1);
    }
    printf("push 이전 &top: %d\n", *top);
    stack[++(*top)] = item;
    stack[0]++;
    printf("push 이후 &top: %d\n", *top);
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
    // printf("pop 이후 &top: %d\n", *top);
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

// 스택 내 우선순의
int operator(char op)
{
    printf("operator 함수에서의 op: %c\n", op);
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
            while (!isEmpty(top) && (operator(ch) <= operator(peek(top)))) // 연산자 우선순위가 작으면 stack에 ch가 들어가야됨 -> 스택에 있는 연산자를 빼고, ch를 삽입
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
        // 숫자인 경우
        default:
            str[k++] = ch;
            break;
        }
    }
    for (int j = 0; str[j] != '\0'; j++) // str배열에 제대로 들어갔는지 확인.
    {
        printf("str[%d] = %c\n", j, str[j]);
    }
    while (!isEmpty(top))
    {
        printf("%c", peek(top));
        str[k++] = pop(top);
        for (int j = 0; str[j] != '\0'; j++) // str배열에 제대로 들어갔는지 확인.
        {
            printf("str[%d] = %c\n", j, str[j]);
        }
    }
    // *top = 0; // 스택 초기화
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
            num = ch - '0'; // int형으로 변환
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
        for (i = 0; exp[i] != '\0'; i++) // str배열에 제대로 들어갔는지 확인.
        {
            printf("exp[%d] = %c\n", i, exp[i]);
        }
    }
}
void printAll()
{
    printf("%d개의 원소가 있습니다.\n", stack[0]);

    // i = 0은 길이를 의미하는 원소이므로
    for (int i = 1; i <= stack[0]; i++)
    {
        printf("stack[%d] : %d\n", i, stack[i]);
    }
}

int main()
{
    int top = 0;
    char *data;
    char str[100] = {'\0'}; // 바뀐 postfixㄹ르 저장할 char형
    data = (char *)malloc(sizeof(char) * 100);
    printf("연산식 : ");
    gets(data);

    infix_to_postfix(data, str, &top);

    int i = 0;
    printf("\n%s\n", str);
    for (i = 0; str[i] != '\0'; i++) // str배열에 제대로 들어갔는지 확인.
    {
        printf("str[%d] = %c\n", i, str[i]);
    }
    int result = Calculate(str, &top);
}
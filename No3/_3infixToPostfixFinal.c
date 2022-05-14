/* ============================================================================================================================================================================= */
/*
프로젝트명 : Project #3 :: Expression Stack using Array.
작성자 : IT공학전공_2116313_손수경
작성일 : 2022-05-05~2022-05-06
사용언어 : C언어
알고리즘 설명 :
    주요 변수 / 배열 설명
        1. char* data : 입력받은 infix 수식
        2.1 int strTopIndex : postfix가 들어가있는 배열의 top을 가리키는 변수
        2.2 char str[100] : postfix가 들어가 있는 스택
        3.1 int opTopIndex, opTopElement : 스택 op의 top 인덱스, 요소
        3.2 char op[100] : infix_to_postfix 과정에서 연산자를 임시로 넣어 놓을 스택
        4.1 int calTopIndex : 스택 cal의 top 인덱스
        4.2 char cal[100] : 후위 표기식을 연산하는 과정에서 쓰이는 스택
    중위 표기식에서 후위 표기식으로 바꾸기
        1. 수식에서 피연산자를 만나면 스택 str에 넣어줍니다.
        2. 수식에서 연산자(ch)를 만나면 스택 내 우선순위를 통해서 스택 op에 넣어줍니다. 이때,
            -	현재 연산자(ch) 우선순위 <= 스택 op에 있는 연산자 우선순위라면 현재의 우선순위가 커질 때까지 스택 op에서 연산자를 빼서 str에 넣습니다.
            -	현재 연산자(ch) 우선순위 > 스택 op에 있는 연산자 우선순위라면 바로 연산자를 스택 str에 넣습니다.
            -	연산자 ‘(‘의 경우 스택에 들어가는 순산 우선순위가 0에서 4로 바뀌므로 작성한 연산자 중 우선순위가 가장 높습니다. 그러므로 무조건 스택 op에 무조건 push 해줍니다.
            -	연산자 ‘)’의 경우는 필요없는 연산자이므로 스택 op 또는 스택 str에 들어가지 않고 연산자 ‘(‘가 나올 때(pop될 때까지)까지 스택 op에 있는 연산자를 스택 str에 넣어줍니다.
    후위 표기식을 연산하기
        1. 후위 표기식이 들어있는 스택 str에서 앞에서부터 하나씩 문자를 꺼내와서 그 문자가 숫자인지, 연산자인지 확인합니다.
            -	만약에 그 문자가 숫자라면 스택 cal에 push합니다.
            -	만약에 그 문자가 연산자라면 스택 cal에 있는 피연산자 2개를 pop 해서 해당 연산자에 맞게 계산한 후 다시 스택 cal에 push 해줍니다.
        2. 스택 str에 있는 계산이 끝났다면 스택 cal에 남아있는 숫자는 최종 결과이므로 마지막 숫자를 반환해줍니다.

참고한 알고리즘 : 수업 시간에 다룬 infix_to_postfix 알고리즘 및 개념, 수업 교재
도움을 준 동료 : 없음
*/
/* ============================================================================================================================================================================= */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define STACK_SIZE 100

// 전달하는 top이 strTop이나 calTopIndex이냐에 따라 다르게 할 것
// -> ok
int isEmpty(int *top)
{
    if (*top == -1) // top이 바뀌어도 수정할 필요 없음
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
int isFull(int *top)
{
    if (*top >= STACK_SIZE) // top이 바뀌어도 수정할 필요 없음
    {
        return 1;
    }
    else
        return 0;
}

// -> ok
void push(char stack[], int *top, int item)
{
    // printf("push 함수에서 item: %c or %d\n", item, item);
    // printf("push 호출 후 strTop 주소: %p, 인덱스: %d\n", top, *top);
    if (isFull(top) == 1)
    {
        printf("Stack is FULL\n");
        exit(1);
    }
    // printf("push 이전 &top: %d\n", *top);
    stack[++(*top)] = item;
    // printf("push 이후 &top: %d\n", *top);
}

// -> ok
int pop(char stack[], int *top)
{
    // printf("pop 호출 후 strTop 주소: %p, 인덱스: %d\n", top, *top);
    int data;
    if (isEmpty(top) == 1)
    {
        printf("Stack is EMPTY\n");
        exit(1);
    }
    data = stack[(*top)--];
    // printf("pop 함수에서 item: %c or %d\n", data, data);

    // printf("pop 이후 &top: %d\n", *top);
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

void infix_to_postfix(char exp[], char str[])
{
    int i = 0;
    int strTopIndex = 0;   // 스택 str의 top 인덱스
    char ch, opTopElement; // 스택 op의 top 요소
    int opTopIndex = -1;   // 스택 op의 top 인덱스
    int len = strlen(exp);
    char op[100] = {'\0'}; // 연산자를 임시로 넣어놓을 스택

    // printf("strlen(exp): %d\n", len);

    for (i = 0; i < len; i++)
    {
        // printf("===========%d===========\n", i);
        // printf("infix_to_postfix 호출 후 strTop 주소: %p, 인덱스: %d\n", top, *top);
        ch = exp[i];
        // printf("infix_to_postfix ch : %c\n", ch);

        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty(&opTopIndex) && (operator(ch) <= operator(peek(op, &opTopIndex)))) // 연산자 우선순위가 작으면 stack에 ch가 들어가야됨 -> 스택에 있는 연산자를 빼고, ch를 삽입
            {
                // printf("첫 번째 pop\n");
                str[strTopIndex++] = pop(op, &opTopIndex);
            }

            push(op, &opTopIndex, ch);
            break;
        case '(':
            push(op, &opTopIndex, ch);
            break;
        case ')':
            // printf("두 번째 pop -> 괄호 닫는 거면 무조건 pop 필요\n");
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
                printf("세 번째 pop\n");
                */
                opTopElement = pop(op, &opTopIndex);
            }
            break;
        // 숫자인 경우
        default:
            str[strTopIndex++] = ch;
            break;
        }
        /*
        for (int idx = 0; str[idx] != '\0'; idx++) // str배열에 제대로 들어갔는지 확인.
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
        // printf("마지막 번째 pop\n");
        str[strTopIndex++] = pop(op, &opTopIndex);
        // printf("str 배열 출력\n");
    }
}

int Calculate(char exp[])
{
    char ch;
    int num;                // operand를 저장하기 위한 임시 변수
    int operand1, operand2; // 연산자가 나타났을 경우 pop한 두 피연산자를 넣을 임시 변수
    int result;
    int calTopIndex = -1;   // 스택 cal의 top 인덱스
    char cal[100] = {'\0'}; // 후위 표기식을 계산하기 위한 스택
    for (int i = 0; i < strlen(exp); i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^')
        {
            num = ch - '0'; // int형으로 변환
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

    char *data; // 입력 받을 infix를 넣을 변수
    data = (char *)malloc(sizeof(char) * 100);

    char str[100] = {0}; // postifx가 그대로 들어가 있음
    printf("계산할 연산식을 입력해주세요.: ");
    gets(data);
    // printf("함수 호출 전 strTop 주소: %p, 인덱스: %d\n", &strTop, strTop);

    infix_to_postfix(data, str);
    printf("\nPostfix: %s\n", str);
    /*
    for (int idx = 0; str[idx] != '\0'; idx++) // str배열에 제대로 들어갔는지 확인.
    {
        printf("str[%d] = %c\n", idx, str[idx]);
    }
    */
    int result = Calculate(str);
    printf("%s = %d\n", data, result);
    free(data);
}
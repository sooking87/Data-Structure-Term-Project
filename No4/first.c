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

typedef struct stackNode
{
    char ch;
    struct stackNode *next;
} node;

typedef struct header
{
    int length;
    node *head;
    node *tail;
} h_linkedList;

h_linkedList *createStack()
{
    h_linkedList *H;
    H = (h_linkedList *)malloc(sizeof(h_linkedList));
    H->length = 0;
    H->head = NULL;
    H->tail = NULL;
    return H;
}
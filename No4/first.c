/* ============================================================================================================================================================================= */
/*
������Ʈ�� : Project #4 :: Expression Stack using Linked List.
�ۼ��� : IT��������_2116313_�ռ���
�ۼ��� : 2022-05-07~2022-05-09
����� : C���
�˰��� ���� :
������ �˰��� : ���� �ð��� �ٷ� infix_to_postfix �˰��� �� ����, ���� ����
������ �� ���� : ����
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
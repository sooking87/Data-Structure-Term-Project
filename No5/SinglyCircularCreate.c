#include <stdio.h>
#include <stdlib.h>

/* 이중 연결 리스트 노드 구조 */
typedef struct doubleListNode
{
    char data[5];
    struct doubleListNode *rlink;
    struct doubleListNode *llink;
} doubleListNode;

typedef struct
{
    int length;
    doubleListNode *head;
} doubleCircularPlus;

doubleCircularPlus *create_doubleCircularPlus()
{
    doubleCircularPlus *H;
    H = (doubleCircularPlus *)malloc(sizeof(doubleCircularPlus));
    H->length = 0;
    H->head = (doubleListNode *)malloc(sizeof(doubleListNode));
    H->head->rlink = H->head;
    H->head->llink = H->head;
    printf("생성 완료\n");
    return H;
}

int main()
{
    doubleCircularPlus *list = create_doubleCircularPlus();
}
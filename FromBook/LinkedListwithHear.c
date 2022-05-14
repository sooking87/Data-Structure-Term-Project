#include <stdio.h>

/* 단순 연결 리스트 노드 구조 */
typedef struct listNode
{
    char data[5];
    struct listNode *link;
} listNode;

/* 헤더 노드 구조 */
typedef struct
{
    int length;
    listNode *head;
    listNode *tail;
} h_linkedList;

h_linkedList *create_h_linkedList()
{
    h_linkedList *H;
    H = (h_linkedList *)malloc(sizeof(h_linkedList));
    H->length = 0;
    H->head = NULL;
    H->tail = NULL;
    return H;
}

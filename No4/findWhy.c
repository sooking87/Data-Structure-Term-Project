#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int data;
    struct listNode *link;
} listNode;

typedef struct
{
    listNode *head;
} linkedList_h;

// ����Ʈ ��ü�� ����Ű�� ���� L ��� �ȿ� head ��� �ֱ�
// ���� ����Ʈ �����
linkedList_h *createLinkedList_h(void)
{
    linkedList_h *L;
    L = (linkedList_h *)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

void addLastNode(linkedList_h *L, int x)
{
    listNode *newNode;
    listNode *p;
    newNode = (listNode *)malloc(sizeof(listNode));
    newNode->data = x;
    newNode->link = NULL;
    if (L->head == NULL)
    {
        L->head = newNode;
        return;
    }
    p = L->head;
    while (p->link != NULL)
    {
        p = p->link;
    }
    // p�� ������ ���
    p->link = newNode;
}

void printList(linkedList_h *L)
{
    listNode *p = L->head;
    if (p == NULL)
    {
        printf("����� ��尡 �����ϴ�.");
    }
    else
    {
        while (p != NULL)
        {
            printf("%d", p->data);
            p = p->link;

            if (p != NULL)
            {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main()
{
    linkedList_h *L;
    L = createLinkedList_h();
    addLastNode(L, 1);
    printList(L);
}
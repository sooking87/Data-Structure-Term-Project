#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *llink;
    struct Node *rlink;
} Node;

typedef struct H
{
    int length;
    Node *crnt;
    Node *head;
} BiDirectionCLL;

void addLast(BiDirectionCLL *bcList, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }

    newNode->data = data;
    bcList->length = 0;
    if (bcList == NULL)
    {
        printf("첫 노드라면\n");
        bcList->head = newNode;
        bcList->crnt = newNode;
        newNode->rlink = newNode;
        newNode->llink = newNode;
        printf("bcList->head->data = %d\n", bcList->head->data);
    }
    else
    {
        newNode->llink = bcList->crnt;
        newNode->rlink = bcList->head;
        bcList->crnt->rlink = newNode;
        bcList->head->llink = newNode;
        bcList->crnt = newNode;
    }
    bcList->length++;
}
int isEmpty(BiDirectionCLL *list)
{
    return (list == NULL);
}

int main()
{
    BiDirectionCLL *bcList = NULL;
    if (bcList == NULL)
    {
        printf("NULL\n");
    }
    int x = isEmpty(bcList);
    printf("%d\n", x);
}
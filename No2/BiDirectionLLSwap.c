#include <stdio.h>
#include <stdlib.h>
#define LENGTH 12

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

BiDirectionCLL *createList()
{
    BiDirectionCLL *H;
    H = (BiDirectionCLL *)malloc(sizeof(BiDirectionCLL));
    // printf("�޸� �Ҵ� �ް�\n");
    H->length = 0;
    // printf("���� �����ϰ�\n");
    H->crnt = (Node *)malloc(sizeof(Node));
    H->head = (Node *)malloc(sizeof(Node));
    H->crnt = NULL;
    H->head = NULL;
    // printf("���� ���� ����Ʈ �����\n");
    // printf("�� ����Ʈ ���� �Ϸ�\n");
    return H;
}

int isEmpty(BiDirectionCLL *bcList)
{
    return (bcList->head == NULL);
}

void addLast(BiDirectionCLL *bcList, int data)
{
    // printf("addLast ����\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }

    newNode->data = data;
    // printf("������ �Ҵ�: newNode->data = %d\n", newNode->data);

    if (isEmpty(bcList))
    {
        // printf("ù �����\n");
        bcList->length = 1;
        // printf("���� ����: bcList->length = %d\n", bcList->length);
        bcList->head = newNode;
        // printf("head�� newNode�� ����: bcList->head->data = %d\n", bcList->head->data);
        bcList->crnt = newNode;
        newNode->rlink = newNode;
        newNode->llink = newNode;
    }
    else
    {
        newNode->llink = bcList->crnt;
        newNode->rlink = bcList->head;
        bcList->crnt->rlink = newNode;
        bcList->head->llink = newNode;
        bcList->crnt = newNode;
        bcList->length++;
        // printf("bcList->crnt->data = %d\n", bcList->crnt->data);               // ���� ���� ����� ���� ��µ� �� -> ok
        // printf("bcList->head->rlink->data = %d\n", bcList->head->rlink->data); // ù ��° ��� ���� ����� ��ȣ ��� ���� -> ok
        // printf("bcList->head->llink->data = %d\n", bcList->head->llink->data); // ���� ���� ��(������ ���)�� �� ���� ���� -> ok
    }
    // printf("bcList->head->data = %d\n", bcList->head->data);
    // printf("addLast ���� ����\n");
}

void swap(int *standard, int *min)
{
    int temp = *standard;
    *standard = *min;
    *min = temp;
}

int main()
{
    BiDirectionCLL *bcList = NULL;
    bcList = createList(); // ��� ��� �����
    int data;
    for (int i = 0; i < 5; i++)
    {
        printf("���� �Է����ּ���: ");
        scanf("%d", &data);
        addLast(bcList, data);
        // ��带 �Է��� ������ ������ bcList�� ���� �� ���� ����� ���� ����Ʈ�ϱ�
        // �Ʒ� 3���� ��°��� �ּ�ó������ �� ��
        printf("�߰��� ����� ���� ��: %d\n", bcList->crnt->llink->data);
        printf("�߰��� ����� ��: %d\n", bcList->crnt->data);
        printf("�߰��� ����� ���� ��: %d\n\n", bcList->crnt->rlink->data);
    }
    bcList->crnt = bcList->crnt->rlink;
    Node *temp = bcList->crnt;
    for (int i = 0; i < 4; i++)
    {
        swap(&(temp->data), &(temp->rlink->data));
        Node *willRemove = bcList->head;
        for (int i = 0; i < 5; i++)
        {
            printf("%d ��° ��� ��: %d\n", (i + 1), willRemove->data);
            willRemove = willRemove->rlink;
        }
        printf("\n");
        temp = temp->rlink;
    }
}
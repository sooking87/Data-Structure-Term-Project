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

void SelectionSort(BiDirectionCLL *bcList)
{
    // ù ��° ������ ����
    Node *ptr = bcList->crnt;
    while (ptr->rlink != bcList->crnt)
    {
        Node *standard = bcList->crnt;       // crnt�� �� ������ ��带 ���ϸ鼭 �ּҰ��� ã�� ��
        Node *compare = bcList->crnt->rlink; // ���ؾߵǴ� ������ ���ϱ� ���� ����
        // standard�� �̵��� compare���� ������ ��ġ����
        ptr = ptr->rlink;
        standard = standard->rlink;
        printf("standard->data = %d\n", standard->data);
        printf("compare->data = %d\n", compare->data); // ���� ������ ����
    }
}
int main()
{
    printf("I am Sohn Soo Kyoung\n");
    printf("This Project is No_2 :: Selection Sort using Bi-directional Circular Linked List.\n");
    printf("Please Cheer Up ! Until 2022.05.23\n\n");

    BiDirectionCLL *bcList = NULL;
    bcList = createList(); // ��� ��� �����

    /* isEmpty() Ȯ��
    int x = isEmpty(bcList);
    printf("%d\n", x);
    */

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

    /*
    // addLast() Ȯ��
    Node *rlinkTest = bcList->crnt;
    printf("rlink ���� Ȯ��\n");
    printf("rlinkTest->rlink: %p\n", rlinkTest->rlink);
    printf("bcList->crnt: %p\n", bcList->crnt);
    while (rlinkTest->rlink != bcList->crnt)
    // for (int i = 0; i < 5; i++)
    {
        printf("%d�� data�� ���� ��� push �Ϸ�\n", rlinkTest->data);
        printf("rlinkTest: %p\n", rlinkTest);
        printf("rlinkTest->rlink: %p\n", rlinkTest->rlink);
        rlinkTest = rlinkTest->rlink;
    }
    printf("rlink ���� Ȯ�� ����\n\n");

    Node *llinkTest = bcList->crnt;
    printf("llink ���� Ȯ��\n");
    while (llinkTest->llink != bcList->crnt)
    // for (int i = 0; i < 5; i++)
    {
        printf("%d�� data�� ���� ��� push �Ϸ�\n", llinkTest->data);
        printf("llinkTest: %p\n", llinkTest);
        printf("llinkTest->llink: %p\n", llinkTest->llink);
        llinkTest = llinkTest->llink;
    }
    printf("llink ���� Ȯ�� ����\n\n");
    */
    bcList->crnt = bcList->crnt->rlink;
    SelectionSort(bcList);
}
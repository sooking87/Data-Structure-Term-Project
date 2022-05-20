#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LENGTH 11

typedef struct data
{
    int num;
    char name[20];
} element;

typedef struct Node
{
    element data;
    struct Node *llink;
    struct Node *rlink;
} Node;

typedef struct Header
{
    int length; // addLast, delete �޼ҵ带 ������ �� ���Ǽ��� ���ؼ� �־����ϴ�.
    Node *crnt; // current�� ���ڷ� ���� ����Ű�� �ִ� ��带 �ǹ��մϴ�.
    Node *head; // ù ��° ��带 ����ŵ�ϴ�.
} DoublyCircularLL;

DoublyCircularLL *createList()
{
    DoublyCircularLL *H;
    H = (DoublyCircularLL *)malloc(sizeof(DoublyCircularLL));
    // printf("�޸� �Ҵ� �ް�\n");
    H->length = 0;
    // printf("���� �����ϰ�\n");
    H->crnt = (Node *)malloc(sizeof(Node));
    H->head = (Node *)malloc(sizeof(Node));
    H->crnt->rlink = H->crnt;
    H->crnt->llink = H->crnt;
    H->head->rlink = H->head;
    H->head->llink = H->head;
    // printf("���� ���� ����Ʈ �����\n");
    // printf("�� ����Ʈ ���� �Ϸ�\n");
    return H;
}

int isEmpty(DoublyCircularLL *list)
{
    return (list->head->rlink == list->head);
}

void addLast(DoublyCircularLL *list, element *item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }

    /* ������ �ֱ� */
    newNode->data.num = item->num;
    strcpy(newNode->data.name, item->name);
    // printf("newNode: %p\n", newNode);

    if (isEmpty(list)) // ù ����� -> ��� ��带 ���� ����Ʈ ��ȯ���� ���ܽ�Ű�� ���ؼ�
    {
        list->head->rlink = newNode;
        list->head->llink = newNode;
        list->crnt->rlink = newNode;
        list->crnt->llink = newNode;
    }

    /* rlink ���� */
    newNode->rlink = list->crnt->rlink; // newNode�� ù ��° ��忡 ������ �������� ����
    list->crnt->rlink = newNode;
    /* llink ���� */
    newNode->llink = list->crnt;
    list->head->llink->llink = newNode; // list->head->llink : ù ��° ��� ->llink��� ���� ù ��° ����� ���� ��尡 newNode��� ��

    list->crnt = newNode;
    printf("list->crnt->llink->data.num = %d\n", list->crnt->llink->data.num);                // ���� ����� ���� ��尡 ���;ߵ�.
    printf("list->head->llink->llink->data.num =  %d\n", list->head->llink->llink->data.num); // �߰��� ����� ��ȣ�� ���;ߵ�
    list->length++;
}

int main()
{
    printf("I am Sohn Soo Kyoung\n");
    printf("This Project is No_6 :: Doubly Circular Linked List for Escaping Island.\n");
    printf("Please Cheer Up ! Until 2022.05.23\n\n");

    char *names[20] = {
        "SohnSooKyoung",
        "Park",
        "Kim",
        "Song",
        "Yee",
        "Choi",
        "Jeong",
        "Alice",
        "Clara",
        "Alex",
        "Mia",
    };

    element *item;
    DoublyCircularLL *pplList = createList();
    for (int i = 1; i <= LENGTH; i++)
    {
        item = (element *)malloc(sizeof(element));
        item->num = i;
        strcpy(item->name, names[i - 1]);
        addLast(pplList, item);
    }

    // push Ȯ��
    /* rlink ���� ��� */
    Node *rlinkTest = pplList->crnt;
    Node *llinkTest = pplList->crnt;
    printf("\nMain\n");
    printf("pplList->crnt: %p\n", pplList->crnt->rlink);
    while (rlinkTest->rlink != pplList->crnt)
    // for (int i = 0; i < LENGTH; i++)
    {
        rlinkTest = rlinkTest->rlink;
        printf("%d. %s ��� push �Ϸ�\n", rlinkTest->data.num, rlinkTest->data.name);
        printf("rlinkTest: %p\n", rlinkTest);
        printf("rlinkTest->rlink: %p\n", rlinkTest->rlink);
    }
    printf("rlink_push Ȯ���� ���� ��� ����\n\n");

    printf("llink_push Ȯ��\n"); // 11->10->9... ��µǾߵ�
    // printf("pplList->head->llink->data.num: %d\n", pplList->head->llink->data.num);
    printf("pplList->crnt->data.num: %d\n", pplList->crnt->data.num);
    while (llinkTest->llink != pplList->crnt)
    // for (int i = 0; i < LENGTH; i++)
    {
        printf("%d. %s ��� push �Ϸ�\n", llinkTest->data.num, llinkTest->data.name);
        printf("llinkTest: %p\n", llinkTest);
        printf("llinkTest->llink: %p\n", llinkTest->llink);
        llinkTest = llinkTest->llink;
    }
    printf("llink_push Ȯ���� ���� ��� ����\n\n");
}
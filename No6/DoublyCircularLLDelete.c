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
    // printf("list->crnt->llink->data.num = %d\n", list->crnt->llink->data.num);                // ���� ����� ���� ��尡 ���;ߵ�.
    // printf("list->head->llink->llink->data.num =  %d\n", list->head->llink->llink->data.num); // �߰��� ����� ��ȣ�� ���;ߵ�
    list->length++;
}

// element *delete (DoublyCircularLL *list)
void *delete (DoublyCircularLL *list)
{
    if (list->length == 0)
    {
        printf("List is EMPTY\n");
        exit(1);
    }

    else
    {
        Node *remove = list->crnt;
        // printf("remove->data.num = %d\n", remove->data.num);
        element *returnData = &(remove->data);
        // printf("returnData->num = %d\n", returnData->num);
        Node *prev = list->crnt->llink;
        // printf("prev->data.num = %d\n", prev->data.num);
        if (remove->data.num == list->head->rlink->data.num)
        {
            list->head->rlink = remove->rlink;
            list->head->llink = remove->rlink;
            // printf("remove->rlink->llink->data.num = %d\n", remove->rlink->llink->data.num);
        }
        list->crnt = remove->rlink;
        remove->llink->rlink = remove->rlink;
        remove->rlink->llink = remove->llink;
        list->length--;
        free(remove);
        return returnData;
    }
}

void moveCrntR(DoublyCircularLL *list, int skipNum)
{
    Node *ptr = list->crnt;
    for (int i = 0; i < skipNum; i++)
    {
        ptr = ptr->rlink;
    }
    list->crnt = ptr;
    delete (list);
}

void moveCrntL(DoublyCircularLL *list, int skipNum)
{
    Node *ptr = list->crnt;
    for (int i = 0; i < skipNum; i++)
    {
        ptr = ptr->llink;
    }
    list->crnt = ptr;
    // printf("������ ��� ��ȣ = %d\n", ptr->data.num);
    delete (list);
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

    /*
    // push Ȯ��
    // * rlink ���� ��� *
    Node *rlinkTest = pplList->crnt;
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
    */
    /*
     // * llink ���� ��� *
     Node *llinkTest = pplList->crnt;
     printf("llink_push Ȯ��\n");
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
     */
    /*
    // delete Ȯ��
    for (int i = 0; i < LENGTH; i++)
    {
        element *deletedNode = delete (pplList);
        printf("%d. %s ��� delete �Ϸ�\n", deletedNode->num, deletedNode->name);
    }
    */
    // ������ 1���Ͷ�� ����
    pplList->crnt = pplList->crnt->rlink;
    srand(time(NULL));
    int skipNum = rand() % 9 + 1;
    // int skipNum = 3;
    printf("skipNum = %d\n", skipNum);

    // *���������� �̵��� ���
    while (pplList->length > 3)
    {
        moveCrntR(pplList, skipNum);
    }

    Node *finalListR = pplList->head->rlink;
    printf("�踦 Ÿ�� ���ε��� Ż���� ���� 3���� ");
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            printf("%d�� %s �� �Դϴ�. ^^\n", finalListR->data.num, finalListR->data.name);
        }
        else
        {
            printf("%d�� %s ��, ", finalListR->data.num, finalListR->data.name);
        }
        finalListR = finalListR->rlink;
    }

    /*
     // *���������� �̵��� ���
     while (pplList->length > 3)
     {
         moveCrntL(pplList, skipNum);
     }

     Node *finalListL = pplList->head->rlink;
     printf("�踦 Ÿ�� ���ε��� Ż���� ���� 3���� ");
     for (int i = 0; i < 3; i++)
     {
         if (i == 2)
         {
             printf("%d�� %s �� �Դϴ�. ^^\n", finalListL->data.num, finalListL->data.name);
         }
         else
         {
             printf("%d�� %s ��, ", finalListL->data.num, finalListL->data.name);
         }
         finalListL = finalListL->rlink;
     }
     */
}
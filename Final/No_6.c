/* ============================================================================================================================================================================= */
/*
������Ʈ�� : Project #6 :: Doubly Circular Linked List for Escaping Island.
�ۼ��� : IT��������_2116313_�ռ���
�ۼ��� : 2022-05-16~2022-05-18, 5/22 �ڵ� ����
����� : C���
�˰��� ���� :
�ֿ� ���� ����
    - element ����ü : ���ڿ� ��� �̸��� �ֱ� ���ؼ� ��������ϴ� element�� ����� data�κп� �ش��մϴ�.
    - Node ����ü : �ϳ��� ����̸� ��� �ȿ��� data�� rllink�� llink�� �����ϰ� �ֽ��ϴ�.
    - DoublyCircularLL ����ü : pplList�� ���� �κ��� �ǹ��ϰ�, ��� ��带 ������ �ֽ��ϴ�.
    ��� ��忡�� length, crnt, head�� �ֽ��ϴ�. length�� ����Ʈ�� ���̸� ������ �ֽ��ϴ�. crnt�� current�� ���ڷ� ���� ����Ű�� �ִ� ��带 ���մϴ�. �߰��� ������ crnt�� �� ĭ�� �ڷ� �̵��ϸ�, ���� ��带 ����Ű�� ���� ���˴ϴ�. head�� ���� ù ��° ��带 ����Ű��, ��� �� ������������ ��µ� �� �ֵ��� �մϴ�.
    - pplList : ����� �����͸� ������ �ִ� ���� ���� ���� ����Ʈ�� ���� �κ��Դϴ�.
    - skipNum : ��Ģ�� ���� Ż������ ���� ����� ���� ���� �����Դϴ�. #include <time.h>���� srand(time(NULL))�� ����ؼ� �Ϻ��� ���� �Լ��� ����� �� �ֵ��� �Ͽ����ϴ�. rand()�� ���� Ư�� ��Ģ�� �־� ����ó�� �������� ��� ��Ģ�� �����������Ƿ� srand()�� ����Ͽ����ϴ�.
����Ʈ ���� ����
    - DoublyCircularLL : ��� ��带 �ǹ��ϸ� ���� ���� ����Ʈ���� ��� ���� ������ ���鸸 ��ȸ�ϵ��� ���α׷��� ®���ϴ�. ��� ��忡�� length, crnt, head�� �����ϰ� ������, length�� ��带 �߰��ϰų�, ������ �� ���� ���������� Ȯ���ϱ� ���ؼ� ��� ��忡 �߰��Ͽ����ϴ�. crnt�� ���� ���� ����Ű�� ��尡 ������ ������� ���ϱ� ���ؼ� ��� ��忡 �߰��Ͽ����ϴ�. head�� ���� ù ��° ��带 ����Ű��, ù ��° ��尡 �������ٸ� �� ��° ��带 ����Ű�� �Ͽ� ��½� ������������ ���ĵǾ� ��µ� �� �ֵ��� �ϱ� ���ؼ� ��� ��忡 �߰��Ͽ����ϴ�.
    - Node : �߰��� element�� ���� ��带 ����Ű�� ������ ������ ������ �ִ� ����ü�Դϴ�.
    - element : �߰��� �������� ��ȣ�� �̸��� ������ �ִ� ����ü�Դϴ�.
    => DoublyCircularLL -> FirstNode(with element) -> SecondNode(with element) -> ��. -> LastNode(with element) -> FirstNode(with element) �̷� ������ ��� ���� ������ ��忡 �������� �ʵ��� �ڵ带 �ۼ��Ͽ����ϴ�.
�Լ� ����
- DoublyCircularLL *createList() : ó�� ���ο� ���� ���� ����Ʈ�� ���� �� ���˴ϴ�. ��� ����� �޸𸮸� �Ҵ� �ް�, ��� ��带 �����ϰ� �ִ� length�� 0����, crnt, head�� NULL�� �ʱ�ȭ �����ִ� ������ �մϴ�.
-  int isEmpty(DoublyCircularLL *list) : ����Ʈ�� ����ִ� ������� �ƴ����� �Ǻ����ݴϴ�. list->head == NULL ������ ���̶�� �� ����Ʈ��� �ǹ̷� 1�� �����ϰ�, �׷��� �ʴٸ� 0�� �����մϴ�.
-   void addLast(DoublyCircularLL *list, element *item) : ������ ��� �ڿ� ���ο� ��带 �߰����ݴϴ�. �׶��� ���� item �����͸� ������ �ֽ��ϴ�.
-   void delete(DoublyCircularLL *list) : list���� list->crnt�� �����ִ� �Լ��Դϴ�.
-   moveCrntR() / moveCrntL() �� pplList->crnt�� �̵����Ѽ� ���� ��带 ����Ű���� �ϴ� �Լ��� �½��ϴ�. ������ �������� ���������� ��½�Ű��, ���������� ��½�Ű��� �Ͽ����Ƿ� �� ���� �и��Ͽ��� ���������� ��½�Ű�� ���ؼ��� moveCrntR()�� ���ؼ� crnt�� �̵���Ű��, ���������� ��½�Ű�� ���ؼ��� moveCrntL()�� ���ؼ� crnt�� �̵���ŵ�ϴ�.
��ü���� �Լ� ���� ����
    -   1). addLast()�� ���ؼ� ����� �����͸� pplList�� �־��ݴϴ�.
    -   2.1). ������ ����� ���ؼ���� pplList�� ���̰� 3�� �Ǳ� ������ moveCrntR()�� ���ؼ� skipNum ��ŭ crnt�� �̵���Ű�鼭 �ش� ��带 �����ݴϴ�.
    -   2.2) ������ ����� ���ؼ���� pplList�� ���̰� 3�� �Ǳ� ������ moveCrntL()�� ���ؼ� skipNum ��ŭ crnt�� �̵���Ű�鼭 �ش� ��带 �����ݴϴ�.
    -   3). 3���� �����͸� ������ݴϴ�.

������ �˰��� : ���� �ð��� �ٷ� ���� ���� ����Ʈ ��� ���� ppt �κ�
������ �� ���� : ����
*/
/* ============================================================================================================================================================================= */

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
    H->crnt = NULL;
    H->head = NULL;
    // printf("���� ���� ����Ʈ �����\n");
    // printf("�� ����Ʈ ���� �Ϸ�\n");
    return H;
}

int isEmpty(DoublyCircularLL *list)
{
    return (list->head == NULL);
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
        list->head = newNode;
        list->crnt = newNode;
        newNode->rlink = newNode;
        newNode->llink = newNode;
    }
    else
    {
        newNode->llink = list->crnt;
        newNode->rlink = list->head; // newNode�� ù ��° ��忡 ������ �������� ����
        list->head->llink = newNode; // list->head : ù ��° ���
        list->crnt->rlink = newNode;
        list->crnt = newNode;
        // printf("list->crnt->llink->data.num = %d\n", list->crnt->llink->data.num);                // ���� ����� ���� ��尡 ���;ߵ�.
        // printf("list->head->llink->llink->data.num =  %d\n", list->head->llink->llink->data.num); // �߰��� ����� ��ȣ�� ���;ߵ�
    }

    list->length++;
}

// element *delete (DoublyCircularLL *list)
void *delete (DoublyCircularLL *list)
{
    if (isEmpty(list))
    {
        printf("List is EMPTY\n");
        exit(1);
    }

    else
    {
        Node *remove = list->crnt;
        // printf("remove->data.num = %d\n", remove->data.num);
        // element *returnData = &(remove->data);
        // printf("returnData->num = %d\n", returnData->num);
        Node *prev = list->crnt->llink;
        // printf("prev->data.num = %d\n", prev->data.num);
        if (remove == list->head)
        {
            list->head = remove->rlink;
            // printf("remove->rlink->llink->data.num = %d\n", remove->rlink->llink->data.num);
        }
        list->crnt = remove->rlink;
        remove->llink->rlink = remove->rlink;
        remove->rlink->llink = remove->llink;
        list->length--;
        free(remove);
        // return returnData;
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
    // while (rlinkTest->rlink != pplList->crnt)
    for (int i = 0; i < LENGTH; i++)
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
    // int skipNum = rand() % 9 + 1;
    int skipNum = 3;
    printf("skipNum = %d\n", skipNum);

    /*
    // *���������� �̵��� ���
    printf("���������� �̵��� ���\n");
    while (pplList->length > 3)
    {
        moveCrntR(pplList, skipNum);
    }

    Node *finalListR = pplList->head;
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
    */

    // *���������� �̵��� ���
    printf("���������� �̵��� ���\n");
    while (pplList->length > 3)
    {
        moveCrntL(pplList, skipNum);
    }

    Node *finalListL = pplList->head;
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
}

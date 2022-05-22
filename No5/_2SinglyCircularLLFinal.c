/* =========================================================================================================================================================================== */
/*
������Ʈ�� : Project #5 :: Singly Circular Linked List for Escaping Island.
�ۼ��� : IT��������_2116313_�ռ���
�ۼ��� : 2022-05-11~2022-05-15, 5/22 �ڵ� ����
����� : C���
�˰��� ���� :
���� ����
    - element ����ü : ���ڿ� ��� �̸��� �ֱ� ���ؼ� ��������ϴ� element�� ����� data�κп� �ش��մϴ�.
    - Node ����ü : �ϳ��� ����̸� ��� �ȿ��� data�� rllink�� �����ϰ� �ֽ��ϴ�.
    - SSinglyCircularLL ����ü : pplList�� ���� �κ��� �ǹ��ϰ�, ��� ��带 ������ �ֽ��ϴ�. ��� ��忡�� length, crnt, head�� �ֽ��ϴ�. length�� ����Ʈ�� ���̸� ������ �ֽ��ϴ�. crnt�� current�� ���ڷ� ���� ����Ű�� �ִ� ��带 ���մϴ�. �߰��� ������ crnt�� �� ĭ�� �ڷ� �̵��ϸ�, ���� ��带 ����Ű�� ���� ���˴ϴ�. head�� ���� ù ��° ��带 ����Ű��, ��½� ������������ ��µ� �� �ֵ��� �մϴ�.
    - pplList : ����� �����͸� ������ �ִ� �ܼ� ���� ���� ����Ʈ�� ���� �κ��Դϴ�.
    - skipNum : ��Ģ�� ���� Ż������ ���� ����� ���� ���� �����Դϴ�. #include <time.h>���� srand(time(NULL))�� ����ؼ� �Ϻ��� ���� �Լ��� ����� �� �ֵ��� �Ͽ����ϴ�. rand()�� ���� Ư�� ��Ģ�� �־� ����ó�� �������� ��� ��Ģ�� �����������Ƿ� srand()�� ����Ͽ����ϴ�.
����Ʈ ���� ����
    - SinglyCircularLL : ��� ��带 �ǹ��ϸ� ���� ���� ����Ʈ���� ��� ���� ������ ���鸸 ��ȸ�ϵ��� ���α׷��� ®���ϴ�. ��� ��忡�� length, crnt, head�� �����ϰ� ������, length�� ��带 �߰��ϰų�, ������ �� ���� ���������� Ȯ���ϱ� ���ؼ� ��� ��忡 �߰��Ͽ����ϴ�. crnt�� ���� ���� ����Ű�� ��尡 ������ ������� ���ϱ� ���ؼ� ��� ��忡 �߰��Ͽ����ϴ�. head�� ���� ù ��° ��带 ����Ű��, ù ��° ��尡 �������ٸ� �� ��° ��带 ����Ű�� �Ͽ� ��½� ������������ ���ĵǾ� ��µ� �� �ֵ��� �ϱ� ���ؼ� ��� ��忡 �߰��Ͽ����ϴ�.
    - Node : �߰��� element�� ���� ��带 ����Ű�� ������ ������ ������ �ִ� ����ü�Դϴ�.
    - element : �߰��� �������� ��ȣ�� �̸��� ������ �ִ� ����ü�Դϴ�.
        => SinglyCircularLL -> FirstNode(with element) -> SecondNode(with element) -> ��. -> LastNode(with element) -> FirstNode(with element) �̷� ������ ��� ���� ������ ��忡 �������� �ʵ��� �ڵ带 �ۼ��Ͽ����ϴ�.
�Լ� ����
    -	SinglyCircularLL *createList() : ó�� ���ο� ���� ���� ����Ʈ�� ���� �� ���˴ϴ�. ��� ����� �޸𸮸� �Ҵ� �ް�, ��� ��带 �����ϰ� �ִ� length�� 0����, crnt, head�� NULL�� �ʱ�ȭ �����ִ� ������ �մϴ�.
    -   int isEmpty(SinglyCircularLL *list) : ����Ʈ�� ����ִ� ������� �ƴ����� �Ǻ����ݴϴ�. list->head == NULL ������ ���̶�� �� ����Ʈ��� �ǹ̷� 1�� �����ϰ�, �׷��� �ʴٸ� 0�� �����մϴ�.
    -	 void addLast(SinglyCircularLL *list, element *item) : ������ ��� �ڿ� ���ο� ��带 �߰����ݴϴ�. �׶��� ���� item �����͸� ������ �ֽ��ϴ�.
    -   void delete(SinglyCircularLL *list) : list���� list->crnt�� �����ִ� �Լ��Դϴ�.
    -	void moveCrnt(SinglyCircularLL *list, int skipNum) : pplList->crnt�� skipNum��ŭ �̵������ִ� �Լ��Դϴ�.
���� ����
    -	1). ��� ��ȣ�� �̸��� pplList�� �־��ݴϴ�. (addLast() ���)
    -	2). pplList�� ���̰� 3�� �Ǳ� ������ moveCrnt()�� ���ؼ� skipNum��ŭ crnt�� �̵���Ű�鼭 �ش� ��带 �����ݴϴ�. (moveCrnt(), delete() ���)
    -	3). 3���� �����͸� ������ݴϴ�.

������ �˰��� : ���� �ð��� �ٷ� �ܼ� ���� ����Ʈ ��� ���� ppt �κ�
������ �� ���� : ����
*/
/* =========================================================================================================================================================================== */

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
    struct Node *rlink;
} Node;

typedef struct Header
{
    int length; // addLast, delete �޼ҵ带 ������ �� ���Ǽ��� ���ؼ� �־����ϴ�.
    Node *crnt; // current�� ���ڷ� ���� ����Ű�� �ִ� ��带 �ǹ��մϴ�.
    Node *head; // ù ��° ��带 ����ŵ�ϴ�.
} SinglyCircularLL;

SinglyCircularLL *createList()
{
    SinglyCircularLL *H;
    H = (SinglyCircularLL *)malloc(sizeof(SinglyCircularLL));
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

// -> ok
int isEmpty(SinglyCircularLL *list)
{
    // printf("isEmpty ȣ��: ��� -> %d\n", list->head == NULL);
    // 1: true, 0: false
    return (list->head == NULL);
}
// -> ok
void addLast(SinglyCircularLL *list, element *item)
{
    // printf("addLastȣ��\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    // printf("newNode�� ���� ������ �ȵǳ�? -> %p\n", newNode);
    //->�װ� �ƴ�
    //  �׷� �� ��ũ�� �ȸ���? -> ����� �߸��߳�?
    if (newNode == NULL)
    {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    /* ������ �ֱ� */
    newNode->data.num = item->num;
    strcpy(newNode->data.name, item->name);
    // printf("newNode: %p\n", newNode);

    if (isEmpty(list)) // ��� ������ ������ �ٲپ��־�� �ϹǷ� ���� ó���� �ʿ�
    {
        // printf("ù �����\n");
        list->head = newNode;
        list->crnt = newNode;
        newNode->rlink = newNode;
    }
    else
    {
        newNode->rlink = list->head; // newNode�� ù ��° ��忡 ����
        list->crnt->rlink = newNode; // �߰��Ǳ� �� ����� �����ʸ�ũ(1�� ���)�� ���ο� ��带 ����
        list->crnt = newNode;        // ����Ű�� ��带 �߰��� ���� �̵�
        // printf("list->head: %p\n", list->head);
        // printf("list->crnt = %p / list->crnt->rlink = %p\n", list->crnt, list->crnt->rlink);
        // printf("�� ���: ��ȣ->%d / �̸�->%s\n", list->crnt->data.num, list->crnt->data.name);
        //  printf("list->length: %d\n\n", list->length);
        //  printf("list->head->rlink->data.num = %d\n", list->head->rlink->data.num);
    }
    list->length++;
    // printf("list->crnt->rlink->data.num = %d\n", list->crnt->rlink->data.num); // ����: All 1��(ù ��° ��带 ����Ű�� �ϰ� �����Ƿ� )
}

// element *delete (SinglyCircularLL *list)
void delete (SinglyCircularLL *list) // �ڵ� �ۼ� ���������� ������ ����� Ȯ���� ���ؼ� element *�� ���������� ��ҽ��ϴ�. ������ �������� ��� ���������� �ʿ䰡 �����Ƿ� void�� �ٲپ����ϴ�.
{
    if (isEmpty(list))
    {
        printf("List is EMPTY\n");
        exit(1);
    }
    else
    {
        Node *remove = list->crnt; // ���� ����Ű�� ��带 ������ ����� ��.
        // remove->data = list->crnt->data;
        // element *returnData = &(remove->data);
        // ���࿡ ù ��° ��尡 ������ ���, ���� ��带 head���� ����
        // printf("remove->data.num = %d\n", remove->data.num);
        // printf("prev->data.num = %d\n", prev->rlink->data.num);
        if (remove == list->head)
        {
            // printf("else���� if�� ����\n");
            list->head = remove->rlink;
            // printf("prev->data.num = %d\n", prev->data.num);
        }
        Node *prev = list->head; // prev�� ���� ����� �� ���
        // printf("list->head->data.num = %d\n", list->head->data.num);
        while (prev->rlink != remove)
        {
            prev = prev->rlink;
        }
        // printf("returnData->num = %d\n", returnData->num);
        // printf("prev->rlink->data.num = %d\n", prev->rlink->data.num); // ���� ����� �����Ϳ��ߵ�.
        list->crnt = remove->rlink; // skipNum�� ��Ģ�� ���߱� ���ؼ� ���� ��带 crnt�� �ٲ�
        prev->rlink = remove->rlink;
        // printf("list->crnt->data.num = %d\n", list->crnt->data.num);
        // printf("cnt = %d\n", cnt);
        list->length--;
        // printf("list->length = %d\n", list->length);
        free(remove);
        // printf("delete �Լ� ���� ����\n");
        // return returnData;
    }
}

void moveCrnt(SinglyCircularLL *list, int skipNum)
{
    Node *ptr = list->crnt;
    for (int i = 0; i < skipNum; i++)
    {
        ptr = ptr->rlink;
    }
    list->crnt = ptr;
    // printf("moveCrnt �Լ�: list->crnt->data.num(remove ���) = %d\n", list->crnt->data.num);
    delete (list);
}

int main()
{
    printf("I am Sohn Soo Kyoung\n");
    printf("This Project is No_5 :: Singly Circular Linked List for Escaping Island.\n");
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
    SinglyCircularLL *pplList = NULL;
    pplList = createList();
    isEmpty(pplList);
    // printf("isEmpty(list) = %d\n", isEmpty(pplList));
    for (int i = 1; i <= LENGTH; i++)
    {
        item = (element *)malloc(sizeof(element));
        item->num = i;
        strcpy(item->name, names[i - 1]);
        addLast(pplList, item);
        // printf("pplList->crnt->data.num = %d\n", pplList->crnt->data.num);
    }
    /*
    // push Ȯ��
    Node *test = pplList->head; // ����: 1 -> 2 -> ... 11
    printf("\nMain\n");
    printf("pplList->head->data: %d\n", pplList->head->data);
    // while (test->rlink != pplList->head)
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%d. %s ��� push �Ϸ�\n", test->data.num, test->data.name);
        printf("test: %p\n", test);
        printf("test->rlink: %p\n", test->rlink);

        test = test->rlink;
    }
    printf("push Ȯ���� ���� ��� ����\n\n");
    */
    /*
    // delete Ȯ��
    pplList->crnt = pplList->crnt->rlink; // crnt�� 1�� ����
    printf("pplList->crnt->data.num : %d\n", pplList->crnt->data.num);
    for (int i = 0; i < LENGTH; i++)
    {
        delete (pplList);
        printf("pplList->crnt->data.num : %d\n", pplList->crnt->data.num);
    }
    */

    // ������ 1���Ͷ�� ����
    pplList->crnt = pplList->crnt->rlink;
    // printf("pplList->crnt = %d\n", pplList->crnt->data.num);

    srand(time(NULL));
    int skipNum = rand() % 9 + 1;
    // int skipNum = 3;
    printf("skipNum = %d\n", skipNum);

    while (pplList->length > 3)
    {
        moveCrnt(pplList, skipNum);
    }

    Node *finalList = pplList->head;
    // printf("%d�� %s �� �Դϴ�. ^^\n", finalList->data.num, finalList->data.name);
    printf("�踦 Ÿ�� ���ε��� Ż���� ���� 3���� ");
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            printf("%d�� %s �� �Դϴ�. ^^\n", finalList->data.num, finalList->data.name);
        }
        else
        {
            printf("%d�� %s ��, ", finalList->data.num, finalList->data.name);
        }
        finalList = finalList->rlink;
    }
}

/* ============================================================================================================================================================================= */
/*
������Ʈ�� : Project #5 :: Singly Circular Linked List for Escaping Island.
�ۼ��� : IT��������_2116313_�ռ���
�ۼ��� : 2022-05-07~2022-05-09
����� : C���
�˰��� ���� :
������ �˰��� : ���� �ð��� �ٷ� �ܼ� ���� ����Ʈ ��� ���� ppt �κ�
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
    struct Node *rlink;
} Node;

typedef struct Header
{
    int length; // push, pop �޼ҵ带 ������ �� ���Ǽ��� ���ؼ� �־����ϴ�.
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
    H->crnt->rlink = H->crnt;
    H->head->rlink = H->head;
    // printf("���� ���� ����Ʈ �����\n");
    // printf("�� ����Ʈ ���� �Ϸ�\n");
    return H;
}

// -> ok
int isEmpty(SinglyCircularLL *list)
{
    // printf("isEmpty ȣ��: ��� -> %d\n", list->crnt->rlink == list->crnt);
    // 1: true, 0: false
    return (list->head->rlink == list->head);
}
// -> ok
void addLast(SinglyCircularLL *list, element *item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    // printf("newNode�� ���� ������ �ȵǳ�? -> %p\n", newNode); -> �װ� �ƴ�
    // �׷� �� ��ũ�� �ȸ���? -> ����� �߸��߳�?
    if (newNode == NULL)
    {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data.num = item->num;
    strcpy(newNode->data.name, item->name);
    // printf("newNode: %p\n", newNode);

    if (isEmpty(list))
    {
        // printf("ù �����\n");
        list->head->rlink = newNode;
        list->crnt->rlink = newNode;
    }
    newNode->rlink = list->crnt->rlink; // ���� �ǵ� : 1�� ���� ����, �ٵ� ��� ��� : �� �κ��� ���� X -> ��?
    list->crnt->rlink = newNode;        // �߰��Ǳ� �� ����� �����ʸ�ũ(1�� ���)�� ���ο� ��带 ����
    list->crnt = newNode;               // ����Ű�� ��带 �߰��� ���� �̵�
    // printf("list->head: %p\n", list->head);
    // printf("list->crnt = %p / list->crnt->rlink = %p\n", list->crnt, list->crnt->rlink);
    list->length++;
    // printf("�� ���: ��ȣ->%d / �̸�->%s\n", list->crnt->data.num, list->crnt->data.name);
    // printf("list->length: %d\n\n", list->length);
    // printf("list->head->rlink->data.num = %d\n", list->head->rlink->data.num);
    // printf("list->crnt->rlink->data.num = %d\n", list->crnt->rlink->data.num); // ����: All 1��(ù ��° ��带 ����Ű�� �ϰ� �����Ƿ� )
}

element *delete (SinglyCircularLL *list)
{
    if (list->length == 0)
    {
        printf("List is EMPTY\n");
        exit(1);
    }
    else
    {
        Node *remove = list->crnt; // ���� ����Ű�� ��带 ������ ����� ��.
        // remove->data = list->crnt->data;
        element *returnData = &(remove->data);
        // ���࿡ ù ��° ��尡 ������ ���, ���� ��带 head���� ����
        printf("remove->data.num = %d\n", remove->data.num);
        // printf("prev->data.num = %d\n", prev->rlink->data.num);
        if (remove->data.num == list->head->rlink->data.num)
        {
            // printf("else���� if�� ����\n");
            list->head->rlink = remove->rlink;
            // printf("prev->data.num = %d\n", prev->data.num);
        }
        Node *prev = list->head; // prev�� ���� ����� �� ���
        // printf("list->head->data.num = %d\n", list->head->rlink->data.num);
        while (prev->rlink->data.num != remove->data.num)
        {
            prev = prev->rlink;
        }
        // printf("returnData->num = %d\n", returnData->num);
        // printf("prev->rlink->data.num = %d\n", prev->rlink->data.num);
        list->crnt = remove->rlink; // skipNum�� ��Ģ�� ���߱� ���ؼ� ���� ��带 crnt�� �ٲ�
        prev->rlink = remove->rlink;
        // printf("list->crnt->data.num = %d\n", list->crnt->data.num);
        // printf("cnt = %d\n", cnt);
        list->length--;
        // printf("list->length = %d\n", list->length);
        free(remove);
        // printf("delete �Լ� ���� ����\n");
        return returnData;
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
    SinglyCircularLL *pplList = createList();
    isEmpty(pplList);
    for (int i = 1; i <= LENGTH; i++)
    {
        item = (element *)malloc(sizeof(element));
        item->num = i;
        strcpy(item->name, names[i - 1]);
        addLast(pplList, item);
    }

    /*
    // push Ȯ��
    Node *test = pplList->crnt; // ����: 11 -> 1 -> 2....
    printf("\nMain\n");
    printf("pplList->crnt: %p\n", pplList->crnt->rlink);
    while (test->rlink != pplList->crnt)
    // for (int i = 0; i < LENGTH; i++)
    {
        test = test->rlink;
        printf("%d. %s ��� push �Ϸ�\n", test->data.num, test->data.name);
        printf("test: %p\n", test);
        printf("test->rlink: %p\n", test->rlink);
    }
    printf("push Ȯ���� ���� ��� ����\n\n");
    */

    /*
    // delete Ȯ��
    // pplList->crnt = pplList->crnt->rlink; // crnt�� 1�� ����
    for (int i = 0; i < LENGTH; i++)
    {
        element *deletedNode = delete (pplList);
        printf("%d. %s ��� delete �Ϸ�\n", deletedNode->num, deletedNode->name);
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

    Node *finalList = pplList->head->rlink;
    printf("%d�� %s �� �Դϴ�. ^^\n", finalList->data.num, finalList->data.name);
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
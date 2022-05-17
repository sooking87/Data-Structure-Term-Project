#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("�� ����Ʈ ���� �Ϸ�\n");
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
        printf("ù �����\n");
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
    // printf("%d. %s ��� push �Ϸ�\n", newNode->data.num, newNode->data.name);
    // printf("list->length: %d\n\n", list->length);
    printf("list->head->rlink->data.num = %d\n", list->head->rlink->data.num);
    printf("list->crnt->rlink->data.num = %d\n", list->crnt->rlink->data.num); // ����: All 1��(ù ��° ��带 ����Ű�� �ϰ� �����Ƿ� )
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
        // printf("remove->data.num = %d\n", remove->data.num);
        // printf("prev->data.num = %d\n", prev->rlink->data.num);
        if (remove->data.num == list->head->rlink->data.num)
        {
            // printf("else���� if�� ����\n");
            list->head = remove->rlink;
            // printf("prev->data.num = %d\n", prev->data.num);
        }
        // printf("returnData->num = %d\n", returnData->num);
        int cnt = 0; // �ݺ����� �� �� ������ Ȯ���ϱ� ���� �ӽ� ����

        // printf("prev->rlink->data.num = %d\n", prev->rlink->data.num);
        list->crnt = remove->rlink;
        // printf("list->crnt->data.num = %d\n", list->crnt->data.num);
        // printf("cnt = %d\n", cnt);
        // printf("delete �Լ� ���� ����\n");
        list->length--;
        // printf("list->length = %d\n", list->length);
        // free(remove); -> ���ο��� ����ؾߵǹǷ� �����ϸ� �ȵ�.
        return returnData;
    }
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

    // delete Ȯ��
    pplList->crnt = pplList->crnt->rlink; // crnt�� 1�� ����
    for (int i = 0; i < LENGTH; i++)
    {
        element *deletedNode = delete (pplList);
        printf("%d. %s ��� delete �Ϸ�\n", deletedNode->num, deletedNode->name);
    }
}
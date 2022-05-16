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

int isEmpty(SinglyCircularLL *list)
{
    printf("isEmpty ȣ��: ��� -> %d\n", list->crnt->rlink == list->crnt);
    // 1: true, 0: false
    return (list->crnt->rlink == list->crnt);
}
void addLast(SinglyCircularLL *list, element *item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data.num = item->num;
    strcpy(newNode->data.name, item->name);
    newNode->rlink = list->head; // head�� ù ��° ����̹Ƿ� ������ ��带 ù ��° ��忡 ����
    printf("list->head: %p\n", list->head);
    printf("�� ���: ��ȣ->%d / �̸�->%s\n", newNode->data.num, newNode->data.name);

    if (isEmpty(list))
    {
        printf("ù �����\n");
        list->head = newNode;
    }
    else
    {
        printf("ù ��尡 �ƴ϶��\n");
        list->crnt->rlink = newNode; // list->crnt�� ���� ���� ���� ������ ��絥 �� ��带 ���ο� ���� ����
    }
    list->crnt->rlink = newNode;
    printf("list->crnt = %p / list->crnt->rlink = %p\n", list->crnt, list->crnt->rlink);
    list->length++;
    printf("%d. %s ��� push �Ϸ�\n", newNode->data.num, newNode->data.name);
    printf("list->length: %d\n\n", list->length);
    // ������ �߰� �� ������ ��ȣ�� 11���� crnt ����
}

element *delete (SinglyCircularLL *list)
{
    if (isEmpty(list))
    {
        printf("List is EMPTY\n");
        exit(1);
    }
    else
    {
        Node *remove = list->crnt; // ���� ����Ű�� ��带 ������ ����� ��.
        element *returnData = &(remove->data);
        Node *prev = list->head;
        remove->data = list->crnt->data;
        printf("prev->num = %d\n", prev->data.num);
        printf("remove->data.num = %d, remove->data.name = %s\n", remove->data.num, remove->data.name);
        /*
        while (prev->rlink != remove)
        {
            printf("prev->data.num = %d\n", prev->data.num);
            prev = prev->rlink;
        }
        */
        printf("delete �Լ� ���� ����\n");
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
    // 11���� �����͸� �ܼ� ���� ���� ����Ʈ�� �߰�
    for (int i = 1; i <= LENGTH; i++)
    {
        item = (element *)malloc(sizeof(element));
        item->num = i;
        strcpy(item->name, names[i - 1]);
        addLast(pplList, item);
    }

    element *temp = delete (pplList);
    printf("num = %d, name = %s\n", temp->num, temp->name);
}
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
    int length; // push, pop 메소드를 정의할 때 편의성을 위해서 넣었습니다.
    Node *crnt; // current의 약자로 현재 가리키고 있는 노드를 의미합니다.
    Node *head; // 첫 번째 노드를 가리킵니다.
} SinglyCircularLL;

SinglyCircularLL *createList()
{
    SinglyCircularLL *H;
    H = (SinglyCircularLL *)malloc(sizeof(SinglyCircularLL));
    // printf("메모리 할당 받고\n");
    H->length = 0;
    // printf("길이 선언하고\n");
    H->crnt = (Node *)malloc(sizeof(Node));
    H->head = (Node *)malloc(sizeof(Node));
    H->crnt->rlink = H->crnt;
    H->head->rlink = H->head;
    // printf("원형 연결 리스트 만들고\n");
    printf("빈 리스트 생성 완료\n");
    return H;
}

int isEmpty(SinglyCircularLL *list)
{
    printf("isEmpty 호출: 결과 -> %d\n", list->crnt->rlink == list->crnt);
    // 1: true, 0: false
    return (list->crnt->rlink == list->crnt);
}
void addLast(SinglyCircularLL *list, element *item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }
    newNode->data.num = item->num;
    strcpy(newNode->data.name, item->name);
    newNode->rlink = list->head; // head는 첫 번째 노드이므로 마지막 노드를 첫 번째 노드에 연결
    printf("list->head: %p\n", list->head);
    printf("들어갈 노드: 번호->%d / 이름->%s\n", newNode->data.num, newNode->data.name);

    if (isEmpty(list))
    {
        printf("첫 노드라면\n");
        list->head = newNode;
    }
    else
    {
        printf("첫 노드가 아니라면\n");
        list->crnt->rlink = newNode; // list->crnt의 다음 노드는 기존 마지막 노든데 그 노드를 새로운 노드로 연결
    }
    list->crnt->rlink = newNode;
    printf("list->crnt = %p / list->crnt->rlink = %p\n", list->crnt, list->crnt->rlink);
    list->length++;
    printf("%d. %s 노드 push 완료\n", newNode->data.num, newNode->data.name);
    printf("list->length: %d\n\n", list->length);
    // 데이터 추가 후 마지막 번호인 11번에 crnt 존재
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
        Node *remove = list->crnt; // 현재 가리키는 노드를 삭제할 노드라고 함.
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
        printf("delete 함수 정상 종료\n");
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
    // 11명의 데이터를 단순 원형 연결 리스트에 추가
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
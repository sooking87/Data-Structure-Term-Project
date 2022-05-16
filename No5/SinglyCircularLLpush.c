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
    // printf("newNode가 새로 생성이 안되나? -> %p\n", newNode); -> 그건 아님
    // 그럼 왜 링크가 안맞지? -> 출력을 잘못했나?
    if (newNode == NULL)
    {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }
    newNode->data.num = item->num;
    strcpy(newNode->data.name, item->name);
    printf("newNode: %p\n", newNode);

    if (isEmpty(list))
    {
        printf("첫 노드라면\n");
        list->head->rlink = newNode;
    }
    newNode->rlink = list->crnt->rlink;
    list->crnt->rlink = newNode;
    list->crnt = newNode;
    printf("list->head: %p\n", list->head);
    printf("list->crnt = %p / list->crnt->rlink = %p\n", list->crnt, list->crnt->rlink);
    list->length++;
    printf("들어간 노드: 번호->%d / 이름->%s\n", list->crnt->data.num, list->crnt->data.name);
    printf("%d. %s 노드 push 완료\n", newNode->data.num, newNode->data.name);
    printf("list->length: %d\n\n", list->length);
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

    // push 확인
    Node *test = pplList->crnt; // 예상: 11 -> 1 -> 2....
    printf("Main\n");
    // while (test->rlink != pplList->crnt)
    for (int i = 0; i < LENGTH; i++)
    {
        test = test->rlink; // 왜 이동이 안되지?
        printf("%d. %s 노드 push 완료\n", test->data.num, test->data.name);
        if (test == pplList->head)
        {
            printf("더미 노드 가리킴\n");
        }
        printf("test->rlink: %p\n", test->rlink);
    }
}
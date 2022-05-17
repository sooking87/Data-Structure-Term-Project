/* ============================================================================================================================================================================= */
/*
프로젝트명 : Project #5 :: Singly Circular Linked List for Escaping Island.
작성자 : IT공학전공_2116313_손수경
작성일 : 2022-05-07~2022-05-09
사용언어 : C언어
알고리즘 설명 :
참고한 알고리즘 : 수업 시간에 다룬 단순 원형 리스트 노드 생성 ppt 부분
도움을 준 동료 : 없음
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
    // printf("빈 리스트 생성 완료\n");
    return H;
}

// -> ok
int isEmpty(SinglyCircularLL *list)
{
    // printf("isEmpty 호출: 결과 -> %d\n", list->crnt->rlink == list->crnt);
    // 1: true, 0: false
    return (list->head->rlink == list->head);
}
// -> ok
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
    // printf("newNode: %p\n", newNode);

    if (isEmpty(list))
    {
        // printf("첫 노드라면\n");
        list->head->rlink = newNode;
        list->crnt->rlink = newNode;
    }
    newNode->rlink = list->crnt->rlink; // 원래 의도 : 1번 노드랑 연결, 근데 출력 결과 : 이 부분이 적용 X -> 왜?
    list->crnt->rlink = newNode;        // 추가되기 전 노드의 오른쪽링크(1번 노드)에 새로운 노드를 연결
    list->crnt = newNode;               // 가리키는 노드를 추가된 노드로 이동
    // printf("list->head: %p\n", list->head);
    // printf("list->crnt = %p / list->crnt->rlink = %p\n", list->crnt, list->crnt->rlink);
    list->length++;
    // printf("들어간 노드: 번호->%d / 이름->%s\n", list->crnt->data.num, list->crnt->data.name);
    // printf("list->length: %d\n\n", list->length);
    // printf("list->head->rlink->data.num = %d\n", list->head->rlink->data.num);
    // printf("list->crnt->rlink->data.num = %d\n", list->crnt->rlink->data.num); // 예상: All 1번(첫 번째 노드를 가리키게 하고 싶으므로 )
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
        Node *remove = list->crnt; // 현재 가리키는 노드를 삭제할 노드라고 함.
        // remove->data = list->crnt->data;
        element *returnData = &(remove->data);
        // 만약에 첫 번째 노드가 지워질 경우, 다음 노드를 head노드로 변경
        printf("remove->data.num = %d\n", remove->data.num);
        // printf("prev->data.num = %d\n", prev->rlink->data.num);
        if (remove->data.num == list->head->rlink->data.num)
        {
            // printf("else문의 if문 들어옴\n");
            list->head->rlink = remove->rlink;
            // printf("prev->data.num = %d\n", prev->data.num);
        }
        Node *prev = list->head; // prev는 지울 노드의 전 노드
        // printf("list->head->data.num = %d\n", list->head->rlink->data.num);
        while (prev->rlink->data.num != remove->data.num)
        {
            prev = prev->rlink;
        }
        // printf("returnData->num = %d\n", returnData->num);
        // printf("prev->rlink->data.num = %d\n", prev->rlink->data.num);
        list->crnt = remove->rlink; // skipNum의 규칙을 맞추기 위해서 지운 노드를 crnt로 바꿈
        prev->rlink = remove->rlink;
        // printf("list->crnt->data.num = %d\n", list->crnt->data.num);
        // printf("cnt = %d\n", cnt);
        list->length--;
        // printf("list->length = %d\n", list->length);
        free(remove);
        // printf("delete 함수 정상 종료\n");
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
    // printf("moveCrnt 함수: list->crnt->data.num(remove 노드) = %d\n", list->crnt->data.num);
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
    // push 확인
    Node *test = pplList->crnt; // 예상: 11 -> 1 -> 2....
    printf("\nMain\n");
    printf("pplList->crnt: %p\n", pplList->crnt->rlink);
    while (test->rlink != pplList->crnt)
    // for (int i = 0; i < LENGTH; i++)
    {
        test = test->rlink;
        printf("%d. %s 노드 push 완료\n", test->data.num, test->data.name);
        printf("test: %p\n", test);
        printf("test->rlink: %p\n", test->rlink);
    }
    printf("push 확인을 위한 출력 종료\n\n");
    */

    /*
    // delete 확인
    // pplList->crnt = pplList->crnt->rlink; // crnt를 1로 맞춤
    for (int i = 0; i < LENGTH; i++)
    {
        element *deletedNode = delete (pplList);
        printf("%d. %s 노드 delete 완료\n", deletedNode->num, deletedNode->name);
    }
    */

    // 시작이 1부터라고 가정
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
    printf("%d번 %s 님 입니다. ^^\n", finalList->data.num, finalList->data.name);
    printf("배를 타고 무인도를 탈출할 최종 3인은 ");
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            printf("%d번 %s 님 입니다. ^^\n", finalList->data.num, finalList->data.name);
        }
        else
        {
            printf("%d번 %s 님, ", finalList->data.num, finalList->data.name);
        }
        finalList = finalList->rlink;
    }
}
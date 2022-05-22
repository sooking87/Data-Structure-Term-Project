/* =========================================================================================================================================================================== */
/*
프로젝트명 : Project #5 :: Singly Circular Linked List for Escaping Island.
작성자 : IT공학전공_2116313_손수경
작성일 : 2022-05-11~2022-05-15
사용언어 : C언어
알고리즘 설명 :
1. 변수 설명
    - crnt : current의 약자로 현재 가리키고 있는 노드를 뜻합니다. 추가될 때마다 crnt는 한 칸씩 뒤로 이동하며, 지울 노드를 가리키는 데에 사용됩니다.
    - head->rlink : 가장 첫 번째 노드를 가리키며, 출력시 오름차순으로 출력될 수 있도록 합니다.
    - skipNum : 규칙에 따라 탈출하지 못할 사람을 고르기 위한 숫자입니다. #include <time.h>에서 srand(time(NULL))을 사용해서 완벽한 랜덤 함수를 출력할 수 있도록 하였습니다. rand()의 경우는 특정 규칙이 있어 랜덤처럼 보이지만 사실 규칙이 정해져있으므로 srand()를 사용하였습니다.
2. 함수 설명
    - SinglyCircularLL *createList() :: 단순 원형 연결 리스트의 초기값을 만들어줍니다.
    - int isEmpty(SinglyCircularLL *list) :: 리스트가 빈리스튼지 아닌지를 판별하여 리턴값이 1이면 true, 0이면 false입니다.
    - void addLast(SinglyCircularLL *list, element *item) :: item을 데이터로 가지고 있는 Node를 list의 마지막 자리에 추가합니다.
    - void delete (SinglyCircularLL *list) :: list에서 crnt가 가리키는 노드를 지웁니다.
    - void moveCrnt(SinglyCircularLL *list, int skipNum) :: skipNum만큼 오른쪽으로 crnt를 이동시킵니다. 이 함수에서 지울 노드를 결정합니다.
3. 진행 과정
    1) 데이터를 연결 리스트에 추가합니다. (addLast() 사용)
    2) 리스트의 길이가 3이 되기 전까지 반복문을 돌리면서 moveCrnt()를 통해서 crnt를 skipNum 만큼 이동시킨 후 delete()를 사용하여 crnt를 삭제합니다.
    3) 리스트의 길이가 3이 되면 리스트의 데이터를 출력해줍니다.
참고한 알고리즘 : 수업 시간에 다룬 단순 원형 리스트 노드 생성 ppt 부분
도움을 준 동료 : 없음
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
    int length; // addLast, delete 메소드를 정의할 때 편의성을 위해서 넣었습니다.
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
    H->crnt = NULL;
    H->head = NULL;
    // printf("원형 연결 리스트 만들고\n");
    // printf("빈 리스트 생성 완료\n");
    return H;
}

// -> ok
int isEmpty(SinglyCircularLL *list)
{
    // printf("isEmpty 호출: 결과 -> %d\n", list->head == NULL);
    // 1: true, 0: false
    return (list->head == NULL);
}
// -> ok
void addLast(SinglyCircularLL *list, element *item)
{
    // printf("addLast호출\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    // printf("newNode가 새로 생성이 안되나? -> %p\n", newNode);
    //->그건 아님
    //  그럼 왜 링크가 안맞지? -> 출력을 잘못했나?
    if (newNode == NULL)
    {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }
    /* 데이터 넣기 */
    newNode->data.num = item->num;
    strcpy(newNode->data.name, item->name);
    // printf("newNode: %p\n", newNode);

    if (isEmpty(list)) // 헤더 노드와의 연결을 바꾸어주어야 하므로 따로 처리가 필요
    {
        // printf("첫 노드라면\n");
        list->head = newNode;
        list->crnt = newNode;
        newNode->rlink = newNode;
    }
    else
    {
        newNode->rlink = list->head; // newNode를 첫 번째 노드에 연결
        list->crnt->rlink = newNode; // 추가되기 전 노드의 오른쪽링크(1번 노드)에 새로운 노드를 연결
        list->crnt = newNode;        // 가리키는 노드를 추가된 노드로 이동
        // printf("list->head: %p\n", list->head);
        // printf("list->crnt = %p / list->crnt->rlink = %p\n", list->crnt, list->crnt->rlink);
        // printf("들어간 노드: 번호->%d / 이름->%s\n", list->crnt->data.num, list->crnt->data.name);
        //  printf("list->length: %d\n\n", list->length);
        //  printf("list->head->rlink->data.num = %d\n", list->head->rlink->data.num);
    }
    list->length++;
    // printf("list->crnt->rlink->data.num = %d\n", list->crnt->rlink->data.num); // 예상: All 1번(첫 번째 노드를 가리키게 하고 싶으므로 )
}

element *delete (SinglyCircularLL *list) // 코드 작성 과정에서는 지워진 노드의 확인을 위해서 element *를 리턴형으로 잡았습니다. 하지만 전반적인 출력 과정에서는 필요가 없으므로 void로 바꾸었습니다.
{
    if (isEmpty(list))
    {
        printf("List is EMPTY\n");
        exit(1);
    }
    else
    {
        Node *remove = list->crnt; // 현재 가리키는 노드를 삭제할 노드라고 함.
        // remove->data = list->crnt->data;
        // element *returnData = &(remove->data);
        // 만약에 첫 번째 노드가 지워질 경우, 다음 노드를 head노드로 변경
        // printf("remove->data.num = %d\n", remove->data.num);
        // printf("prev->data.num = %d\n", prev->rlink->data.num);
        if (remove == list->head)
        {
            // printf("else문의 if문 들어옴\n");
            list->head = remove->rlink;
            // printf("prev->data.num = %d\n", prev->data.num);
        }
        Node *prev = list->head; // prev는 지울 노드의 전 노드
        // printf("list->head->data.num = %d\n", list->head->data.num);
        while (prev->rlink != remove)
        {
            prev = prev->rlink;
        }
        // printf("returnData->num = %d\n", returnData->num);
        // printf("prev->rlink->data.num = %d\n", prev->rlink->data.num); // 지울 노드의 데이터여야됨.
        list->crnt = remove->rlink; // skipNum의 규칙을 맞추기 위해서 지운 노드를 crnt로 바꿈
        prev->rlink = remove->rlink;
        // printf("list->crnt->data.num = %d\n", list->crnt->data.num);
        // printf("cnt = %d\n", cnt);
        list->length--;
        // printf("list->length = %d\n", list->length);
        free(remove);
        // printf("delete 함수 정상 종료\n");
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
    // push 확인
    Node *test = pplList->head; // 예상: 1 -> 2 -> ... 11
    printf("\nMain\n");
    printf("pplList->head->data: %d\n", pplList->head->data);
    // while (test->rlink != pplList->head)
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%d. %s 노드 push 완료\n", test->data.num, test->data.name);
        printf("test: %p\n", test);
        printf("test->rlink: %p\n", test->rlink);

        test = test->rlink;
    }
    printf("push 확인을 위한 출력 종료\n\n");
    */
    /*
    // delete 확인
    pplList->crnt = pplList->crnt->rlink; // crnt를 1로 맞춤
    printf("pplList->crnt->data.num : %d\n", pplList->crnt->data.num);
    for (int i = 0; i < LENGTH; i++)
    {
        delete (pplList);
        printf("pplList->crnt->data.num : %d\n", pplList->crnt->data.num);
    }
    */

    // 시작이 1부터라고 가정
    pplList->crnt = pplList->crnt->rlink;
    // printf("pplList->crnt = %d\n", pplList->crnt->data.num);

    srand(time(NULL));
    // int skipNum = rand() % 9 + 1;
    int skipNum = 3;
    printf("skipNum = %d\n", skipNum);

    while (pplList->length > 3)
    {
        moveCrnt(pplList, skipNum);
    }

    Node *finalList = pplList->head;
    // printf("%d번 %s 님 입니다. ^^\n", finalList->data.num, finalList->data.name);
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
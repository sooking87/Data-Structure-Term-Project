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
    int length; // addLast, delete 메소드를 정의할 때 편의성을 위해서 넣었습니다.
    Node *crnt; // current의 약자로 현재 가리키고 있는 노드를 의미합니다.
    Node *head; // 첫 번째 노드를 가리킵니다.
} DoublyCircularLL;

DoublyCircularLL *createList()
{
    DoublyCircularLL *H;
    H = (DoublyCircularLL *)malloc(sizeof(DoublyCircularLL));
    // printf("메모리 할당 받고\n");
    H->length = 0;
    // printf("길이 선언하고\n");
    H->crnt = (Node *)malloc(sizeof(Node));
    H->head = (Node *)malloc(sizeof(Node));
    H->crnt->rlink = H->crnt;
    H->crnt->llink = H->crnt;
    H->head->rlink = H->head;
    H->head->llink = H->head;
    // printf("원형 연결 리스트 만들고\n");
    // printf("빈 리스트 생성 완료\n");
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
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }

    /* 데이터 넣기 */
    newNode->data.num = item->num;
    strcpy(newNode->data.name, item->name);
    // printf("newNode: %p\n", newNode);

    if (isEmpty(list)) // 첫 노드라면 -> 헤더 노드를 원형 리스트 순환에서 제외시키기 위해서
    {
        list->head->rlink = newNode;
        list->head->llink = newNode;
        list->crnt->rlink = newNode;
        list->crnt->llink = newNode;
    }

    /* rlink 연결 */
    newNode->rlink = list->crnt->rlink; // newNode를 첫 번째 노드에 오른쪽 방향으로 연결
    list->crnt->rlink = newNode;
    /* llink 연결 */
    newNode->llink = list->crnt;
    list->head->llink->llink = newNode; // list->head->llink : 첫 번째 노드 ->llink라는 것은 첫 번째 노드의 왼쪽 노드가 newNode라는 것

    list->crnt = newNode;
    // printf("list->crnt->llink->data.num = %d\n", list->crnt->llink->data.num);                // 현재 노드의 앞쪽 노드가 나와야됨.
    // printf("list->head->llink->llink->data.num =  %d\n", list->head->llink->llink->data.num); // 추가된 노드의 번호가 나와야됨
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
    // printf("삭제될 노드 번호 = %d\n", ptr->data.num);
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
    // push 확인
    // * rlink 기준 출력 *
    Node *rlinkTest = pplList->crnt;
    printf("\nMain\n");
    printf("pplList->crnt: %p\n", pplList->crnt->rlink);
    while (rlinkTest->rlink != pplList->crnt)
    // for (int i = 0; i < LENGTH; i++)
    {
        rlinkTest = rlinkTest->rlink;
        printf("%d. %s 노드 push 완료\n", rlinkTest->data.num, rlinkTest->data.name);
        printf("rlinkTest: %p\n", rlinkTest);
        printf("rlinkTest->rlink: %p\n", rlinkTest->rlink);
    }
    printf("rlink_push 확인을 위한 출력 종료\n\n");
    */
    /*
     // * llink 기준 출력 *
     Node *llinkTest = pplList->crnt;
     printf("llink_push 확인\n");
     // printf("pplList->head->llink->data.num: %d\n", pplList->head->llink->data.num);
     printf("pplList->crnt->data.num: %d\n", pplList->crnt->data.num);
     while (llinkTest->llink != pplList->crnt)
     // for (int i = 0; i < LENGTH; i++)
     {
         printf("%d. %s 노드 push 완료\n", llinkTest->data.num, llinkTest->data.name);
         printf("llinkTest: %p\n", llinkTest);
         printf("llinkTest->llink: %p\n", llinkTest->llink);
         llinkTest = llinkTest->llink;
     }
     printf("llink_push 확인을 위한 출력 종료\n\n");
     */
    /*
    // delete 확인
    for (int i = 0; i < LENGTH; i++)
    {
        element *deletedNode = delete (pplList);
        printf("%d. %s 노드 delete 완료\n", deletedNode->num, deletedNode->name);
    }
    */
    // 시작이 1부터라고 가정
    pplList->crnt = pplList->crnt->rlink;
    srand(time(NULL));
    int skipNum = rand() % 9 + 1;
    // int skipNum = 3;
    printf("skipNum = %d\n", skipNum);

    // *순방향으로 이동한 경우
    while (pplList->length > 3)
    {
        moveCrntR(pplList, skipNum);
    }

    Node *finalListR = pplList->head->rlink;
    printf("배를 타고 무인도를 탈출할 최종 3인은 ");
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            printf("%d번 %s 님 입니다. ^^\n", finalListR->data.num, finalListR->data.name);
        }
        else
        {
            printf("%d번 %s 님, ", finalListR->data.num, finalListR->data.name);
        }
        finalListR = finalListR->rlink;
    }

    /*
     // *역방향으로 이동한 경우
     while (pplList->length > 3)
     {
         moveCrntL(pplList, skipNum);
     }

     Node *finalListL = pplList->head->rlink;
     printf("배를 타고 무인도를 탈출할 최종 3인은 ");
     for (int i = 0; i < 3; i++)
     {
         if (i == 2)
         {
             printf("%d번 %s 님 입니다. ^^\n", finalListL->data.num, finalListL->data.name);
         }
         else
         {
             printf("%d번 %s 님, ", finalListL->data.num, finalListL->data.name);
         }
         finalListL = finalListL->rlink;
     }
     */
}
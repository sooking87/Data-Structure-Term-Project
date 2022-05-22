#include <stdio.h>
#include <stdlib.h>
#define LENGTH 12

typedef struct Node
{
    int data;
    struct Node *llink;
    struct Node *rlink;
} Node;

typedef struct H
{
    int length;
    Node *crnt;
    Node *head;
} BiDirectionCLL;

BiDirectionCLL *createList()
{
    BiDirectionCLL *H;
    H = (BiDirectionCLL *)malloc(sizeof(BiDirectionCLL));
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

int isEmpty(BiDirectionCLL *bcList)
{
    return (bcList->head == NULL);
}

void addLast(BiDirectionCLL *bcList, int data)
{
    // printf("addLast 들어옴\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }

    newNode->data = data;
    // printf("데이터 할당: newNode->data = %d\n", newNode->data);

    if (isEmpty(bcList))
    {
        // printf("첫 노드라면\n");
        bcList->length = 1;
        // printf("길이 설정: bcList->length = %d\n", bcList->length);
        bcList->head = newNode;
        // printf("head를 newNode로 설정: bcList->head->data = %d\n", bcList->head->data);
        bcList->crnt = newNode;
        newNode->rlink = newNode;
        newNode->llink = newNode;
    }
    else
    {
        newNode->llink = bcList->crnt;
        newNode->rlink = bcList->head;
        bcList->crnt->rlink = newNode;
        bcList->head->llink = newNode;
        bcList->crnt = newNode;
        bcList->length++;
        // printf("bcList->crnt->data = %d\n", bcList->crnt->data);               // 현재 넣은 노드의 값이 출력될 것 -> ok
        // printf("bcList->head->rlink->data = %d\n", bcList->head->rlink->data); // 첫 번째 노드 다음 노드의 번호 출력 예상 -> ok
        // printf("bcList->head->llink->data = %d\n", bcList->head->llink->data); // 현재 넣은 값(마지막 노드)가 될 것을 예상 -> ok
    }
    // printf("bcList->head->data = %d\n", bcList->head->data);
    // printf("addLast 정상 종료\n");
}

void swap(int *standard, int *min)
{
    int temp = *standard;
    *standard = *min;
    *min = temp;
}

void SelectionSort(BiDirectionCLL *bcList)
{
    // 첫 번째 노드부터 시작
    Node *ptr = bcList->crnt;
    while (ptr->rlink != bcList->crnt)
    {
        Node *standard = bcList->crnt;       // crnt과 그 이후의 노드를 비교하면서 최소값을 찾을 것
        Node *compare = bcList->crnt->rlink; // 비교해야되는 기준을 정하기 위한 변수
        // standard의 이동이 compare에도 영향을 미치는지
        ptr = ptr->rlink;
        standard = standard->rlink;
        printf("standard->data = %d\n", standard->data);
        printf("compare->data = %d\n", compare->data); // 같을 것으로 예상
    }
}
int main()
{
    printf("I am Sohn Soo Kyoung\n");
    printf("This Project is No_2 :: Selection Sort using Bi-directional Circular Linked List.\n");
    printf("Please Cheer Up ! Until 2022.05.23\n\n");

    BiDirectionCLL *bcList = NULL;
    bcList = createList(); // 헤더 노드 만들기

    /* isEmpty() 확인
    int x = isEmpty(bcList);
    printf("%d\n", x);
    */

    int data;
    for (int i = 0; i < 5; i++)
    {
        printf("값을 입력해주세요: ");
        scanf("%d", &data);
        addLast(bcList, data);
        // 노드를 입력할 때마다 현재의 bcList의 좌측 및 우측 노드의 값을 프린트하기
        // 아래 3개의 출력값은 주석처리하지 말 것
        printf("추가된 노드의 좌측 값: %d\n", bcList->crnt->llink->data);
        printf("추가된 노드의 값: %d\n", bcList->crnt->data);
        printf("추가된 노드의 우측 값: %d\n\n", bcList->crnt->rlink->data);
    }

    /*
    // addLast() 확인
    Node *rlinkTest = bcList->crnt;
    printf("rlink 연결 확인\n");
    printf("rlinkTest->rlink: %p\n", rlinkTest->rlink);
    printf("bcList->crnt: %p\n", bcList->crnt);
    while (rlinkTest->rlink != bcList->crnt)
    // for (int i = 0; i < 5; i++)
    {
        printf("%d을 data로 가진 노드 push 완료\n", rlinkTest->data);
        printf("rlinkTest: %p\n", rlinkTest);
        printf("rlinkTest->rlink: %p\n", rlinkTest->rlink);
        rlinkTest = rlinkTest->rlink;
    }
    printf("rlink 연결 확인 종료\n\n");

    Node *llinkTest = bcList->crnt;
    printf("llink 연결 확인\n");
    while (llinkTest->llink != bcList->crnt)
    // for (int i = 0; i < 5; i++)
    {
        printf("%d을 data로 가진 노드 push 완료\n", llinkTest->data);
        printf("llinkTest: %p\n", llinkTest);
        printf("llinkTest->llink: %p\n", llinkTest->llink);
        llinkTest = llinkTest->llink;
    }
    printf("llink 연결 확인 종료\n\n");
    */
    bcList->crnt = bcList->crnt->rlink;
    SelectionSort(bcList);
}
/* =========================================================================================================================================================================== */
/*
프로젝트명 : Project #1 :: Selection Sort using Array.
작성자 : IT공학전공_2116313_손수경
작성일 : 2022-05-20~2022-05-21
사용언어 : C언어
알고리즘 설명 :
주요 변수 설명
    -   Node 구조체 : 노드를 구성하고 있으며 구조체는 data, llink, rlink로 구성되어 있어 이중 연결 리스트를 만들기 위한 노드를 만들었습니다
    -   BiDirectionCLL 구조체 : 헤더 노드를 위한 값들이 들어가 있으며 연결 리스트의 길이를 나타내는 length와 현재 가리키는 노드를 나타내는 crnt, 첫 노드를 가리키는 head로 구성되어 있습니다. 따라서 H->length는 연결 리스트의 길이로 사용하였고, H->crnt는 현재 가리키는 노드, H->head는 첫 번째 노드를 가리킵니다.
    -   bcList : 문제에서 요구하는 이중 원형 연결 리스트의 시작 부분입니다.
리스트 구성 과정
    이 연결 리스트는 이중 원형 연결 리스트로, 노드에 llink와 rlink를 넣어 앞쪽 노드와 뒤쪽 노드를 연결하도록 코드를 짰습니다. 처음에는 bcList가 NULL값이지만 createList()를 통해서 헤더 노드가 있는 빈 리스트를 만들어 줍니다. 그 후, 데이터를 맨 뒤로 추가하여 입력받은 그대로 bcList를 만들어줍니다.(정렬 전 bcList)
함수 설명
    -   BiDirectionCLL *createList() : 헤더 노드도 없는 bcList에 헤더 노드를 만들어주고 bcList가 가리키는 노드는 헤더 노드로 하고, 길이를 0으로 초기화하고, head와 crnt가 가리키는 노드는 없으로 NULL로 해줍니다.
    -   int isEmpty(BiDirectionCCL *bcList) : 빈 리스트인지 아닌지를 판별합니다. 1이면 빈 리스트이고 0이면 비어 있지 않은 리스트입니다.
    -   void addLast(BiDirectionCCL *bcList) : 입력 받은 data를 제일 마지막 노드로 연결시켜주는 함수입니다. 첫 노드라면 bcList->head와 bcList->crnt를 모두 첫 노드에 연결시키고, 원형 이중 연결 리스트를 위해서 newNode의 llink와 rlink를 newNode로 연결시킵니다.
    첫 노드가 아니라면 newNode->llink를 추가할 노드 앞쪽노드(bcList->crnt)에 연결시키고 newNode->rlink를 첫 노드(bcList->head)와 연결시킵니다. 그리고 newNode의 앞쪽 노드의 rlink를 newNode에 연결시키고, 첫 노드의 llink를 newNode에 연결시켜서 원형 이중 연결 리스트의 구조를 만들어줍니다.
    -   void swap(int *standard, int *min) : 기준점과 기준점 이후의 data들 중에서의 최소값을 바꾸어주는 함수입니다. 이 함수를 의도한대로 구현하지 못하였습니다. 원래 의도한 바는 한 노드에서 나오거나 가리키는 링크가 4개가 있는데 이 링크 자체를 수정하여서 노드끼리 변경을 해주고 싶었지만 그렇게 된다면 총 8개의 링크를 수정해주어야 합니다. 하지만 그 링크들의 규칙을 찾지 못하였고, 너무 복잡하여 일단 결과는 내기 위해서 “값”만을 바꾸는 식으로 swap() 함수를 진행하였습니다. 하지만 8개의 링크를 수정하되, 어느 위치에서든 규칙이 적용되기 위한 공통점을 찾아내는 것이 너무 복잡하고 어려워서 의도한 대로 swap() 함수를 구현하지는 못하였습니다. 따라서 swap()은 다음과 같이 구현하였습니다.
    -   void SelectionSort(BiDirectionCLL *bcList) : 선택 정렬이 이루어지는 함수입니다. 지금 마찬가지고 2중 반복문을 사용하고 있는데 그 조건을 standard와 compare을 기준으로 하였습니다. compare는 하나씩 오른쪽 노드로 이동하면서 최소값을 찾아야되는 포인터이므로 상관없지만 기준이 되는 부분인 standard의 경우는 안쪽 반복문이 수행되는 동안에서 바뀌면 안되므로 stTemp를 사용하여서 최소값을 찾는데 사용하였습니다. 그리고 isChanged라는 변수를 넣은 이유는 만약 현재의 노드가 최소값이라서 변경될 필요가 없지만, isChanged가 없다면 무조건 현재 노드와 그 다음 노드가 변경될 것 이므로 isChanged를 넣어 이 문제점을 수정해주었습니다. 그래서 isChanged가 0이라면 바뀌었다는 뜻이므로 swap() 해주고, 그렇지 않다면 그냥 standard의 노드를 한 칸 오른쪽으로 이동시켜 줍니다.
전체적인 함수 진행 구조
    -   1). 먼저 scanf 함수를 통해서 12개의 값을 입력받습니다. 입력을 받을 때마다 추가된 데이터를 기준으로 앞쪽 노드, 뒤쪽 노드의 데이터를 출력해줍니다.
    -   2). 선택 정렬을 진행합니다. 이때 SelectionSort() 와 swap()이 사용됩니다.
    -   3). SelectionSort()를 마치고 나서 첫 번째 노드 기준 양방향으로 출력하여 오름 차순으로 정렬됨을 확인하고, 마지막 노드를 기준으로 역방향으로 출력하여 내림 차순으로 정렬됨을 확인합니다.
참고한 알고리즘 : 과제 참고용 - 선택 정렬 pdf
도움을 준 동료 : 없음
*/
/* =========================================================================================================================================================================== */
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
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
        // printf("bcList->crnt->data = %d\n", bcList->crnt->data);               // 현재 넣은 노드의 값이 출력될 것 -> ok
        // printf("bcList->head->rlink->data = %d\n", bcList->head->rlink->data); // 첫 번째 노드 다음 노드의 번호 출력 예상 -> ok
        // printf("bcList->head->llink->data = %d\n", bcList->head->llink->data); // 현재 넣은 값(마지막 노드)가 될 것을 예상 -> ok
    }
    // printf("bcList->head->data = %d\n", bcList->head->data);
    // printf("addLast 정상 종료\n");
    bcList->length++;
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
    Node *standard = bcList->head; // crnt과 그 이후의 노드를 비교하면서 최소값을 찾을 것
    while (standard->rlink != bcList->head)
    {
        Node *stTemp = standard;
        Node *compare = standard->rlink; // 최소값을 구하기 위한 변수
        int isChanged = 1;
        // printf("standard->data: %d\n", standard->data);
        // printf("compare->data 시작 지점: %d\n", compare->data);
        while (compare != bcList->head)
        {
            // printf("비교해야되는 값: %d\n", min->data);
            if (stTemp->data > compare->data)
            {
                isChanged = 0;
                stTemp = compare;
            }
            // printf("기준이 되는 값: %d\n", standard->data);
            //  printf("standard 이후 제일 작은 값: %d\n", param->data);
            compare = compare->rlink;
            // printf("안에 while문 종료조건: %d\n", compare != bcList->head);
            // printf("isChanged = %d\n", isChanged);
        }
        // printf("\n최종 결과\n");
        // printf("기준이 되는 값: %d\n", standard->data);
        // printf("최종->standard 이후 제일 작은 값: %d\n", stTemp->data); // 최소값인 compare이 오른쪽으로 이동하고 반복문이 끝났으므로 왼쪽값의 data가 최솟값
        if (isChanged == 0)
        {
            swap(&(standard->data), &(stTemp->data));
            Node *afterChanged = bcList->head;
            for (int i = 0; i < LENGTH; i++)
            {
                printf("%d 번째 노드 값: %d\n", (i + 1), afterChanged->data);
                afterChanged = afterChanged->rlink;
            }
            printf("\n");
        }
        standard = standard->rlink;

        /*
        // swap이 발생했는지 확인
        Node *willRemove = bcList->head;
        for (int i = 0; i < 5; i++)
        {
            printf("%d 번째 노드 값: %d\n", (i + 1), willRemove->data);
            willRemove = willRemove->rlink;
        }
        printf("\n");
        */
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
    for (int i = 0; i < LENGTH; i++)
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
    // printf("첫 번째 노드값: %d\n", bcList->head->data);

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
    // printf("bcList->length = %d\n", bcList->length);
    printf("정렬 이후\n오름차순 ver.\n");
    Node *p = bcList->head;
    int cnt = 1;
    int sum = 0;
    double avg;
    while (p->rlink != bcList->head)
    {
        printf("%d 번째 노드: %d\n", cnt, p->data);
        sum += p->data;
        p = p->rlink;
        cnt++;
    }
    printf("%d 번째 노드: %d\n", cnt, p->data);
    sum += p->data;
    avg = sum / (double)LENGTH;
    printf("bcList 내의 %d개의 원소 값의 합: %d\n", LENGTH, sum);
    printf("bcList 내의 %d개의 원소 값의 평균: %f\n", LENGTH, avg);

    printf("\n정렬 이후\n내림차순 ver.\n");
    Node *p2 = bcList->head->llink;
    int cnt2 = 1;
    int sum2 = 0;
    double avg2;
    while (p2->llink != bcList->head->llink)
    {
        printf("%d 번째 노드: %d\n", cnt2, p2->data);
        sum2 += p2->data;
        p2 = p2->llink;
        cnt2++;
    }
    printf("%d 번째 노드: %d\n", cnt2, p2->data);
    sum2 += p2->data;
    avg2 = sum2 / (double)LENGTH;
    printf("bcList 내의 %d개의 원소 값의 합: %d\n", LENGTH, sum2);
    printf("bcList 내의 %d개의 원소 값의 평균: %f\n", LENGTH, avg2);
}

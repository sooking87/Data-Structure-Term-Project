/* =========================================================================================================================================================================== */
/*
������Ʈ�� : Project #1 :: Selection Sort using Array.
�ۼ��� : IT��������_2116313_�ռ���
�ۼ��� : 2022-05-20~2022-05-21
����� : C���
�˰��� ���� :
�ֿ� ���� ����
    -   Node ����ü : ��带 �����ϰ� ������ ����ü�� data, llink, rlink�� �����Ǿ� �־� ���� ���� ����Ʈ�� ����� ���� ��带 ��������ϴ�
    -   BiDirectionCLL ����ü : ��� ��带 ���� ������ �� ������ ���� ����Ʈ�� ���̸� ��Ÿ���� length�� ���� ����Ű�� ��带 ��Ÿ���� crnt, ù ��带 ����Ű�� head�� �����Ǿ� �ֽ��ϴ�. ���� H->length�� ���� ����Ʈ�� ���̷� ����Ͽ���, H->crnt�� ���� ����Ű�� ���, H->head�� ù ��° ��带 ����ŵ�ϴ�.
    -   bcList : �������� �䱸�ϴ� ���� ���� ���� ����Ʈ�� ���� �κ��Դϴ�.
����Ʈ ���� ����
    �� ���� ����Ʈ�� ���� ���� ���� ����Ʈ��, ��忡 llink�� rlink�� �־� ���� ���� ���� ��带 �����ϵ��� �ڵ带 ®���ϴ�. ó������ bcList�� NULL�������� createList()�� ���ؼ� ��� ��尡 �ִ� �� ����Ʈ�� ����� �ݴϴ�. �� ��, �����͸� �� �ڷ� �߰��Ͽ� �Է¹��� �״�� bcList�� ������ݴϴ�.(���� �� bcList)
�Լ� ����
    -   BiDirectionCLL *createList() : ��� ��嵵 ���� bcList�� ��� ��带 ������ְ� bcList�� ����Ű�� ���� ��� ���� �ϰ�, ���̸� 0���� �ʱ�ȭ�ϰ�, head�� crnt�� ����Ű�� ���� ������ NULL�� ���ݴϴ�.
    -   int isEmpty(BiDirectionCCL *bcList) : �� ����Ʈ���� �ƴ����� �Ǻ��մϴ�. 1�̸� �� ����Ʈ�̰� 0�̸� ��� ���� ���� ����Ʈ�Դϴ�.
    -   void addLast(BiDirectionCCL *bcList) : �Է� ���� data�� ���� ������ ���� ��������ִ� �Լ��Դϴ�. ù ����� bcList->head�� bcList->crnt�� ��� ù ��忡 �����Ű��, ���� ���� ���� ����Ʈ�� ���ؼ� newNode�� llink�� rlink�� newNode�� �����ŵ�ϴ�.
    ù ��尡 �ƴ϶�� newNode->llink�� �߰��� ��� ���ʳ��(bcList->crnt)�� �����Ű�� newNode->rlink�� ù ���(bcList->head)�� �����ŵ�ϴ�. �׸��� newNode�� ���� ����� rlink�� newNode�� �����Ű��, ù ����� llink�� newNode�� ������Ѽ� ���� ���� ���� ����Ʈ�� ������ ������ݴϴ�.
    -   void swap(int *standard, int *min) : �������� ������ ������ data�� �߿����� �ּҰ��� �ٲپ��ִ� �Լ��Դϴ�. �� �Լ��� �ǵ��Ѵ�� �������� ���Ͽ����ϴ�. ���� �ǵ��� �ٴ� �� ��忡�� �����ų� ����Ű�� ��ũ�� 4���� �ִµ� �� ��ũ ��ü�� �����Ͽ��� ��峢�� ������ ���ְ� �;����� �׷��� �ȴٸ� �� 8���� ��ũ�� �������־�� �մϴ�. ������ �� ��ũ���� ��Ģ�� ã�� ���Ͽ���, �ʹ� �����Ͽ� �ϴ� ����� ���� ���ؼ� ���������� �ٲٴ� ������ swap() �Լ��� �����Ͽ����ϴ�. ������ 8���� ��ũ�� �����ϵ�, ��� ��ġ������ ��Ģ�� ����Ǳ� ���� �������� ã�Ƴ��� ���� �ʹ� �����ϰ� ������� �ǵ��� ��� swap() �Լ��� ���������� ���Ͽ����ϴ�. ���� swap()�� ������ ���� �����Ͽ����ϴ�.
    -   void SelectionSort(BiDirectionCLL *bcList) : ���� ������ �̷������ �Լ��Դϴ�. ���� ���������� 2�� �ݺ����� ����ϰ� �ִµ� �� ������ standard�� compare�� �������� �Ͽ����ϴ�. compare�� �ϳ��� ������ ���� �̵��ϸ鼭 �ּҰ��� ã�ƾߵǴ� �������̹Ƿ� ��������� ������ �Ǵ� �κ��� standard�� ���� ���� �ݺ����� ����Ǵ� ���ȿ��� �ٲ�� �ȵǹǷ� stTemp�� ����Ͽ��� �ּҰ��� ã�µ� ����Ͽ����ϴ�. �׸��� isChanged��� ������ ���� ������ ���� ������ ��尡 �ּҰ��̶� ����� �ʿ䰡 ������, isChanged�� ���ٸ� ������ ���� ���� �� ���� ��尡 ����� �� �̹Ƿ� isChanged�� �־� �� �������� �������־����ϴ�. �׷��� isChanged�� 0�̶�� �ٲ���ٴ� ���̹Ƿ� swap() ���ְ�, �׷��� �ʴٸ� �׳� standard�� ��带 �� ĭ ���������� �̵����� �ݴϴ�.
��ü���� �Լ� ���� ����
    -   1). ���� scanf �Լ��� ���ؼ� 12���� ���� �Է¹޽��ϴ�. �Է��� ���� ������ �߰��� �����͸� �������� ���� ���, ���� ����� �����͸� ������ݴϴ�.
    -   2). ���� ������ �����մϴ�. �̶� SelectionSort() �� swap()�� ���˴ϴ�.
    -   3). SelectionSort()�� ��ġ�� ���� ù ��° ��� ���� ��������� ����Ͽ� ���� �������� ���ĵ��� Ȯ���ϰ�, ������ ��带 �������� ���������� ����Ͽ� ���� �������� ���ĵ��� Ȯ���մϴ�.
������ �˰��� : ���� ����� - ���� ���� pdf
������ �� ���� : ����
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
    // printf("�޸� �Ҵ� �ް�\n");
    H->length = 0;
    // printf("���� �����ϰ�\n");
    H->crnt = (Node *)malloc(sizeof(Node));
    H->head = (Node *)malloc(sizeof(Node));
    H->crnt = NULL;
    H->head = NULL;
    // printf("���� ���� ����Ʈ �����\n");
    // printf("�� ����Ʈ ���� �Ϸ�\n");
    return H;
}

int isEmpty(BiDirectionCLL *bcList)
{
    return (bcList->head == NULL);
}

void addLast(BiDirectionCLL *bcList, int data)
{
    // printf("addLast ����\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }

    newNode->data = data;
    // printf("������ �Ҵ�: newNode->data = %d\n", newNode->data);

    if (isEmpty(bcList))
    {
        // printf("ù �����\n");
        // printf("���� ����: bcList->length = %d\n", bcList->length);
        bcList->head = newNode;
        // printf("head�� newNode�� ����: bcList->head->data = %d\n", bcList->head->data);
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
        // printf("bcList->crnt->data = %d\n", bcList->crnt->data);               // ���� ���� ����� ���� ��µ� �� -> ok
        // printf("bcList->head->rlink->data = %d\n", bcList->head->rlink->data); // ù ��° ��� ���� ����� ��ȣ ��� ���� -> ok
        // printf("bcList->head->llink->data = %d\n", bcList->head->llink->data); // ���� ���� ��(������ ���)�� �� ���� ���� -> ok
    }
    // printf("bcList->head->data = %d\n", bcList->head->data);
    // printf("addLast ���� ����\n");
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
    // ù ��° ������ ����
    Node *standard = bcList->head; // crnt�� �� ������ ��带 ���ϸ鼭 �ּҰ��� ã�� ��
    while (standard->rlink != bcList->head)
    {
        Node *stTemp = standard;
        Node *compare = standard->rlink; // �ּҰ��� ���ϱ� ���� ����
        int isChanged = 1;
        // printf("standard->data: %d\n", standard->data);
        // printf("compare->data ���� ����: %d\n", compare->data);
        while (compare != bcList->head)
        {
            // printf("���ؾߵǴ� ��: %d\n", min->data);
            if (stTemp->data > compare->data)
            {
                isChanged = 0;
                stTemp = compare;
            }
            // printf("������ �Ǵ� ��: %d\n", standard->data);
            //  printf("standard ���� ���� ���� ��: %d\n", param->data);
            compare = compare->rlink;
            // printf("�ȿ� while�� ��������: %d\n", compare != bcList->head);
            // printf("isChanged = %d\n", isChanged);
        }
        // printf("\n���� ���\n");
        // printf("������ �Ǵ� ��: %d\n", standard->data);
        // printf("����->standard ���� ���� ���� ��: %d\n", stTemp->data); // �ּҰ��� compare�� ���������� �̵��ϰ� �ݺ����� �������Ƿ� ���ʰ��� data�� �ּڰ�
        if (isChanged == 0)
        {
            swap(&(standard->data), &(stTemp->data));
            Node *afterChanged = bcList->head;
            for (int i = 0; i < LENGTH; i++)
            {
                printf("%d ��° ��� ��: %d\n", (i + 1), afterChanged->data);
                afterChanged = afterChanged->rlink;
            }
            printf("\n");
        }
        standard = standard->rlink;

        /*
        // swap�� �߻��ߴ��� Ȯ��
        Node *willRemove = bcList->head;
        for (int i = 0; i < 5; i++)
        {
            printf("%d ��° ��� ��: %d\n", (i + 1), willRemove->data);
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
    bcList = createList(); // ��� ��� �����

    /* isEmpty() Ȯ��
    int x = isEmpty(bcList);
    printf("%d\n", x);
    */

    int data;
    for (int i = 0; i < LENGTH; i++)
    {
        printf("���� �Է����ּ���: ");
        scanf("%d", &data);
        addLast(bcList, data);
        // ��带 �Է��� ������ ������ bcList�� ���� �� ���� ����� ���� ����Ʈ�ϱ�
        // �Ʒ� 3���� ��°��� �ּ�ó������ �� ��
        printf("�߰��� ����� ���� ��: %d\n", bcList->crnt->llink->data);
        printf("�߰��� ����� ��: %d\n", bcList->crnt->data);
        printf("�߰��� ����� ���� ��: %d\n\n", bcList->crnt->rlink->data);
    }
    // printf("ù ��° ��尪: %d\n", bcList->head->data);

    /*
    // addLast() Ȯ��
    Node *rlinkTest = bcList->crnt;
    printf("rlink ���� Ȯ��\n");
    printf("rlinkTest->rlink: %p\n", rlinkTest->rlink);
    printf("bcList->crnt: %p\n", bcList->crnt);
    while (rlinkTest->rlink != bcList->crnt)
    // for (int i = 0; i < 5; i++)
    {
        printf("%d�� data�� ���� ��� push �Ϸ�\n", rlinkTest->data);
        printf("rlinkTest: %p\n", rlinkTest);
        printf("rlinkTest->rlink: %p\n", rlinkTest->rlink);
        rlinkTest = rlinkTest->rlink;
    }
    printf("rlink ���� Ȯ�� ����\n\n");

    Node *llinkTest = bcList->crnt;
    printf("llink ���� Ȯ��\n");
    while (llinkTest->llink != bcList->crnt)
    // for (int i = 0; i < 5; i++)
    {
        printf("%d�� data�� ���� ��� push �Ϸ�\n", llinkTest->data);
        printf("llinkTest: %p\n", llinkTest);
        printf("llinkTest->llink: %p\n", llinkTest->llink);
        llinkTest = llinkTest->llink;
    }
    printf("llink ���� Ȯ�� ����\n\n");
    */
    bcList->crnt = bcList->crnt->rlink;
    SelectionSort(bcList);
    // printf("bcList->length = %d\n", bcList->length);
    printf("���� ����\n�������� ver.\n");
    Node *p = bcList->head;
    int cnt = 1;
    int sum = 0;
    double avg;
    while (p->rlink != bcList->head)
    {
        printf("%d ��° ���: %d\n", cnt, p->data);
        sum += p->data;
        p = p->rlink;
        cnt++;
    }
    printf("%d ��° ���: %d\n", cnt, p->data);
    sum += p->data;
    avg = sum / (double)LENGTH;
    printf("bcList ���� %d���� ���� ���� ��: %d\n", LENGTH, sum);
    printf("bcList ���� %d���� ���� ���� ���: %f\n", LENGTH, avg);

    printf("\n���� ����\n�������� ver.\n");
    Node *p2 = bcList->head->llink;
    int cnt2 = 1;
    int sum2 = 0;
    double avg2;
    while (p2->llink != bcList->head->llink)
    {
        printf("%d ��° ���: %d\n", cnt2, p2->data);
        sum2 += p2->data;
        p2 = p2->llink;
        cnt2++;
    }
    printf("%d ��° ���: %d\n", cnt2, p2->data);
    sum2 += p2->data;
    avg2 = sum2 / (double)LENGTH;
    printf("bcList ���� %d���� ���� ���� ��: %d\n", LENGTH, sum2);
    printf("bcList ���� %d���� ���� ���� ���: %f\n", LENGTH, avg2);
}

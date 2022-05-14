#define Q_SIZE 100

typedef int element;
element queue[Q_SIZE];

void enqueue(int *rear, element item)
{
    if (*rear == Q_SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    queue[++*rear] = item;
}

int isEmpty(int *front, int rear)
{
    if (*front == rear)
        return 1;
    else
        return 0;
}

element dequeue(int *front, int rear)
{
    if (*front == rear)
    {
        printf("Queue is EMPTY\n");
        exit(1);
    }
    else
        ++*front;
}

element peek(int front, int rear)
{
    if (front == rear)
    {
        printf("Queue is EMPTY\n");
        exit(1);
    }
    else
    {
        return queue[front++];
    }
}

int main()
{
    int front = -1; // 삭제 연산 인덱스
    int rear = -1;  // 삽입 연산 인덱스
    element data;

    enqueue(&rear, 1);
    enqueue(&rear, 2);

    data = peek(front, rear);

    data = dequeue(&front, rear);
    printf("data=%d\n", data);

    data = dequeue(&front, rear);
    printf("data=%d\n", data);

    return 0;
}
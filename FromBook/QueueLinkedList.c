#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[10];
    char grade;
} element;

typedef struct queueNode
{
    element data;
    struct queueNode *link;
} queueNode;

typedef struct
{
    queueNode *front;
    queueNode *rear;
    int length;
} linkedQueue;

linkedQueue *createQ()
{
    linkedQueue *q;
    q = (linkedQueue *)malloc(sizeof(linkedQueue));
    q->front = NULL;
    q->rear = NULL;
    q->length = 0;
    return q;
}

int isEmpty(linkedQueue *q)
{
    return (q->length == 0);
}

void enqueue(linkedQueue *q, element item)
{
    queueNode *newNode;
    newNode = (queueNode *)malloc(sizeof(queueNode));
    newNode->data = item;
    newNode->link = NULL;
    if (q->length == 0)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->link = newNode;
        q->rear = newNode;
    }
    q->length++;
}

element dequeue(linkedQueue *q)
{
    queueNode *temp;
    element item;
    if (q->length == 0)
    {
        printf("Queue is EMPTY\n");
        exit(1);
    }
    else
    {
        item = q->front->data;
        temp = q->front;
        q->front = q->front->link;
        if (q->front == NULL)
            q->rear = NULL;
        q->length--;
        free(temp);
        return item;
    }
}

void delete (linkedQueue *q)
{
    queueNode *temp;
    if (q->length == 0)
    {
        printf("Queue is EMPTY\n");
        exit(1);
    }
    else
    {
        temp = q->front;
        q->front = q->front->link;
        if (q->front == NULL)
            q->rear = NULL;
        q->length--;
        free(temp);
    }
}

element peek(linkedQueue *q)
{
    if (q->length == 0)
    {
        printf("Queue is EMPTY\n");
        exit(1);
    }
    else
        return q->front->data;
}

int main()
{
    element item;
    linkedQueue *q;
    q = createQ();

    item.id = 123;
    strcpy(item.name, "Hong");
    item.grade = 'A';

    enqueue(q, item);
}

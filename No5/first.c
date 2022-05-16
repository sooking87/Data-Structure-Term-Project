#include <stdio.h>
#define LENGTH 11
typedef struct data
{
    int num;
    char name[10];
} element;

typedef struct Node
{
    element data;
    struct Node *rlink;
} Node;

typedef struct SinglyCircularLL
{
    Node *next;
} SinglyCircularLL;

SinglyCircularLL *createList()
{
    SinglyCircularLL *H;
    H = (SinglyCircularLL *)malloc(sizeof(SinglyCircularLL));
    H->next->rlink = H->next;
    return H;
}
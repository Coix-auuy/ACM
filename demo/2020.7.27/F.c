#include <stdio.h>
#include <stdlib.h>
struct pm
{
    int x, y;
} a[510];
typedef struct node
{
    int data;
    struct node *next;
} Node;
int main()
{
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    Node *L = (Node*)malloc(sizeof(Node));
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = a[0].x;
    L->next = q;
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = a[0].y;
    q->next = p;
    for (int i = 1; i < m; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = a[i].y;
    }
}
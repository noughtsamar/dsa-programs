#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} nodet;

void print(nodet *t)
{
    nodet *p = t->link;
    do
    {
        printf("%d ", p->data);
        p = p->link;
    } while (p != t->link);
}

int main()
{
    nodet *tail = NULL;
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    for (int i = 1; i <= n; i++)
    {
        if (tail == NULL)
        {
            nodet *new = (nodet *)malloc(sizeof(nodet));
            new->link = new;
            new->data = i;
            tail = new;
        }
        else
        {
            nodet *new = (nodet *)malloc(sizeof(nodet));
            new->data = i;
            new->link = tail->link;
            tail->link = new;
            tail = tail->link;
        }
    }
    n--;
    while (n--)
    {
        for (int i = 0; i < k - 1; i++)
        {
            tail = tail->link;
        }
        printf("deleted %d.\n", tail->link->data);
        nodet *temp = tail->link;
        tail->link = tail->link->link;
        free(temp);
        temp = NULL;
    }
    printf("The winner is: %d", tail->data);
}
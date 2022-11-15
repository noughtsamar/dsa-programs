#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;
NODE *create(NODE *);
NODE *insert_front(NODE *, int);
NODE *destroy(NODE *);
void display(NODE *);
NODE *delete_at_pos(NODE *, int);
NODE *delete_alt(NODE *, int);
NODE *create(NODE *head)
{
    head = NULL;
    return head;
}
NODE *insert_front(NODE *head, int ele)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = head;
    head = temp;
    return head;
}
NODE *destroy(NODE *head)
{
    NODE *temp = head;
    while (head)
    {
        head = head->link;
        free(temp);
        temp = head;
    }
    return head;
}
void display(NODE *head)
{
    while (head)
    {
        printf("%d\t", head->data);
        head = head->link;
    }
    printf("\n");
}
NODE *delete_front(NODE *head)
{
    if (head == NULL)
    {
        printf("No element to delete\n");
        return head;
    }
    NODE *temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
    return head;
}
NODE *delete_at_pos(NODE *head, int pos)
{
    if (head == NULL)
    {
        printf("No element to delete\n");
        return head;
    }
    if (pos == 0)
    {
        head = delete_front(head);
    }
    else
    {
        NODE *pres = head;
        NODE *prev = NULL;
        int flag = 1;
        for (int i = 0; i < pos && flag; i++)
        {
            prev = pres;
            pres = pres->link;
            if (pres == NULL)
                flag = 0;
        }
        if (flag)
        {
            prev->link = pres->link;
            free(pres);
            pres = NULL;
        }
        else
            printf("Invalid position\n");
    }
    return head;
}
NODE *delete_alt(NODE *head, int n)
{
    int l;
    if (n % 2 == 0)
        l = n / 2 - 1;
    else
        l = n / 2;
    for (int i = 0; i <= l; i++)
    {
        head = delete_at_pos(head, i);
    }
    return head;
}
int main()
{
    int n;
    printf("Enter size of the list\n");
    scanf("%d", &n);
    NODE *head;
    head = create(head);
    int ele;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element\n");
        scanf("%d", &ele);
        head = insert_front(head, ele);
    }
    display(head);
    head = delete_alt(head, n);
    display(head);
    destroy(head);
    return 0;
}

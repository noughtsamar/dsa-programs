#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} NODE;

void display(NODE *head)
{
    NODE *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void insert_at_beginning(NODE **h, int d)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = d;
    ptr->link = *h;
    *h = ptr;
}

void insert_at_position(NODE *head, int d, int pos)
{
    NODE *ptr = head;
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = d;
    temp->link = NULL;

    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}

NODE *delete_at_beginning(NODE *h)
{
    if (h == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        NODE *temp = h;
        h = h->link;
        free(temp);
        temp = NULL;
    }
    return h;
}

NODE *delete_at_end(NODE *head)
{
    NODE *temp = head;
    NODE *temp2 = head;
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}

NODE *del_at_pos(NODE *head, int pos)
{
    NODE *temp = head;
    NODE *temp2 = head;
    if (head == NULL)
    {
        printf("Empty list");
    }
    else if (pos == 0)
    {
        head = head->link;
        free(temp);
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = temp->link;
        free(temp);
        temp = NULL;
    }
    return head;
}
void insert_at_end(NODE *head, int info)
{
    NODE *ptr = head;
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = info;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void count(NODE *head)
{
    int c = 0;
    NODE *temp;
    temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->link;
    }
    printf("\n%d", c);
}

int main()
{
    NODE *head;
    head = (NODE *)malloc(sizeof(NODE));
    head->data = 10;
    head->link = NULL;
    // head = delete_at_beginning(head);
    // head = delete_at_end(head);
    // head = del_at_pos(head, 2);
    int check;
    printf("add node: ");
    scanf("%d", &check);
    while(check!=0)
    {
        int value;
        printf("node value: ");
        scanf("%d", &value);
        NODE* temp = NULL;
        NODE* prev = NULL;
        NODE* newnode = malloc(sizeof(NODE));
        //printf("checkpt 2");
        newnode->data = value;
        newnode->link = NULL;
        //printf("checkpt 3");
        temp = head;
        prev = temp;
        while((value>temp->data) && (temp->link!=NULL))
        {
           // printf("checkpt 1");
            prev = temp;
            temp = temp->link;
        }
        if(temp->link==0)
        {
            temp->link = newnode;
            newnode->link = NULL;
        }else
        {
            prev->link = newnode;
            newnode->link = temp;
        }

        printf("add node? ");
        scanf("%d", &check);
    }
    display(head);
    count(head);
    return 0;
}

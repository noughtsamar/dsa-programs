#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int prio;
    struct node* link;
}nodet;

nodet* enqueue(nodet* h, int d, int p)
{   
    nodet* new = (nodet*)malloc(sizeof(nodet));
    new->data = d;
    new->prio = p;
    new->link = NULL;
    if(h==NULL)
    {
        h = new;
    }else{
        nodet* temp = h;
        while(temp->link!=NULL && temp->link->prio <= new->prio)
        {
            temp = temp->link;            
        }
        new->link = temp->link;
        temp->link = new;
    }
    return h;

}

nodet* dequeue(nodet* h, int d)
{
    
}

void display(nodet* head)
{
    nodet *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;        
    }
    printf("\n");

}

int main()
{
    nodet* head=NULL;
    head = NULL;
    head = enqueue(head, 10, 1);
    head = enqueue(head, 20, 2);
    head = enqueue(head, 40, 4);
    head = enqueue(head, 30, 3);
    head = enqueue(head, 60, 6);
    head = enqueue(head, 90, 9);
    head = enqueue(head, 50, 5);
    head = enqueue(head, 70, 7);
    head = enqueue(head, 80, 8);
    display(head);
}
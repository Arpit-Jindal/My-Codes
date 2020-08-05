#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
}*head;
void rotate(struct node **head_ref, int k);
  void insert()
{
    int n,i,value;
    struct node *temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf(" ");
}
int main(void)
{
    int t,k,n,value;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     rotate(&head,k);
     printList(head);
     }
     return(0);
}
void rotate(struct node **head_ref, int k)
{
    node* newhead = *head_ref;
    node* prevtail= NULL;
    while(k--)
    {
        prevtail = newhead;
        newhead = newhead->next;
    }
    if(newhead == NULL) 
        return;
    prevtail->next = NULL;
    node* newtail = newhead;
    while (newtail->next!=NULL)
        newtail = newtail->next;
    newtail->next = *head_ref;
    *head_ref = newhead;
}

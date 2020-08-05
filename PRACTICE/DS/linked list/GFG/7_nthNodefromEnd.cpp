#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
int getNthFromLast(struct Node * head, int n);
int main()
{
    int T, i, n, l, k;
    cin >> T;
    while (T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }
        cout << getNthFromLast(head, k);
    }
    return 0;
}
int getNthFromLast(Node * head, int n)
{
    Node* slow = head, *fast = head;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        fast = fast->next;
        count++;
        if (fast == NULL)
        {
            if (count == n)
                return slow->data;
            else
                return -1;
        }
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}
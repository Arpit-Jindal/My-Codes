#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
}*head;
void insert()
{
    int n, value;
    cin >> n;
    struct node *temp;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            head = new node();
            head->data = value;
            head->next = NULL;
            temp = head;
            continue;
        }
        else
        {
            temp->next = new node();
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
struct node *reverse (struct node *head, int k)
{
    node* current = head, *prev = NULL, *next = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverse(next, k);
    }
    return prev;
}
int main(void)
{
    int t, k, value, n;
    cin >> t;
    while (t--)
    {
        insert();
        cin >> k;
        head = reverse(head, k);
        printList(head);
    }
}
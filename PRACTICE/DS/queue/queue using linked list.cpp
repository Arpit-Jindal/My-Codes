#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* front = NULL;
node* rear = NULL;

void push(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void pop()
{
    if (front == NULL)
    {
        cout << "Queue is already Empty\n";
        return;
    }
    if (front == rear) {
        front = rear = NULL;
        cout << "Queue is now Empty\n";
    }
    else
    {
        node* temp = front;
        front = front->next;
        delete temp;
    }
}
void print()
{
    node* temp = front;
    cout << "queue :";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << endl;
}
int main()
{
    push(1); push(2);
    push(3); push(4);
    push(5); push(6);
    push(7);

    print();
    pop();
    print();

}


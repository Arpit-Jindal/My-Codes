#include<iostream>
using namespace std;

struct node
{
	int data;
	int priority;
	node* next;
};

node* newnode(int data, int x)
{
	node* temp = new node();
	temp->data = data;
	temp->priority = x;
	temp->next = NULL;
	return temp;
}

void pop(node**head)
{
	node* temp = *head;
	*head = temp->next;
	delete temp;
}

int peek(node**head)
{
	return (*head)->data;
}

void print(node**head)
{
	while ((*head) != NULL)
	{
		cout << peek(head) << "->" << (*head)->priority << endl;
		pop(head);
	}
}

void push(node**head, int data, int p)
{
	node* start = *head;
	node*temp = newnode(data, p);
	if (start == NULL)
	{
		(*head) = temp;
		return;
	}
	if (start->priority < p)
	{
		temp->next = start;
		(*head) = temp;
	}
	else
	{
		while (start->next != NULL && start->next->priority > p)
		{
			start = start->next;
		}
		temp->next = start->next;
		start->next = temp;
	}
}

int main()
{
	node* head = NULL;
	push(&head, 8, 5);
	push(&head, 5, 1);
	push(&head, 7, 0);
	push(&head, 6, 3);
	push(&head, 4, 2);

	print(&head);


}
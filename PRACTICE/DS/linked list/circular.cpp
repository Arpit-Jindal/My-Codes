#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* getnewnode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}
node* insertAtBeginning(node* last, int data)
{
	node* temp = getnewnode(data);
	if (last == NULL)
	{
		last = temp;
		last->next = last;
	}
	else
	{
		temp->next = last->next;
		last->next = temp;
	}
	return last;
}
node* insertAtend(node* last, int data)
{
	node* temp = getnewnode(data);
	if (last == NULL)
	{
		last = temp;
		last->next = last;
	}
	else
	{
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
	return last;
}
node* insertAtAfter(node* last, int data, int key)
{
	if (last == NULL) return NULL;
	node* p = last->next;
	do
	{
		if (p->data == key)
		{
			node* temp = getnewnode(data);
			temp->next = p->next;
			p->next = temp;

			if (p == last) last = temp; // only one node was present
			return last;
		}
		p = p->next;
	} while (p != last->next);

	cout << key << " not present" << endl;
	return last;
}
void printList (node* last)
{
	if (last == NULL) return;
	node* first = last->next;
	do
	{
		cout << first->data << " ";
		first = first->next;
	} while (first != last->next);
	cout << endl;
}

node* deleteNode(node* last, int key)
{
	if (last == NULL) return NULL;
	node* curr = last;
	node* prev;
	do
	{
		prev = curr;
		curr = curr->next;
		if (curr->data == key)
			break; 
	} while (curr != last);
	if (last->next == last && last->data == key)
	{
		last = NULL;
		delete curr;
	}
	else if (last->data == key)
	{
		prev->next = last->next;
		last->next = NULL;
		last = prev;
		delete curr;
	}
	else if (curr->data == key)
	{
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
	else
		cout << key << " not found" << endl;
	return last;
}
int main()
{
	node* last = NULL;
	last = insertAtBeginning(last, 10);
	last = insertAtBeginning(last, 5);
	last = insertAtend(last, 20);
	last = insertAtAfter(last, 15, 10);

	printList(last);

	last = deleteNode(last, 15);
	printList(last);
	last = deleteNode(last, 20);
	printList(last);
	last = deleteNode(last, 5);
	printList(last);
	last = deleteNode(last, 12);
}

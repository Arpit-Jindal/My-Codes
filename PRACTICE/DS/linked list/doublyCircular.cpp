#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node* prev;
};
node* getnewnode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
node* insertAtBeginning(node* last, int data)
{
	node* temp = getnewnode(data);
	if (last == NULL)
	{
		last = temp;
		last->next = last;
		last->prev = last;
	}
	else
	{
		temp->next = last->next;
		temp->prev = last;
		last->next->prev = temp;
		last->next = temp;
	}
	return last;
}
node* deleteNode(node* last, int key)
{
	if (last == NULL)
		return NULL;
	node* curr = last;
	do
	{
		curr = curr->next;
		if (curr->data == key) break;
	} while (curr != last);
	if (last->next == last && last->data == key)
	{
		last = NULL;
		delete curr;
	}

	else if (last->data == key)
	{
		last->prev->next = last->next;
		last->next->prev = last->prev;
		last = last->prev;
		delete curr;
	}
	else if (curr->data == key)
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete curr;
	}
	else
		cout << key << " not found" << endl;
	return last;
}
void printList (node* last)
{
	if (last == NULL) return;
	node * first = last->next;
	do
	{
		cout << first->data << " ";
		first = first->next;
	} while (first != last->next);
	cout << endl;
}
int main()
{
	node* last = NULL;
	last = insertAtBeginning(last, 20);
	last = insertAtBeginning(last, 15);
	last = insertAtBeginning(last, 10);
	last = insertAtBeginning(last, 5);
	printList(last);

	last = deleteNode(last, 5);
	printList(last);
	last = deleteNode(last, 20);
	printList(last);
}
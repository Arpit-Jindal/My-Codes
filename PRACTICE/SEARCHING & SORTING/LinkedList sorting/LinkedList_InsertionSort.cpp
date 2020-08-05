#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* Insert(node* root, int x)
{
	node* temp = new node();
	temp->data = x;
	temp->next = NULL;
	if (root == NULL)
		root = temp;
	else if (x < root->data)
	{
		temp->next = root;
		root = temp;
	}
	else //insert AFTER
	{
		node* head = root;
		while (head->next != NULL && x > head->next->data)
			head = head->next;

		temp->next = head->next;
		head->next = temp;
	}
	return root;
}
node* insertionsort(node* root)
{
	node* temp = root;
	node* head = NULL;
	while (temp)
	{
		head = Insert(head, temp->data);
		temp = temp->next;
	}
	return head;
}

node* push(node* root, int data)
{
	node* temp = new node();
	temp->data = data;
	temp->next = root;
	root = temp;
	return root;
}
void print(node* root)
{
	node* temp = root;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	node* root = NULL;
	root = push(root, 10);
	root = push(root, 15);
	root = push(root, 12);
	root = push(root, 5);
	root = push(root, 20);
	print(root);
	root = insertionsort(root);
	print(root);
}
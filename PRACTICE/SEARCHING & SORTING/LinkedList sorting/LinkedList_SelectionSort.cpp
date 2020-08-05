#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* selectionsort(node* root)
{
	node* temp = root;
	node* temp1;
	while (temp)
	{
		node* min = temp;
		temp1 = temp->next;
		while (temp1)
		{
			if (temp1->data < min->data)
				min = temp1;
			temp1 = temp1->next;
		}
		if (min != temp)
			swap(min->data, temp->data);
		temp = temp->next;
	}
	return root;
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
	root = selectionsort(root);
	print(root);
}
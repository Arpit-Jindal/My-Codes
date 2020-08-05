#include<iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};
node* root = NULL;

void insert(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->link = NULL;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		temp->link = root;
		root = temp;
	}
}
void printreverse(node* root)
{
	if (root == NULL)
		return;
	printreverse(root->link);
	cout << root->data << " ";
}
int main()
{
	insert(10);
	insert(5);
	insert(6);
	insert(9);
	printreverse(root);
}
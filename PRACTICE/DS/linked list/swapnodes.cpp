#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* Insert(node* root, int data)
{
	node* temp = new node();
	temp->data = data;
	temp->next = root;
	root = temp;
	return root;
}
void print(node* root)
{
	while (root != NULL)
	{
		cout << root->data << " ";
		root = root->next;
	}
	cout << endl;
}
node* swap(node* root, int a, int b)
{
	if (a == b) return root;

	node* currX = root;
	node* currY = root;
	node* prevX = NULL;
	node* prevY = NULL;
	while (currX != NULL && currX->data != a)
	{
		prevX = currX;
		currX = currX->next;
	}
	while (currY != NULL && currY->data != b)
	{
		prevY = currY;
		currY = currY->next;
	}
	if (currX == NULL || currY == NULL)
		return root;

	if (prevX == NULL)
		root = currY;
	else
		prevX->next = currY;

	if (prevY == NULL)
		root = currX;
	else
		prevY->next = currX;
	
	swap(currY->next,currX->next);
	return root;
}
int main()
{
	node* root = NULL;
	root = Insert(root, 20);
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 1);
	root = Insert(root, 30);
	print(root);
	root = swap(root, 30, 20);
	print(root);
}
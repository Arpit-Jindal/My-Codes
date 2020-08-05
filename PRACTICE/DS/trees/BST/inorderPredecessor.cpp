#include<iostream>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
node* Search(node* root, int data) {
	if (root == NULL) return NULL;
	else if (root->data == data) return root;
	else if (root->data < data) return Search(root->right, data);
	else return Search(root->left, data);
}
node* FindMax(node* root)
{
	if (root == NULL) return NULL;
	while (root->right != NULL)
		root = root->right;
	return root;
}
node* getPredecessor(node* root, int data)
{
	node* current = Search(root, data);
	if (current == NULL) return NULL;

	//Case 1: Node has left subtree
	if (current->left != NULL)
	{
		return FindMax(current->left);
	}
	//Case 2: No left subtree
	else
	{
		node* predecessor = NULL;
		node* temp = root;
		while (temp != current)
		{
			if (current->data > temp->data)
			{
				predecessor = temp;
				temp = temp->right;
			}
			else
				temp = temp ->left;
		}
		return predecessor;
	}
}

node* insert(node* root, int data)
{
	if (root == NULL)
	{
		node* temp = new node();
		temp->left = temp->right = NULL;
		temp->data = data;
		root = temp;
	}
	else if (root->data < data) root->right = insert(root->right, data);
	else root->left = insert (root->left, data);
	return root;
}

int main()
{
	node* root = NULL;
	root = insert(root, 10); root = insert(root, 20);
	root = insert(root, 5); root = insert(root, 7);
	root = insert(root, 6); root = insert(root, 3);
	root = insert(root, 8);

	node* predecessor = getPredecessor(root, 8);
	cout << "predecessor: " << predecessor->data;
}
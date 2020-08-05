#include<iostream>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
node* FindMin(node* root)
{
	if (root == NULL) return root;
	while (root->left != NULL) root = root->left;
	return root;
}
node* Search(node* root, int data) {
	if (root == NULL) return NULL;
	else if (root->data == data) return root;
	else if (root->data < data) return Search(root->right, data);
	else return Search(root->left, data);
}
node* GetSuccessor(node* root, int data)
{
	//Search the Node - O(h)
	node* current = Search(root, data);
	if (current == NULL) return NULL;

	//Case 1: Node has right subtree
	if (current->right != NULL)
		return FindMin(current->right);

	//Case 2: No right subtree
	else
	{
		node* successor = NULL;
		node* temp = root;
		while (temp != current)
		{
			if (current->data < temp->data)
			{
				successor = temp;
				temp = temp->left;
			}
			else
				temp = temp->right;
		}
		return successor;
	}
}

node* insert(node* root, int data);

int main()
{
	node* root = NULL;
	root = insert(root, 10); root = insert(root, 15);
	root = insert(root, 20); root = insert(root, 70);
	root = insert(root, 6);

	node* successor = GetSuccessor(root, 20);
	cout << "successor: " << successor->data << endl;

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
	else if (data <= root->data) root->left = insert(root->left, data);
	else root->right = insert(root->right, data);

	return root;

}
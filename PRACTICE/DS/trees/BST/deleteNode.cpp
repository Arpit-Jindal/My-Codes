#include <iostream>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
node* FindMin(node* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}
node* Delete(node* root, int data)
{
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	else //element found (data == root->data)
	{
		//Case 1: No Child
		if (root->left == NULL && root->right == NULL)
		{
			delete root; // now it is a dangling pointer
			root = NULL;
		}
		//Case 2: One Child
		else if (root->left == NULL)
		{
			node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			node* temp = root;
			root = root->left;
			delete temp;
		}
		//Case 3: Two Child
		else
		{
			node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}

	}
	return root;
}

node* insert(node* root, int data);
void inorder(node* root);

int main()
{
	node* root = NULL;
	root = insert(root, 10); root = insert(root, 15);
	root = insert(root, 12); root = insert(root, 25);
	root = insert(root, 6); root = insert(root, 3);
	root = insert(root, 7);

	inorder(root);
	root = Delete(root, 10);
	cout << endl;
	inorder(root);
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
	else if (data <= root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;

}
void inorder(node* root)
{
	if (root == NULL)return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
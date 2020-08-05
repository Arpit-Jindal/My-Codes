#include<iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	int ht;
};

int height(node* root)
{
	if (root == NULL) return -1;

	return root->ht;
}
node* rightRotate(node* root)
{
	node* newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	root->ht = max(height(root->left), height(root->right)) + 1;
	newRoot->ht = max(height(newRoot->left), height(newRoot->right)) + 1;
	return newRoot;
}
node* leftRotate(node* root)
{
	node* newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;

	root->ht = max(height(root->left), height(root->right)) + 1;
	newRoot->ht = max(height(newRoot->left), height(newRoot->right)) + 1;
	return newRoot;
}
node* avlInsert(node* root, int data)
{
	if (root == NULL)
	{
		node* newNode = new node();
		newNode->left = newNode->right = NULL;
		newNode->data = data;
		newNode->ht = 0;
		return newNode;
	}
	if (data < root->data) {
		root->left = avlInsert(root->left, data);
	}
	else {
		root->right = avlInsert(root->right, data);
	}

	root->ht = max(height(root->left), height(root->right)) + 1;
	int balance = height(root->left) - height(root->right);
	if (balance > 1)
	{
		if (height(root->left->left) >= height(root->left->right)) {
			return rightRotate(root); //LL
		}
		else {//LR
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	else if (balance < -1)
	{
		if (height(root->right->right) >= height(root->right->left)) {
			return leftRotate(root);//RR
		}
		else {//RL
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}

	return root;
}

void preorder(node* root)
{
	if (root == NULL)return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	node* root = NULL;
	root = avlInsert(root, 10);
	root = avlInsert(root, 20);
	root = avlInsert(root, 30);
	root = avlInsert(root, 40);
	root = avlInsert(root, 50);
	root = avlInsert(root, 25);
	preorder(root);
}
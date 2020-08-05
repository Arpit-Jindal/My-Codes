#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
void printleft(node* root) {
	if (root == NULL) return;
	if (root->left) {
		cout << root->data << " ";
		printleft(root->left);
	} else if (root->right) {
		cout << root->data << " ";
		printleft(root->right);
	}
}
void printright(node* root) {
	if (root == NULL) return;
	if (root->right) {
		printright(root->right);
		cout << root->data << " ";
	} else if (root->left) {
		printright(root->left);
		cout << root->data << " ";
	}
}
void printleaf(node* root) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL) cout << root->data << " ";
	printleaf(root->left);
	printleaf(root->right);
}
void boundary(node* root) {
	printleft(root);
	printleaf(root);
	printright(root->right);
}
int main()
{
	node* root = new node(1); 

	root->left = new node(3); 
	root->right = new node(7); 
	root->left->right = new node(5);
	root->left->right->right = new node(6); 

	root->right->left = new node(9);
	root->right->left->left = new node(10); 
	boundary(root);
}
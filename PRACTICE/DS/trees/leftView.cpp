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
void leftview(node* root, int &maxlevel, int level) {
	if (root == NULL)return;
	if (level > maxlevel) {
		cout << root->data << endl;
		maxlevel = level;
	}
	leftview(root->left, maxlevel, level + 1);
	leftview(root->right, maxlevel, level + 1);
}
//alternate approach
void leftView(node* root) {
	queue<node*> q;
	if (root == NULL) return;
	q.push(root);
	q.push(NULL);
	node* prev = NULL;
	while (!q.empty()) {
		node* temp = q.front(); q.pop();
		if (temp == NULL) {
			if (!q.empty()) q.push(NULL);
			prev = NULL;
		}
		else {
			if (prev == NULL)
				cout << temp->data << " ";
			prev = temp;
			if (temp->left)q.push(temp->left);
			if (temp->right)q.push(temp->right);
		}
	}
}
int main()
{
	node* root = new node(12);
	root->left = new node(10);
	root->right = new node(30);
	root->right->left = new node(25);
	root->right->right = new node(40);

	// int maxlevel = -1;
	// leftview(root, maxlevel, 0);
	leftView(root);
}
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
void rightview(node* root, int &maxlevel, int level) {
	if (root == NULL)return;
	if (level > maxlevel) {
		cout << root->data << " ";
		maxlevel = level;
	}
	rightview(root->right, maxlevel, level + 1);
	rightview(root->left, maxlevel, level + 1);
}
//another approach
void rightView(node* root) {
	if (root == NULL) return;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* temp = q.front(); q.pop();
		if (temp == NULL) {
			if (!q.empty())
				q.push(NULL);
		}
		else {
			if (q.front() == NULL)
				cout << temp->data << " ";
			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
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
	root->right->right->right = new node(50);
	// int maxlevel = -1;
	// rightview(root, maxlevel, 0);
	rightView(root);

}
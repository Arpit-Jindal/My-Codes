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
//level order
void TopView (node* root) {
	queue<pair<node*, int>> q;
	map<int, int> m;
	q.push(make_pair(root, 0));
	while (!q.empty()) {
		pair<node*, int> p = q.front(); q.pop();
		node* node = p.first;
		int hd = p.second;
		if (m.find(hd) == m.end())
			m[hd] = node->data;
		if (node->left) 
			q.push(make_pair(node->left, hd - 1));
		if (node->right) 
			q.push(make_pair(node->right, hd + 1));
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->second << " ";
	}
}
//preorder
void helper(node* root, map<int, int> &m, int hd) {
	if (root == NULL) return;
	if (m[hd] == 0) m[hd] = root->data;
	helper(root->left, m, hd - 1);
	helper(root->right, m, hd + 1);
}
void topView(node* root) {
	map<int, int> m;
	helper(root, m, 0);
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->second << " ";
	}
}
int main()
{
	node* root = new node(12);
	root->left = new node(10);
	root->right = new node(30);
	root->right->left = new node(25);
	root->right->left->left = new node(99);
	root->right->left->left->left = new node(109);
	root->right->right = new node(40);
	root->right->right->right = new node(50);
	TopView(root);
}
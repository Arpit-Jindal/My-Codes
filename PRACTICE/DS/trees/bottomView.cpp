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
//levelorder
void BottomView (node* root) {
	queue<pair<node*, int>> q;
	map<int, int> m;
	q.push(make_pair(root, 0));
	while (!q.empty()) {
		pair<node*, int> p = q.front(); q.pop();
		node* node = p.first;
		int hd = p.second;
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
void helper(node* root, map<int, pair<int, int> > &m, int ht, int hd) {
	if (root == NULL) return;
	if (m.find(hd) != m.end()) {
		if (m[hd].second <= ht)
			m[hd] = {root->data, ht};
	} else {
		m[hd] = {root->data, ht};
	}
	helper(root->left, m, ht + 1, hd - 1);
	helper(root->right, m, ht + 1, hd + 1);
}
void bottomView(node* root) {
	map<int, pair<int, int>> m;
	helper(root, m, 0, 0);
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->second.first << " ";
	}
}
int main()
{
	node *root = new node(20);
	root->left = new node(8);
	root->right = new node(22);
	root->left->left = new node(5);
	root->left->right = new node(3);
	root->right->left = new node(4);
	root->right->right = new node(25);
	root->left->right->left = new node(10);
	root->left->right->right = new node(14);
	BottomView(root);
}
#include<iostream>
using namespace std;
class node
{
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
node* insert(node*root, int data)
{
	node* temp = new node(data);
	if (root == NULL) root = temp;
	else if (root->data < data) root->right = insert(root->right, data);
	else if (root->data > data) root->left = insert (root->left, data);
	return root;
}
//O(n)
int diameter(node* root, int &res) {
	if (root == NULL) return 0;
	int l = diameter(root->left, res);
	int r = diameter(root->right, res);
	int temp = max(l, r) + 1;
	int ans = l + r + 1;
	res = max(res, ans);
	return temp;
}


//O(n2)
int height(node* root)
{
	if (root == NULL) return 0;
	return max(height(root->left), height(root->right)) + 1;
}
int diameter(node* root)
{
	if (root == NULL) return 0;
	int op1 = height(root->left) + height(root->right) + 1;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1, max(op2, op3));
}
int main()
{
	node* root = NULL;
	root = insert(root , 50);
	root = insert(root , 30);
	root = insert(root , 70);
	cout << diameter(root) << endl;
	int res = -1e9;
	int temp = diameter(root, res);
	cout << res;
}
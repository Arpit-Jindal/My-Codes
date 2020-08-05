#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
node* getnewnode(int data)
{
	node* temp = new node();
	temp->right = temp->left = NULL;
	temp->data = data;
	return temp;
}
bool search (node* root, int key)
{
	if (root == NULL) return false;
	if (root->data == key) return true;
	else if (root->data < key) return search(root->right, key);
	else return search(root->left, key);
}
node* Insert(node* root, int data)
{
	if (root == NULL) root = getnewnode(data);
	else if (root->data < data)
		root->right = Insert (root->right, data);
	else
		root->left = Insert(root->left, data);

	return root;
}
node* InsertIterative(node* root, int data)
{
	node* temp = getnewnode(data);
	if (root == NULL) root = temp;
	else
	{
		node* parent = NULL;
		node* current = root;
		while (current != NULL)
		{
			parent = current;
			if (current->data < data)
				current = current->right;
			else
				current = current->left;
		}
		if (parent->data <= data)
			parent->right = temp;
		else
			parent->left = temp;
	}
	return root;
}
bool sameTree(node* root1, node* root2)
{
	if (root1 == NULL && root2 == NULL) return true;
	if (root1 == NULL || root2 == NULL) return false;

	return root1->data == root2->data && sameTree(root1->left, root2->left) && sameTree (root1->right, root2->right);
}
int SIZE(node* root)
{
	if (root == NULL) return 0;
	return SIZE(root->left) + SIZE(root->right) + 1;
}
int sum(node* root)
{
	if (root == NULL) return 0;
	return sum(root->left) + sum(root->right) + root->data;
}
int height(node* root)
{
	if (root == NULL) return -1;
	return max(height(root->left), height(root->right)) + 1;
}
// int diameter(node* root)
// {
// 	if (root == NULL) return 0;
// 	int r1 = height(root->left) + 1;
// 	int r2 = height(root->right) + 1;
// 	int op1 = r1 + r2 ;
// 	int op2 = diameter(root->left);
// 	int op3 = diameter(root->right);
// 	return max(op1, max(op2, op3));
// }
bool isBST(node* root, int min = INT_MIN , int max = INT_MAX) //Initially call with INT_MIN & INT_MAX
{
	if (root == NULL) return true;
	if (root->data < min || root->data > max) return false;
	return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);

}
bool is_bst_inorder(node* root) {
	if (root == NULL) return true;
	static vector<int> v;
	is_bst(root->left);
	if (!v.empty() && root->data < v[v.size() - 1])
		return false;
	v.push_back(root->data);
	is_bst(root->right);
	return true;
}
node* lowestCommonAncesstor (node* root, int a, int b) //bst
{
	if (root->data < a && root->data < b)
		return lowestCommonAncesstor (root->right, a, b);
	else if (root->data > a && root->data > b)
		return lowestCommonAncesstor(root->left, a, b);
	else
		return root;
}
int main()
{
	node* root = NULL;
	root = Insert(root, 10); root = Insert(root, 6);
	root = Insert(root, 15); root = Insert(root, 12);
	root = Insert(root, 25); root = Insert(root, 3);
	root = Insert(root, 7);
	// cout << lowestCommonAncesstor(root, 3, 15)->data;
	// cout << diameter(root);
	cout << is_bst_inorder(root);

}
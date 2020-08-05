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
node* buildTree()
{
	int d; cin >> d;
	if (d == -1) return NULL;

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}
void printKthLevel(node* root, int k)
{
	if (root == NULL)return;
	if (k == 0)
	{
		cout << root->data << " ";
		return;
	}
	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);
	return;
}
int main()
{
	node* root = buildTree(); // Input = 3 4 -1 6 -1 -1 5 1 -1 -1 -1
	printKthLevel(root, 2);
}
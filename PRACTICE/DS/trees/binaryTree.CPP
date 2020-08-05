#include<iostream>
#include<queue>
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
node* CreateTreeFromArray(int arr[], int s, int e)
{
	if (s > e) return NULL;
	int mid = (s + e) / 2;
	node* root = new node(arr[mid]);
	root->left = CreateTreeFromArray(arr, s, mid - 1);
	root->right = CreateTreeFromArray(arr, mid + 1, e);
	return root;
}
node* CreateFromPRE_IN(int preorder[], int inorder[], int s, int e, int &pi)
{
	if (s > e)return NULL;
	node* root = new node(preorder[pi++]);
	if (s == e) return root; //leaf node

	int index; //inorder index
	for (index = s; index <= e; index++)
		if (inorder[index] == root->data) break;

	root->left = CreateFromPRE_IN(preorder, inorder, s, index - 1, pi);
	root->right = CreateFromPRE_IN(preorder, inorder, index + 1, e, pi);
	return root;
}
node* CreateFromPOST_IN(int postorder[], int inorder[], int s, int e, int &pi)
{
	if (s > e)return NULL;
	node* root = new node(postorder[pi--]);
	if (s == e) return root; //leaf node

	int index; //inorder index
	for (index = s; index <= e; index++)
		if (inorder[index] == root->data) break;

	root->right = CreateFromPOST_IN(postorder, inorder, index + 1, e, pi);
	root->left = CreateFromPOST_IN(postorder, inorder, s, index - 1, pi);
	return root;
}

void BFS(node* root)
{
	if (root == NULL)
		return;
	queue<node*> q;
	q.push(root);
	q.push(0);
	while (!q.empty())
	{
		node* current = q.front();
		q.pop();
		if (current == 0)
		{
			cout << endl;
			if (!q.empty())
				q.push(0);
		}
		else
		{	cout << current->data << " ";
			if (current->left != NULL) q.push(current->left);
			if (current->right != NULL) q.push(current->right);
		}
	}
}
int main()
{
	///Build tree
	// node* root = buildTree(); // Input = 3 4 -1 6 -1 -1 5 1 -1 -1 -1
	// BFS(root);

	///Create from array
	// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// node* root = CreateTreeFromArray(arr, 0, n - 1);
	// BFS(root);

	//Create from preorder and inorder
	int preorder[] = {1, 2, 3, 4, 8, 5, 6, 7};
	int inorder[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int n = sizeof(inorder) / sizeof(inorder[0]);
	int pi = 0;
	node* root = CreateFromPRE_IN(preorder, inorder, 0, n - 1, pi);
	BFS(root);

}
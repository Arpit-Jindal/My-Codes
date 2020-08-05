#include<iostream>
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
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}
node* insert(node* root, int data)
{
	if (root == NULL)
		return getnewnode(data);
	else if (data <= root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	return root;

}
bool Search(node* root, int data)
{
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return Search(root->left, data);
	else
		return Search(root->right, data);
}
//time complexity = O(n) - visiting each node once
int findheight(node* root)
{
	if (root == NULL)
		return -1; //if height is counted by no. of edges
	return max(findheight(root->left), findheight(root->right)) + 1;
}

int findmin(node*);
int findmin_recursion(node*);
int findmax(node*);

int main()
{
	node* root = NULL;
	root = insert(root, 10);
	root = insert(root, 15);
	root = insert(root, 20);
	root = insert(root, 70);
	root = insert(root, 6);

	int number;
	cout << "Enter number to be searched\n";
	cin >> number;
	if (Search(root, number) == true) cout << "Found\n";
	else cout << "Not Found\n";

	cout << endl << "MINIMUM: " << findmin_recursion(root) << endl;
	cout << "MAXIMUM: " << findmax(root) << endl;
}

int findmin(node* root) {
	if (root == NULL)
		return -1;
	while (root->left != NULL)
		root = root->left;
	return root->data;
}

int findmin_recursion(node* root) {
	if (root == NULL) return -1;
	if (root->left == NULL) return root->data;
	return findmin_recursion(root->left);
}

int findmax(node* root) {
	if (root == NULL) return -1;
	while (root->right != NULL) root = root->right;
	return root->data;
}

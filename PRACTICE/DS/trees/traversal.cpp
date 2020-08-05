#include<iostream>
#include<queue> //for levelorder
#include<stack> //for iterative depth first 
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
void preorder(node* root)
{
	if (root == NULL)return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node* root)
{
	if (root == NULL)return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
void inorder(node* root)
{
	if (root == NULL)return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void levelorder(node* root)
{
	if (root == NULL) return;
	queue <node*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		node* current = Q.front(); Q.pop();
		cout << current->data << " ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
	}
}
void preorderIterative (node* root)
{
	if (root == NULL) return;
	stack<node*> S;
	S.push(root);
	while (!S.empty())
	{
		root = S.top(); S.pop();
		cout << root->data << " ";
		//Right child is pushed before left child to make sure that left subtree is processed first.
		if (root->right != NULL )S.push(root->right);
		if (root->left != NULL )S.push(root->left);
	}
}
void postorderIterative(node* root)
{
	if (root == NULL) return;
	stack<node*> S1;
	stack<node*> S2;
	S1.push(root);
	while (!S1.empty())
	{
		root = S1.top(); S1.pop();
		S2.push(root);
		if (root->left != NULL ) S1.push(root->left);
		if (root->right != NULL ) S1.push(root->right);
	}
	while (!S2.empty())
	{
		cout << S2.top()->data << " ";
		S2.pop();
	}
}
// void inorderIterative (node* root)
// {
// 	if (root == NULL) return;
// 	stack<node*> S;
// 	while (root || !S.empty())
// 	{
// 		while (root) {
// 			S.push(root);
// 			root = root->left;
// 		}
// 		root = S.top(); S.pop();
// 		cout << root->data << " ";
// 		root = root->right;
// 	}
// }
void inorderIterative (node* root)
{
	if (root == NULL) return;
	stack<node*> S;
	while (1)
	{
		while (root) {
			S.push(root);
			root = root->left;
		}
		if (S.empty()) break;
		root = S.top(); S.pop();
		cout << root->data << " ";
		root = root->right;
	}
}
void levelByLevel(node* root)
{
	//1 queue and delimeter
	if (root == NULL)return;
	queue<node*> q;
	q.push(root);
	q.push(0);
	while (!q.empty())
	{
		node* current = q.front(); q.pop();
		if (current == 0)
		{
			cout << endl;
			if (!q.empty()) q.push(0);
		}
		else
		{	cout << current->data << " ";
			if (current->left != NULL) q.push(current->left);
			if (current->right != NULL) q.push(current->right);
		}
	}
	// //2 queue
	// queue<node*> q1;
	// queue<node*> q2;
	// q1.push(root);
	// while (!q1.empty() || !q2.empty())
	// {
	// 	while (!q1.empty())
	// 	{
	// 		node* current = q1.front();
	// 		q1.pop();
	// 		if (current->left != NULL)q2.push(current->left);
	// 		if (current->right != NULL)q2.push(current->right);
	// 		cout << current->data << " ";
	// 	}
	// 	cout << endl;
	// 	queue<node*> Q = q1;
	// 	q1 = q2;
	// 	q2 = Q;
	// }
}
//Level Order Traversal
void verticalOrderTraversalLO(node* root) {
	map<int, vector<int>> m;
	queue< pair<node*, int> > q;
	int hd = 0;
	q.push(make_pair(root, hd));

	while (!q.empty()) {
		pair<node*, int> temp = q.front(); q.pop();
		hd = temp.second;
		node* node = temp.first;
		m[hd].push_back(node->data);
		if (node->left != NULL)
			q.push(make_pair(node->left, hd - 1));
		if (node->right != NULL)
			q.push(make_pair(node->right, hd + 1));
	}

	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "\t: ";
		for (int i = 0; i < it->second.size(); i++) {
			cout << it->second[i] << " ";
		}
		cout << endl;
	}
}

void helperDiagnol(map<int, vector<int>>&m, TreeNode* A, int slope = 0) {
	if (A == NULL)return;
	m[slope].push_back(A->val);
	if (A->left)helperDiagnol(m, A->left, slope + 1);
	if (A->right)helperDiagnol(m, A->right, slope);
}
vector<int> diagonalTraversal(TreeNode* A) {
	map<int, vector<int>> m;
	helperDiagnol(m, A);
	vector<int> ans;
	for (auto x : m) {
		for (auto i : x.second) {
			ans.push_back(i);
		}
	}
	return ans;
}

node* insert(node* root, int data);
int main()
{
	node* root = NULL;
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 15);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 13);
	root = insert(root, 17);
	cout << "PREORDER: "; preorder(root); cout << endl;
	cout << "INORDER: "; inorder(root); cout << endl;
	cout << "POSTORDER: "; postorder(root); cout << endl;
	cout << "LEVEL ORDER: "; levelorder(root); cout << endl << endl;
	cout << "PREORDER ITERATIVE: "; preorderIterative(root); cout << endl;
	cout << "INORDER ITERATIVE: "; inorderIterative(root); cout << endl;
	cout << "POSTORDER ITERATIVE: "; postorderIterative(root); cout << endl;
	cout << "LEVEL BY LEVEL: " << endl; levelByLevel(root);
}
node* insert(node* root, int data)
{
	if (root == NULL)
	{
		node* temp = new node();
		temp->left = temp->right = NULL;
		temp->data = data;
		root = temp;
	}
	else if (data <= root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;
}
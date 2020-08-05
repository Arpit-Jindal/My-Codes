#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
bool isPalindromeUtil(node* &left, node* right)
{
	if (right == NULL) 
		return true;
	if(isPalindromeUtil(left, right->next) == false)
		return false;

	if (left->data == right->data){
		left = left->next;
		return true;
	}
	else 
		return false;
}
bool isPalindrome(node* root)
{
	return isPalindromeUtil(root, root);
}
node* push(node* root, int data)
{
	node* temp = new node();
	temp->data = data;
	temp->next = root;
	root = temp;
	return root;
}
void print(node* root)
{
	node* temp = root;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	node* root = NULL;
	root = push(root, 10);
	root = push(root, 15);
	root = push(root, 12);
	root = push(root, 12);
	root = push(root, 15);
	root = push(root, 13);
	print(root);
	cout << isPalindrome(root) << endl;
}
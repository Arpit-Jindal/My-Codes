#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	//Constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};
void InsertAtEnd(node* &root, int x) {
	node* temp = new node(x);
	if (root == NULL)
		root = temp;
	else {
		node* p = root;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
	}
}
void Print(node* root) {
	if (root == NULL) {
		return;
	}
	while (root != NULL) {
		cout << root->data << "->";
		root = root->next;
	} cout<<endl;
}

int middle(node* head)
{
	if (head == NULL)
		return -1;
	node*p = head;
	while (p->next != NULL && p->next->next != NULL )
	{
		head = head->next;
		p = p->next->next;
	}
	return head->data;
}

int main()
{
	node* head = NULL;
	for (int i = 1; i <= 7; i++)
		InsertAtEnd(head, i);
	Print(head);
	cout << middle(head);

}
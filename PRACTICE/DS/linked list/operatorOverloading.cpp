#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int d)
	{
		data = d;
		next = NULL;
	}
};
void insertAtTail(node* &head, int d)
{
	node* temp = new node(d);
	if (head == NULL)
		head = temp;
	else
	{
		node* root = head;
		while (root->next != NULL)
			root = root->next;
		root->next = temp;
	}
}
void buildList(node* &head)
{
	int n;
	cin >> n;
	while (n != -1)
	{
		insertAtTail(head, n);
		cin >> n;
	}
}
void print(node* head)
{
	while (head != NULL)
	{
		cout << head->data << "->";
		head = head ->next;
	}
}
istream& operator >>(istream& is, node*&head)
{
	buildList(head);
	return is;
}
ostream& operator << (ostream& os, node*head)
{
	print(head);
	return os;
}
int main()
{
	node* head = NULL;
	node* head2 = NULL;
	cin >> head >> head2;
	cout << head << endl << head2;
}
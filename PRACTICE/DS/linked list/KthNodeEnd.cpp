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
int KthEnd(node*head, int k)
{
	node* fast = head;
	node* slow = head;
	while (k--)
		fast = fast->next;
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow->data;
}
int main()
{
	node* head = NULL;
	buildList(head);
	print(head);
	cout << endl << "Enter Kth node from end: ";
	int k;
	cin >> k;
	cout << KthEnd(head, k);
}
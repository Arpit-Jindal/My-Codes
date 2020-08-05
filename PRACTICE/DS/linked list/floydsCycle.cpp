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
bool detectCycle(node* head)
{
	node* fast = head;
	node* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			return true;
	}
	return false;
}
void cycleRemoval(node*&head)
{
	node* fast = head;
	node* slow = head;
	do
	{
		fast = fast->next->next;
		slow = slow->next;
	} while (fast != slow);
	slow = head;
	while (fast->next != slow->next)
	{
		fast = fast->next;
		slow = slow->next;
	}
	fast->next = NULL;
}
int main()
{
	node* head = NULL;
	buildList(head);
	print(head);
	cout << endl;
	head->next->next->next->next = head->next;
	if (detectCycle(head))
		cycleRemoval(head);
	print(head);
}
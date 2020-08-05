#include<iostream>
using namespace std;
struct node
{
	int data;
	node*next;
};
class List
{
	node* root = NULL;
public:
	void push(int x);
	void print();
};
void List::push(int x)
{
	node* temp = new node();
	temp->data = x;
	temp->next = NULL;
	if (root == NULL)
		root = temp;
	else if (x < root->data)
	{
		temp->next = root;
		root = temp;
	}
	else //insert AFTER
	{
		node* head = root;
		while (head->next != NULL && x > head->next->data)
			head = head->next;

		temp->next = head->next;
		head->next = temp;
	}
}
void List::print()
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
	List L;
	L.push(1);
	L.push(5);
	L.push(3);
	L.print();
}
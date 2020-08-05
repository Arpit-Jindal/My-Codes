#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

struct node
{
	int data;
	node* link;
};
node* head = NULL;

void Append();
void Display();

void Reverse()
{
	if (head == NULL)
		return;
	stack <node*> s;
	node *temp = head;
	while (temp != NULL)
	{
		s.push(temp);
		temp = temp->link;
	}
	temp = s.top();
	head = temp;
	s.pop();
	while (!s.empty())
	{
		temp->link = s.top();
		s.pop();
		temp = temp->link;
	}
	temp->link = NULL;
}

int main()
{
	Append(); Append(); Append(); Append();
	Reverse();
	Display();
}

void Append() {
	node* temp = new node();

	cout << "enter elements: ";
	cin >> temp->data;
	temp->link = NULL;

	if (head == NULL) head = temp;
	else
	{
		node* p = head;
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
}

void Display() {
	node*temp = head;
	if (temp == NULL) cout << "EMPTY LIST\n\n";
	else
	{
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp -> link;
		}
	}
}


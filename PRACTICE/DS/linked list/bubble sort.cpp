#include<iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

class List
{
public:
	node* root = NULL;
	void push(int x);
	void bsort();
	void print();
};

void List::push(int x)
{
	node* temp = new node();
	temp->data = x;
	temp->link = root;
	root = temp;

}
void List::print()
{
	node* temp = root;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}
void List::bsort()
{
	if (root == NULL) return;

	node* temp;
	node*temp1 = root;
	while (temp1 != NULL)
	{
		temp = root;
		while (temp->link != NULL)
		{
			if (temp->data > temp->link -> data)
			{
				int p = temp->data;
				temp->data = temp->link -> data;
				temp->link->data = p;
			}
			temp = temp->link;
		}
		temp1 = temp1->link;
	}
}
int main()
{
	List L;
	L.push(5); L.push(2); L.push(3); L.push(1);
	cout << "Before sorting: \n";
	L.print();
	cout << "After sorting: \n";
	L.bsort();
	L.print();
}
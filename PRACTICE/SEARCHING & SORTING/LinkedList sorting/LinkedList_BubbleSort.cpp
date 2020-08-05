#include <iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};
node* root = NULL;

node* getnewnode()
{
	int x;
	cin >> x;
	node* temp = new node();
	temp->data = x;
	temp->link = NULL;
	return temp;
}

void Insert()
{
	node* temp = getnewnode();
	temp->link = root;
	root = temp;
}

void Print()
{
	node* temp = root;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}

void bsort()
{
	if (root == NULL) return;

	node* temp1 = root;
	node* temp;
	while (temp1 != NULL)
	{
		temp = root;
		while (temp->link != NULL)
		{
			if (temp->data > temp->link->data)
				swap(temp->data, temp->link->data);

			temp = temp->link;
		}
		temp1 = temp1->link;
	}
}
node* bubble_sort_LinkedList_itr(node* head)
{
	if (head == NULL || head->next == NULL) return head;
	node* dummy = new node(-1);
	dummy->next = head;
	node* temp, *prevtemp;
	while (1) {
		bool ans = false;
		prevtemp = dummy;
		temp = dummy->next;
		while (temp->next)
		{
			if (temp->data > temp->next->data) {
				prevtemp->next = temp->next;
				temp->next = temp->next->next;
				prevtemp->next->next = temp;
				prevtemp = prevtemp->next;
				ans = true;
			}
			else {
				prevtemp = temp;
				temp = temp->next;
			}
		}
		if (!ans) break;
	}
	return dummy->next;
}

// void bsort()
// {
// 	if (root == NULL) return;

// 	node* temp;
// 	// node* last = NULL;
// 	int swapped;
// 	do
// 	{
// 		swapped=0;
// 		temp = root;
// 		while (temp->link != NULL) //while(temp->link!=last)
// 		{
// 			if (temp->data > temp->link->data)
// 			{
// 				int c = temp->data;
// 				temp->data = temp->link->data;
// 				temp->link->data = c;
// 				swapped = 1;
// 			}
// 			temp = temp->link;

// 		}
// 		// last = temp;
// 	}
// 	while (swapped);

// }

int main()
{
	int n;
	cout << "Enter no of elements in the linked list \n";
	cin >> n;
	cout << "Enter elements\n";
	for (int i = 0; i < n; i++) { Insert(); }
	cout << "Elements before sorting \n";
	Print();
	bsort();
	cout << "Elements after sorting \n";
	Print();
}
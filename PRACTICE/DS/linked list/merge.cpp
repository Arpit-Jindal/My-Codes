#include<iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

void push(node** head, int x)
{
	node*temp = new node();
	temp->data = x;
	temp->link = NULL;
	if (*head == NULL)
	{
		(*head) = temp;
	}
	else
	{
		node* p = *head;
		while (p->link != NULL) p = p->link;
		p->link = temp;
	}
}
node* merge(node* l1, node* l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	node* head = NULL;    // head of the list to return

	// find first element (can use dummy node to put this part inside of the loop)
	if (l1->val < l2->val) {
		head = l1;
		l1 = l1->next;
	} else {
		head = l2;
		l2 = l2->next;
	}

	node* p = head;     // pointer to form new list

	while (l1 && l2) {
		if (l1->val < l2->val) {
			p->next = l1;
			l1 = l1->next;
		} else {
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}

	// add the rest of the tail, done!
	if (l1) {
		p->next = l1;
	} else {
		p->next = l2;
	}

	return head;
}
node* sort(node* root)
{
	if (root == NULL) return root;

	node* temp;
	node* temp1 = root;
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
	return root;
}
void print(node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->link;
	}
	cout << endl;
}
int main()
{
	node* head1 = NULL;
	node* head2 = NULL;
	node* Merge = NULL;

	push(&head1, 2); push(&head1, 4);
	push(&head1, 6); push(&head1, 8);
	head1 = sort(head1);

	push(&head2, 1); push(&head2, 3);
	push(&head2, 4); push(&head2, 2);
	head2 = sort(head2);

	Merge = merge(head1, head2);
	print(head1);
	print(head2);
	print(Merge);

}
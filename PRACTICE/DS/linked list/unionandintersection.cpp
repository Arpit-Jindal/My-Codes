#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* link;
};

void push(struct node** head, int x)
{
	node*temp = new node();
	temp->data = x;
	temp->link = (*head);
	(*head) = temp;
}

bool ispresent(struct node* head, int data)
{
	while (head != NULL)
	{
		if (head->data == data)
			return true;
		head = head->link;
	}
	return false;
}

struct node* getunion(struct node* head1, struct node* head2)
{
	struct node* result = NULL;
	struct node* t1 = head1;
	struct node* t2 = head2;

	while (t1 != NULL)
	{
		push(&result, t1->data);
		t1 = t1->link;
	}

	while (t2 != NULL)
	{
		if (!ispresent(result, t2->data))
			push(&result, t2->data);

		t2 = t2->link;
	}
	return result;
}

struct node* getintersection(struct node* head1, struct node* head2)
{
	struct node* result = NULL;
	struct node* t1 = head1;
	while (t1 != NULL)
	{
		if (ispresent(head2, t1->data))
			push(&result, t1->data);
		
		t1 = t1->link;
	}
	return result;

}

void print(struct node* head)
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
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* intersection = NULL;
	struct node* unionn = NULL;

	push(&head1, 2);
	push(&head1, 4);
	push(&head1, 6);
	push(&head1, 8);


	push(&head2, 1);
	push(&head2, 3);
	push(&head2, 4);
	push(&head2, 2);

	unionn = getunion(head1, head2);
	intersection = getintersection(head1, head2);

	print(head1);
	print(head2);
	print(intersection);
	print(unionn);

}
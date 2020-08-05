#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
};

struct node* root = NULL;
int len;

struct node* getnewnode()
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	return temp;
}

int Length() {
	int count = 0;
	struct node* temp = root;
	while (temp != NULL) {
		count++;
		temp = temp->link;
	}
	return count;
}

void Append() {
	struct node* temp = getnewnode();

	if (root == NULL) root = temp;
	else
	{
		struct node* p = root;
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
}

void Add_at_beginning() {
	struct node* temp = getnewnode();
	temp->link = root;
	root = temp;
}

void Add_at_any_location() {

	int loc;
	printf("Enter location of new node: ");
	scanf("%d", &loc);
	if (loc == 1) Add_at_beginning();
	else if (loc > len) printf("INVALID LOCATION \n Currently %d nodes present\n", len);
	else
	{
		struct node* temp = getnewnode();
		struct node* p = root;
		int i = 1;
		while (i <= loc - 2)
		{
			p = p->link;
			i++;
		}

		temp ->link = p->link;
		p->link = temp;
	}
}
void Display() {
	if (root == NULL) printf("EMPTY LIST\n\n");
	else
	{
		struct node*temp = root;
		while (temp->link != NULL)
		{
			printf("%d -> ", temp->data );
			temp = temp -> link;
		}
		printf("%d ", temp->data );

	}
}
void Delete() {
	struct node* temp = root;
	int loc;

	printf("Enter location to delete: \n");
	scanf("%d", &loc);
	if (loc > len) printf("INVALID LOCATION \n\n");
	else if (loc == 1)
	{
		root = temp->link;
		free(temp);
	}
	else
	{
		int i = 1;
		while (i <= loc - 2)
		{
			temp = temp->link;
			i++;
		}
		struct node *q = temp->link;
		temp->link = q->link;
		free(q);
	}
}

void adjacent_swap()
{
	int loc;
	printf("Enter location to swap: ");
	scanf("%d", &loc);
	if (loc >= len || loc < 0) printf("INVALID LOCATION \n");
	else if (loc == 1)
	{
		struct node*q = root->link;
		root->link = q->link;
		q->link = root;
		root = q;
		Display();

	}

	else {
		struct node* temp, *p, *r;
		temp = root;
		int i = 1;
		while (i <= loc - 2)
		{
			temp = temp->link;
			i++;
		}
		p = temp->link;

		r = p->link;
		p->link = r->link;
		r->link = temp->link;
		temp->link = r;

		// temp->link=q->link;
		// q->link=r->link;
		// r->link=q;

		Display();
	}

}

int main()
{
	int choice;
	while (1)
	{
		printf("\n\nSINGLE LINKED LIST OPERATIONS\n\n");
		printf("1.Append\n");
		printf("2.Add at beginning\n");
		printf("3.Add at any location\n");
		printf("4.Length\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Node swap(Adjacent)\n");
		printf("15.Quit\n\n");

		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: Append();
			len = Length();

			break;
		case 2: Add_at_beginning();
			len = Length();

			break;
		case 3: Add_at_any_location();
			len = Length();

			break;
		case 4: len = Length();
			printf("length is: %d\n\n", len  );
			break;
		case 5: Display();
			break;
		case 6: Delete();
			len = Length();
			break;
		case 7: adjacent_swap();
			break;
		case 15: return 0;
		default: printf("INVALID INPUT\n\n");

		}
	}
}

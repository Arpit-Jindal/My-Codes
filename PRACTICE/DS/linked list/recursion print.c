#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* root = NULL;
void Append();
void print_forward(struct node* p)
{
	if (p == NULL)
	{
		printf("\n");
		return;
	}
	printf("%d ", p->data );
	print_forward(p->link);
}
void print_reverse(struct node* p)
{
	if (p == NULL)
	{
		return;
	}
	print_reverse(p->link);
	printf("%d ", p->data );
}
int main()
{
	Append(); Append(); Append(); Append();
	printf("\n");
	print_forward(root);
	print_reverse(root);
}

void Append() {
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	printf("Enter value: ");
	scanf("%d", &temp->data);
	temp->link = NULL;

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

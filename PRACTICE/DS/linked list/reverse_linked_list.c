#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* root = NULL;
void reverse_iterative()
{
	struct node *current = root, *prev = NULL, *next;
	while (current != NULL){
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	root = prev;
}
void reverse_recursion(struct node* p)
{
	if (p->link == NULL){
		root = p;
		return;
	}
	reverse_recursion(p->link);
	p->link->link = p;
	p->link = NULL;
}
void Display();
void Append();
int main()
{
	Append(); Append(); Append(); Append();
	Display();
	printf("\n");
	reverse_recursion(root);
	//reverseiterative();
	Display();
}
void Display() {
	struct node*temp = root;
	if (temp == NULL) 
		printf("EMPTY LIST\n\n");
	else
	{
		while (temp != NULL)
		{
			printf("%d  ", temp->data );
			temp = temp -> link;
		}
	}
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


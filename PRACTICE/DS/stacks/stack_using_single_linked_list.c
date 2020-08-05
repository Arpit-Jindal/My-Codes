#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node*top = NULL;
void Push() {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter element\n");
	scanf("%d", &temp->data);
	temp->link = top;
	top = temp;
}

void Pop() {
	if (top == NULL) printf("STACK UNDERFLOW\n");
	else
	{
		struct node* temp;
		temp = top;
		top = top->link;
		free(temp);
	}
}

//dont use in actual
void Traverse() {
	struct node* temp;
	if (top == NULL)printf("STACK UNDERFLOW\n");
	else
	{
		temp = top;
		while (temp != NULL)
		{
			printf("%d ", temp->data );
			temp = temp->link;
		}
	}
}

int main()
{
	int ch, ele;
	while (1) {
		printf("\nSTACK USING LINKED LIST\n\n");
		printf("1.Insert\n2.Delete\n3.Traverse\n4.EXIT\nEnter your choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1: Push();
			break;
		case 2: Pop();
			break;
		case 3: Traverse();
			break;
		case 4: exit(0);
		default: printf("\nWrong choice\n");
		}

	}
}

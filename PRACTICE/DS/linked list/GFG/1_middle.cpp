#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data  = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
		*head_ref = new_node;
	else
		(*tail_ref)->next = new_node;
	*tail_ref = new_node;
}
int getMiddle(Node *head)
{
	Node* slow = head, *fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}
int main()
{
	int T, i, n, l;
	cin >> T;
	while (T--) {
		struct Node *head = NULL,  *tail = NULL;
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			cin >> l;
			append(&head, &tail, l);
		}
		printf("%d", getMiddle(head));
	}
	return 0;
}
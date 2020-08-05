#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	//Constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};

//Insert at end
void InsertAtEnd(node* &root, int x) {
	node* temp = new node(x);
	if (root == NULL)
		root = temp;
	else {
		node* p = root;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
	}
}
//Insert at Begin
void InsertAtBegin(node* &root, int x) {
	node*temp = new node(x);
	temp->next = root;
	root = temp;
}

//Priority Insert
void PriorityInsert(node* &root, int x) {
	node* temp = new node(x);
	if (root == NULL)
		root = temp;
	else if (x < root->data) {
		temp->next = root;
		root = temp;
	} else { // insert after
		node* p = root;
		while (p->next != NULL && x > p->next->data)
			p = p->next;
		temp->next = p->next;
		p->next = temp;
	}
}
void Print(node* root) {
	if (root == NULL) {
		return;
	}
	while (root != NULL) {
		cout << root->data << "->";
		root = root->next;
	}
}
void print_recursion(node* root) {
	if (root == NULL)
		return;
	cout << root->data << "->";
	print_recursion(root->next);
}
void print_reverse_recursion(node* root) {
	if (root == NULL)
		return;
	print_reverse_recursion(root->next);
	cout << root->data << "->";
}
void reverse(node* &root) {
	node* prev = NULL;
	node* curr = root;
	node* Next = NULL;
	while (curr) {
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next;
	}
	root = prev;
}
void reverse_recursion(node* &root, node* temp) {
	if (temp->next == NULL) {
		root = temp;
		return;
	}
	reverse_recursion(root, temp->next);
	node* q = temp->next;
	q->next = temp;
	temp->next = NULL;
}
bool isPresent(node* root, int x) {
	while (root != NULL) {
		if (root->data == x)
			return true;
		root = root->next;
	}
	return false;
}
node* Intersection(node* root1, node* root2) {
	node* result = NULL;
	node* t1 = root1;
	while (t1 != NULL) {
		if (isPresent(root2, t1->data))
			InsertAtEnd(result, t1->data);
		t1 = t1->next;
	}
	return result;
}
node* Union(node* root1, node* root2) {
	node* result = NULL;
	node* t1 = root1;
	node* t2 = root2;
	while (t1 != NULL) {
		InsertAtEnd(result, t1->data);
		t1 = t1->next;
	}
	while (t2 != NULL) {
		if (!isPresent(root1, t2->data))
			InsertAtEnd(result, t2->data);
		t2 = t2->next;
	}
	return result;
}
int length(node* root) {
	int i = 0;
	while (root != NULL) {
		i++;
		root = root->next;
	}
	return i;
}
int middle(node* root){
	if(root == NULL)
		return -1;
	node* p = root;
	while(p->next!=NULL && p->next->next != NULL){
		root = root->next;
		p = p->next->next;
	}
	return root->data;
}

int main()
{
	node* root1 = NULL, *root2 = NULL;
	PriorityInsert(root1, 2);
	PriorityInsert(root1, 4);
	PriorityInsert(root1, 7);
	PriorityInsert(root1, 1);
	PriorityInsert(root1, 3);
	PriorityInsert(root1, 9);

	PriorityInsert(root2, 2);
	PriorityInsert(root2, 1);
	PriorityInsert(root2, 6);
	PriorityInsert(root2, 5);
	PriorityInsert(root2, 9);

	node* intersect = Intersection(root1, root2);
	node* unionn = Union(root1, root2);

	Print(unionn);

}
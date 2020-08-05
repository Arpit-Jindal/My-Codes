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
int getcount(node* root) {
	int i = 0;
	while (root != NULL) {
		i++;
		root = root->next;
	}
	return i;
}
node* getIntersectionPoint(node* A, node*B) {
	if (A == NULL || B == NULL)
		return NULL;
	node* root1 = A;
	node* root2 = B;

	int count1 = getcount(root1);
	int count2 = getcount(root2);
	int d = count1 - count2;
	if (d < 0) { //swap if A is smaller
		node* temp = root1;
		root1 = root2;
		root2 = temp;
		d = count2 - count1;
	}
	//A is always bigger now
	for (int i = 1; i <= d; i++) {
		root1 = root1->next;
	}
	while (root1 != NULL && root2 != NULL) {
		if (root1 == root2) {
			return root1;
		}
		root1 = root1->next;
		root2 = root2->next;
	}
	return NULL;
}
int main()
{

}
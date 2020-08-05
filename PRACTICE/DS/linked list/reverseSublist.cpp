#include<iostream>
using namespace std;
node* reverse(node* root) {
	node* prev = NULL;
	node* curr = root;
	node* Next = NULL;
	while (curr) {
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next;
	}
	return prev;
}
node* reverseBetween(node* A, int B, int C) {
	if (B == C)
		return A;

	node* revs = NULL;
	node* revs_prev = NULL;
	node* revend = NULL;
	node* revend_next = NULL;
	node* curr = A;
	int i = 1;

	while (curr != NULL && i <= C) {
		if (i < B) {
			revs_prev = curr;
		} else if (i == B) {
			revs = curr;
		} else if (i == C) {
			revend = curr;
			revend_next = curr->next;
		}
		curr = curr->next;
		i++;
	}
	revend->next = NULL;
	revend = reverse(revs);

	if (revs_prev != NULL) {
		revs_prev->next = revend;
	} else {
		A = revend;
	}
	revs->next = revend_next;
	return A;
}
int main()
{

}
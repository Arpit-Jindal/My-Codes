#include<iostream>
using namespace std;
node* reverseInGroupsOfK(node* root, int K) {
	node* prev = NULL;
	node* curr = root;
	node* Next = NULL;
	int c = 0;
	while (curr && c < ) {
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next;
		c++;
	}

	if (Next != NULL)
		root->next = reverseList(Next, K);

	return prev;
}
int main()
{

}
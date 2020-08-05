#include<iostream>
using namespace std;
ListNode* Solution::partition(ListNode* A, int x) {
	if (A == NULL || A->next == NULL) {
		return A;
	}
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* p1 = NULL;
	ListNode* p2 = NULL;
	while (A) {
		ListNode* temp = new ListNode(A->val);
		if (A->val < x) {
			if (head1 == NULL) {
				p1 = temp;
				head1 = temp;
			} else {
				p1->next = temp;
				p1 = temp;
			}
		} else {
			if (head2 == NULL) {
				p2 = temp;
				head2 = temp;
			} else {
				p2->next = temp;
				p2 = temp;
			}
		}
		A = A->next;
	}
	if (head1 == NULL)
		return head2;
	p1->next = head2;
	return head1;
}
int main()
{

}
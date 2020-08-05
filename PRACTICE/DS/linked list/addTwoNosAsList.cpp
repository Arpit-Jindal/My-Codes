#include<iostream>
using namespace std;
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
	if (A == NULL)
		return B;
	if (B == NULL)
		return A;

	ListNode* head1 = A;
	ListNode* head2 = B;
	ListNode* result = NULL; //to return
	ListNode* ans = NULL;
	int c = 0; int a = 0;
	while (head1 && head2) {
		c = head1->val + head2->val + c;
		a = c % 10;
		c = c / 10;
		ListNode* temp = new ListNode(a);
		if (result == NULL) {
			ans = temp;
			result = ans;
		} else {
			ans->next = temp;
			ans = temp;
		}

		head2 = head2->next;
		head1 = head1->next;
	}
	if (head1) {
		while (head1) {
			c = head1->val + c;
			a = c % 10;
			c = c / 10;
			ListNode* temp = new ListNode(a);
			ans->next = temp;
			ans = temp;
			head1 = head1->next;
		}
	}
	if (head2) {
		while (head2) {
			c = head2->val + c;
			a = c % 10;
			c = c / 10;
			ListNode* temp = new ListNode(a);
			ans->next = temp;
			ans = temp;
			head2 = head2->next;
		}
	}
	if (c == 1) {
		ListNode* temp = new ListNode(c);
		ans->next = temp;
		ans = temp;
	}
	return result;

}

int main()
{

}
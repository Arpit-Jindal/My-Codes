#include<bits/stdc++.h>
using namespace std;
class mycomp {
public:
	bool operator()(pair<int, int>p1, pair<int, int>p2) {
		return p1.first > p2.first;
	}
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> pq;
	int k = A.size();
	for (int i = 0; i < k; i++) {
		pq.push(make_pair(A[i]->val, i));
	}
	ListNode* root = NULL;
	ListNode* temp = NULL;
	while (pq.top().first != INT_MAX) {
		pair<int, int> n = pq.top();
		if (root == NULL) {
			root = new ListNode(n.first);
			temp = root;
		} else {
			temp->next = new ListNode(n.first);
			temp = temp->next;
		}
		int x = n.second;
		pq.pop();
		A[x] = A[x]->next;
		if (A[x] == NULL)pq.push(make_pair(INT_MAX, INT_MAX));
		else pq.push(make_pair(A[x]->val, x));
	}
	return root;
}
//OR---->
class mycomp {
public:
	bool operator()(ListNode* l1, ListNode* l2) {
		return l1->val > l2->val;
	}
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
	priority_queue<ListNode*, vector<ListNode*>, mycomp> pq;
	int k = A.size();
	for (int i = 0; i < k; i++)
		pq.push(A[i]);

	ListNode* root = NULL;
	ListNode* temp = NULL;
	while (!pq.empty()) {
		ListNode* t = pq.top(); pq.pop();
		if (t->next) pq.push(t->next);
		if (root == NULL) root = t;
		else temp->next = t;
		temp = t;
	}
	return root;
}
int main()
{

}
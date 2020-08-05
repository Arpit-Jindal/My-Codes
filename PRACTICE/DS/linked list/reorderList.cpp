#include<iostream>
using namespace std;
ListNode* middle(ListNode* root){
    if(root == NULL)
        return NULL;
    ListNode* p = root;
    while(p->next!=NULL && p->next->next != NULL){
        root = root->next;
        p = p->next->next;
    }
    return root;
}
ListNode* reverse(ListNode* root) {
    ListNode* prev = NULL;
    ListNode* curr = root;
    ListNode* Next = NULL;
    while (curr) {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}
ListNode* Solution::reorderList(ListNode* A) {
    if(A==NULL || A->next == NULL){
        return A;
    }
    ListNode* mid = middle(A);
    ListNode* start2 = mid->next;
    mid->next = NULL;
    ListNode* start1 = A;
    start2 = reverse(start2);
    ListNode* c1 = start1;
    ListNode* c2 = start2;
    ListNode* n1 = NULL;
    ListNode* n2 = NULL;
    while(c1!=NULL && c2!=NULL){
        n1 = c1->next;
        n2 = c2->next;
        c1->next = c2;
        c2->next = n1;
        c1 = n1;
        c2 = n2;
    }
    return start1;
}
int main()
{
		
}
#include<iostream>
using namespace std;
int length(ListNode* root) {
    int i = 0;
    while (root != NULL) {
        i++;
        root = root->next;
    }
    return i;
}
ListNode* Solution::rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next == NULL || k%length(head) == 0){
        return head;
    }
    k = k%length(head);
    ListNode* fast = head;
    ListNode* slow = head;
    while(k--){
        fast = fast->next;
    }
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* newhead = slow->next;
    slow->next = NULL;
    fast->next = head;
    return newhead;
}
int main()
{
		
}
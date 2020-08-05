 int length(ListNode* root) {
    int i = 0;
    while (root != NULL) {
        i++;
        root = root->next;
    }
    return i;
}
ListNode* Solution::removeNthFromEnd(ListNode* head, int k) {
    if(head == NULL)
        return head;
    if(k>=length(head)){
        head = head->next;
        return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while(k--)
        fast = fast->next;
    while(fast->next!=NULL){
        fast = fast->next;
        slow= slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
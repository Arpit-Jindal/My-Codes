ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL){
        return A;
    }
    ListNode* result = NULL; //to return
    ListNode* head = NULL; //to traverse
    
    while(A->next){
        if(A->val != A->next->val){
            ListNode* temp = new ListNode(A->val);
            if(result==NULL){
                head = temp;
                result = temp;
            }
            head->next = temp;
            head = temp;
        }
        A=A->next;
    }
    if(head == NULL){
         ListNode* temp = new ListNode(A->val);
         head = temp;
         result = temp;
    }
    if(head->val!=A->val){
        ListNode* temp = new ListNode(A->val);
        head->next = temp;
        head = temp;
    }
    return result;
}
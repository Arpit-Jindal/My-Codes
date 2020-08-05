ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL){
        return A;
    }
    ListNode* result = NULL;
    ListNode* head = NULL;
    ListNode* p = NULL;
    while(A->next){
        if(A->val == A->next->val){
            p=A;
            A = A->next;
        }else if(p == NULL || p->val!=A->val){
            ListNode* temp = new ListNode(A->val);
            if(result==NULL){
                head = temp;
                result = head;
            }else{
                head->next = temp;
                head = temp;
            }
            p=A;
            A=A->next;
        }else if(p->val == A->val){
            p=A;
            A = A->next;
        }
    }
    
    if(result && p->val!=A->val){
        ListNode* temp = new ListNode(A->val);
        head->next = temp;
        head = temp;
    }
    
    return result;
}
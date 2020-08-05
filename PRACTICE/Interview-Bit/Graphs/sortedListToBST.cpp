int getLength(ListNode* A) {
    int count = 0;
    ListNode* root = A;
    while (root) {
        count++;
        root = root->next;
    }
    return count;
}
TreeNode* constructBST(ListNode* &head, int n) {
    if (n <= 0) return NULL;
    TreeNode* leftTree = constructBST(head, n / 2);
    TreeNode* root = new TreeNode(head->val);
    root->left = leftTree;
    head = head->next;
    root->right = constructBST(head, n - n / 2 - 1);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if (A == NULL) return NULL;
    int n = getLength(A);
    return constructBST(A, n);
}
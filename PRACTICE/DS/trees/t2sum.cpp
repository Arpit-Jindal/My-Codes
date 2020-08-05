int Solution::t2Sum(TreeNode * root, int k) {
    stack<TreeNode*> S2;
    stack<TreeNode*> S1;
    TreeNode* root1 = root;
    TreeNode* root2 = root;
    bool done1 = false, done2 = false;
    int val1 = 0, val2 = 0;
    while (1) {
        if (done1 == false) {
            while (root1) {
                S1.push(root1);
                root1 = root1->left;
            }
            root1 = S1.top(); S1.pop();
            val1 = root1->val;
            root1 = root1->right;
            done1 = true;
        }
        if (done2 == false) {
            while (root2) {
                S2.push(root2);
                root2 = root2->right;
            }
            root2 = S2.top(); S2.pop();
            val2 = root2->val;
            root2 = root2->left;
            done2 = true;
        }
        if (val1 >= val2) return 0;
        if (val1 + val2 == k) return 1;
        if (val1 + val2 < k) done1 = false;
        if (val1 + val2 > k) done2 = false;
    }
}
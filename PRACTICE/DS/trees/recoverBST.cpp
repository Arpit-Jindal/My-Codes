vector<int> Solution::recoverTree(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> ans;
    int curr, prev = NULL, first = NULL, middle = NULL, last = NULL;
    int count = 1;
    while (root || !s.empty()) {
        while (root) {
            s.push(root);
            root = root->left;
        }
        root = s.top(); s.pop();
        curr = root->val;
        if (prev && prev > curr && count == 1) {
            first = prev;
            middle = curr;
            count++;
        }
        if (prev && prev > curr && count == 2) {
            last = curr;
        }
        prev = curr;
        root = root->right;
    }
    (last != NULL) ? ans.push_back(last) : ans.push_back(middle);
    ans.push_back(first);
    return ans;
}
//-------------------------------------ORRRRRRRRR---------------------------------
void inorder(TreeNode* root, int& first, int& middle, int& last, int& prev) {
    if (root == NULL)
        return ;
    inorder(root->left, first, middle, last, prev);
    if (prev && root->val < prev) {
        if (!first) {
            first = prev;
            middle = root->val;
        }
        else {
            last = root->val;
        }
    }
    prev = root->val;
    inorder(root->right, first, middle, last, prev);
}
vector<int> Solution::recoverTree(TreeNode* root) {
    int prev = NULL, first = NULL, middle = NULL, last = NULL;
    inorder(root, first, middle, last, prev);
    vector<int> ans;
    (last != NULL) ? ans.push_back(last) : ans.push_back(middle);
    ans.push_back(first);
    return ans;
}

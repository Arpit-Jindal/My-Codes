class item {
public:
    TreeNode* node;
    int depth;
};
int Solution::minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    queue<item> q;
    item x = {root , 1};
    q.push(x);
    while (!q.empty()) {
        x = q.front(); q.pop();
        TreeNode* temp = x.node;
        int d = x.depth;
        if (temp->left == NULL && temp->right == NULL)
            return d;
        if (temp->left) {
            x.node = temp->left;
            x.depth = d + 1;
            q.push(x);
        }
        if (temp->right) {
            x.node = temp->right;
            x.depth = d + 1;
            q.push(x);
        }
    }

}
void recur(TreeNode* root, vector<int> v, int &sum) {
    if (!root) return;
    v.push_back(root->val);

    if (root->left == NULL && root->right == NULL) {
        int num = 0;

        for (int i = 0; i < v.size(); i++)
            num = (num * 10 + v[i]) % 1003;

        sum = (sum + (num % 1003)) % 1003;
    }
    else {
        recur(root->left, v, sum);
        recur(root->right, v, sum);
    }
}
int Solution::sumNumbers(TreeNode* root) {
    vector<int> v;
    int sum = 0;
    recur(root, v, sum);
    return sum;
}
//----------------------------------------------------OR--------------------------------------------------------------------
int treePathsSumUtil(TreeNode *root, int val)  
{  
    // Base case  
    if (root == NULL) return 0;  
  
    // Update val  
    val = (val*10 + root->val)%1003;  
  
    // if current node is leaf, return the current value of val  
    if (root->left==NULL && root->right==NULL)  
    return val;  
  
    // recur sum of values for left and right subtree  
    return (treePathsSumUtil(root->left, val) +  treePathsSumUtil(root->right, val))%1003;  
}  
int Solution::sumNumbers(TreeNode* root) {
    return treePathsSumUtil(root, 0); 
}

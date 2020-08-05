TreeNode* Solution::invertTree(TreeNode* root) {
	if (root == NULL)
		return root;
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	root->left = invertTree(root->left);
	root->right = invertTree(root->right);
	return root;
}

int isMirror(TreeNode* a, TreeNode* b) {
	if (a == NULL && b == NULL)
		return 1;
	if (a && b && (a->val == b->val))
		return isMirror(a->left, b->right) && isMirror(a->right, b->left);
	return 0;
}
int Solution::isSymmetric(TreeNode* root) {
	return isMirror(root, root);
}
//BST to sorted LL
class LL {
public:
    TreeNode* head, tail;
}
LL flattenBST(TreeNode* root) {
    LL l;
    if (root == NULL) {
        l.head = l.tail = NULL;
        return l;
    }

    //1.Leaf TreeNode
    if (root->left == NULL && root->right == NULL)  {
        l.head = l.tail = root;
        return l;
    }

    //2. left not null
    if (root->left != NULL && root->right == NULL) {
        LL leftLL = flattenBST(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;

        return l;
    }
    //3. right not NULL
    if (root->left == NULL && root->right != NULL) {
        LL rightLL = flattenBST(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    //4.Both sides are not null
    LL leftLL = flattenBST(root->left);
    LL rightLL = flattenBST(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;

}

//binary tree to LL (preorder)
TreeNode* Solution::flatten(TreeNode* root) {
    if (root == NULL) return NULL;

    else if (root->left == NULL && root->right == NULL) return root;

    else if (root->left == NULL && root->right != NULL) {
        TreeNode* r = flatten(root->right);
        return root;
    }

    else if (root->left != NULL && root->right == NULL) {
        TreeNode* l = flatten(root->left);
        root->right = l;
        root->left = NULL;
        return root;
    }

    else {
        TreeNode* l = flatten(root->left);
        TreeNode* r = flatten(root->right);
        TreeNode* temp = l;
        while (temp->right)temp = temp->right;
        temp->right = r;
        root->right = l;
        root->left = NULL;
        return root;
    }
}
//short
TreeNode* Solution::flatten(TreeNode* root) {
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) return root;
    TreeNode* l = flatten(root->left);
    TreeNode* r = flatten(root->right);
    if (l) {
        TreeNode* temp = l;
        while (temp->right)temp = temp->right;
        temp->right = r;
        root->right = l;
    }
    else root->right = r;

    root->left = NULL;
    return root;
}
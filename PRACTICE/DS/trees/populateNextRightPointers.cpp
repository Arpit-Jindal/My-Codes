TreeLinkNode* getnext(TreeLinkNode* temp) {
    temp = temp->next;
    while (temp) {
        if (temp->left)
            return temp->left;
        if (temp->right)
            return temp->right;
        temp = temp->next;
    }
    return NULL;
}
void Solution::connect(TreeLinkNode* root) {
    if (root == NULL)
        return;
    TreeLinkNode* temp;
    while (root) {
        temp = root;
        while (temp) {
            if (temp->left) {
                if (temp->right)
                    temp->left->next = temp->right;
                else
                    temp->left->next = getnext(temp);
            }
            if (temp->right)
                temp->right->next = getnext(temp);
            temp = temp->next;
        }
        if (root->left)
            root = root->left;
        else if (root->right)
            root = root->right;
        else
            root = root->next;
    }
}


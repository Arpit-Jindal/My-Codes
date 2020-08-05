#include<bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void helper(node* root, map<int, vector<int>> &m, int hd) {
    if (root == NULL) return;
    m[hd].push_back(root->data);
    helper(root->left, m, hd - 1);
    helper(root->right, m, hd + 1);

}
//Preorder
void verticalOrderTraversal(node* root) {
    vector<vector<int>> ans;

    map<int, vector<int>> m;
    helper(root, m, 0);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << "\t: ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}
//Level Order Traversal
void verticalOrderTraversalLO(node* root) {
    map<int, vector<int>> m;
    queue< pair<node*, int> > q;
    int hd = 0;
    q.push(make_pair(root, hd));

    while (!q.empty()) {
        pair<node*, int> temp = q.front(); q.pop();
        hd = temp.second;
        node* node = temp.first;
        m[hd].push_back(node->data);
        if (node->left != NULL)
            q.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            q.push(make_pair(node->right, hd + 1));
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << "\t: ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);
    verticalOrderTraversalLO(root);
}
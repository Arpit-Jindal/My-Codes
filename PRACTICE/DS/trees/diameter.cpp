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
int height(node* root, int& ans)
{
	if (root == NULL) return 0;
	int left_height = height(root->left, ans);
	int right_height = height(root->right, ans);

	ans = max(ans, 1 + left_height + right_height);

	return 1 + max(left_height, right_height);
}
int diameter(node* root)
{
	if (root == NULL) return 0;
	int ans = INT_MIN;
	int ht = height(root, ans);
	return ans;
}
int main()
{

}
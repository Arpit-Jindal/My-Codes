/*RISHABH CHANDRA. AVL tree implementation.*/
#include<iostream>
#define COUNT 5
using namespace std;
struct node
{
	int key;
	node* left;
	node* right;
	int ht;
};
void print2DUtil(node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("(%d,%d)\n", root->key, root->ht);
    print2DUtil(root->left, space);
}
class AVL{
	node* ROOT;
public:
	friend void print2DUtil();
	void print2D()
	{
	   cout<<"----------------------------------------------------";
	   print2DUtil(ROOT, 1);
	   cout<<"----------------------------------------------------";
	}
	int height(node* x)
	{
		if(x==NULL) return 0;
		return x->ht;
	}
	node* rotateright(node* u)
	{
		node* v = u->left;
		node* t2 = v->right;
		u->left = t2;
		v->right = u;
		u->ht = max(height(u->left),height(u->right)) + 1; //first u and then v
		v->ht = max(height(v->left),height(v->right)) + 1;
		return v;
	}
	node* rotateleft(node* v)
	{
		node* u = v->right;
		node* t2 = u->left;

		v->right = t2;
		u->left = v;

		v->ht = max(height(v->left),height(v->right)) + 1;
		u->ht = max(height(u->left), height(u->right)) + 1;

		return u;
	}
	int balancefactor(node* t)
	{
		if(t==NULL) return 0;
		else return (height(t->left) - height(t->right));
	}
	node* insert(node* root, int data)
	{
		if(root==NULL)
		{
			node* newNode = new node;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->ht = 1;
			newNode->key = data;
			return newNode;
		}
		if(data < root->key)
			root->left = insert(root->left,data);
		else if(data > root->key)
			root->right = insert(root->right,data);
		else return root;

		root->ht = 1+ max(height(root->left),height(root->right));

		if(balancefactor(root) > 1 && data < root->left->key)
			return rotateright(root);
		else if(balancefactor(root) < -1 && data > root->right->key)
			return rotateleft(root);
		else if(balancefactor(root) > 1 && data > root->left->key)
		{
			root->left = rotateleft(root->left);
			return rotateright(root);
		}
		else if(balancefactor(root) < -1 && data < root->right->key)
		{
			root->right = rotateright(root->right);
			return rotateleft(root);
		}
		return root;
	}
	void add(int k)
	{
		ROOT = insert(ROOT,k);
	}
	node* delfunc(node* root, int data)
	{
		if(root==NULL) return root;
		if(root->key > data) root->left = delfunc(root->left,data);
		else if(root->key < data) root->right = delfunc(root->right,data);
		else
		{
			if(root->left==NULL || root->right==NULL)
			{
				node* temp = root->left?root->left:root->right;
				if(temp==NULL)
				{
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;
				delete(temp);
			}
			else
			{
				node* temp = root->right;
				while(temp->left!=NULL)
					temp=temp->left;
				root->key = temp->key;
				root->right = delfunc(root->right,temp->key);
			}
		}
		if(root==NULL) return root;
		root->ht = 1+max(height(root->left),height(root->right));
		if(balancefactor(root) > 1 && balancefactor(root->left)>0)
			return rotateright(root);
		else if(balancefactor(root) > 1 && balancefactor(root->left)<=0)
		{
			root->left = rotateleft(root->left);
			return rotateright(root);
		}
		else if(balancefactor(root) < -1 && balancefactor(root->right)<0)
			return rotateleft(root);
		else if(balancefactor(root) < -1 && balancefactor(root->right)>=0)
		{
			root->right = rotateright(root->right);
			return rotateleft(root);
		}
		return root;
	}
	void remove(int k)
	{
		ROOT = delfunc(ROOT,k);
	}
};
int main()
{
	AVL tree;
	while(true)
	{
		int o,t;
		cin>>o>>t;
		if(o==-1) break;
		o==0?tree.add(t):tree.remove(t);
		tree.print2D();
	}
}

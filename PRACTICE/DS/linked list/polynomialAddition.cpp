#include<iostream>
using namespace std;
struct node
{
    int coeff;
    int power;
    node* next;
};
node* Insert(node* root, int c, int p)
{
    node* temp = new node();
    temp->coeff = c;
    temp->power = p;
    temp->next = NULL;
    if (root == NULL)
        root = temp;
    else if (root->power < p)
    {
        temp->next = root;
        root = temp;
    }
    else if (root->power == p)
        root->coeff = root->coeff + c;
    else
    {
        node* x = root;
        while (x->next != NULL && x->next->power > p)
            x = x->next;
        if (x->next != NULL && x->next->power == p)
        {
            x = x->next;
            x->coeff = x->coeff + c;
        }
        else
        {
            temp->next = x->next;
            x -> next = temp;
        }
    }
    return root;
}
void print(node* root)
{
    while (root->next != NULL)
    {
        cout << root->coeff << "x^" << root->power << " + ";
        root = root->next;
    }
    cout << root->coeff << "x^" << root->power << endl;
}
node* add(node* root1, node* root2)
{
    node* poly = NULL;
    while (root1)
    {
        poly = Insert(poly, root1->coeff, root1->power);
        root1 = root1->next;
    }
    while (root2)
    {
        poly = Insert(poly, root2->coeff, root2->power);
        root2 = root2->next;
    }
    return poly;
}
int main()
{
    node* root1 = NULL;
    node* root2 = NULL;
    root1 = Insert(root1, 7, 0);
    root1 = Insert(root1, 6, 1);
    root1 = Insert(root1, 5, 1);
    root1 = Insert(root1, 10, 3);
    root1 = Insert(root1, 4, 2);

    root2 = Insert(root2, 4, 4);
    root2 = Insert(root2, 3, 2);
    root2 = Insert(root2, 5, 1);
    print(root1);
    print(root2);
    node* poly = add(root1, root2);
    print(poly);
}
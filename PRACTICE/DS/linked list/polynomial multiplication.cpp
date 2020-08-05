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
node* multiply(node* root1, node* root2)
{
    node* poly = NULL;
    while (root1)
    {
        node* temp = root2;
        while (temp)
        {
            poly = Insert(poly, root1->coeff * temp->coeff, root1->power + temp->power);
            temp = temp->next;
        }
        root1 = root1->next;
    }
    return poly;
}
int main()
{
    node* root1 = NULL;
    node* root2 = NULL;
    root1 = Insert(root1, 7, 0);
    root1 = Insert(root1, 6, 1);
    root1 = Insert(root1, 4, 2);

    root2 = Insert(root2, 3, 2);
    root2 = Insert(root2, 5, 1);
    print(root1);
    print(root2);
    node* poly = multiply(root1, root2);
    print(poly);
}
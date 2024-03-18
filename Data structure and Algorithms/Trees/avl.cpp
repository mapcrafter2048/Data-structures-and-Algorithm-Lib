#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(node *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    else
    {
        return 1 + max(height(root->left), height(root->right));
    }
}

int getbalancedfactor(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return (height(root->left) - height(root->right));
    }
}

node *rightrotate(node *root)
{
    node *x = root->left;
    node *t2 = x->right;

    x->right = root;
    root->left = t2;
    return x;
}

node *leftrotate(node *root)
{
    node *x = root->right;
    node *t2 = x->left;

    x->left = root;
    root->right = t2;

    return x;
}

node *insert(node *root, int value)
{
    if (root == nullptr)
    {
        return new node(value);
    }
    else if (value <= root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
    }
    int bf = getbalancedfactor(root);
    if (bf > 1)
    {
        if (value < root->left->data)
        {
            return rightrotate(root);
        }
        else
        {
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }
    }
    if (bf < -1)
    {
        if (value > root->right->data)
        {
            return leftrotate(root);
        }
        else
        {
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }
    }
    return root;
}

int main()
{
    // Create an AVL tree and perform insertions if needed

    return 0;
}

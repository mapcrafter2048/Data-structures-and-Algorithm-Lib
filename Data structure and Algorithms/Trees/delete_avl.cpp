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

int getbalancedfactr(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return height(root->left) - height(root->right);
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

    x->right = root;
    root->left = t2;

    return x;
}

node *getsuccessor(node *root)
{
    node *curr = root;
    curr = curr->right;
    while (curr != nullptr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node *deletion(node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (key < root->data)
    {
        root->left = deletion(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletion(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            node *succ = getsuccessor(root);
            root->data = succ->data;
            root->right = deletion(root->right, succ->data);
        }
        return root;
    }
    int bf = getbalancedfactr(root);
    if (bf > 1)
    {
        if (getbalancedfactr(root->left) >= 0)
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
        if (getbalancedfactr(root->right) <= 0)
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

    return 0;
}
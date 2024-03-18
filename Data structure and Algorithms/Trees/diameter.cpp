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
        return 0;
    }
    else
    {
        return 1 + max(height(root->left), height(root->right));
    }
}

int diameter(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
}

/*
so here also we are doing that recursive approach first it will calculate its own height and then
if will recursively call for its right and left tree the same thing they will also calculate their
height and then will return the max of them. and it will return the max of its height it children
height recursively
*/

// #  second solution

int result = 0;

int heights(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = heights(root->left);
    int right = heights(root->right);

    result = max(result, left + right + 1);
    return 1 + max(left, right);
}

int main()
{

    return 0;
}
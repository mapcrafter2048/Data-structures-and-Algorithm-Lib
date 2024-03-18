#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>

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

node *floorInBST(node *root, int x)
{
    node *result = nullptr;
    while (root != nullptr)
    {
        if (root->data == x)
        {
            return root;
        }
        else if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            result = root;
            root = root->right;
        }
    }
    return root;
}

/*
    If the current node's value (root->data) is equal to x, 
    it means we have found an exact match, so we return the current node as the floor value.

    If the current node's value is greater than x, 
    it means that the floor value (if it exists) must be in the left subtree because 
    all values in the left subtree are smaller than the current node's value. So,
    we move to the left subtree by updating root = root->left.

    If the current node's value is less than x, it means the floor value could potentially 
    be the current node or a larger value in the right subtree. We update result to store 
    the current node's value because it's a candidate for the floor value, and then we move 
    to the right subtree by updating root = root->right.

    so here we can see that even if we move right to right to right when we will enconter the last
    node that is the floor that will value will be smaller that x hence we will automatically 
    trigger the last else condition and return the last node
*/

using namespace std;

int main()
{

    return 0;
}
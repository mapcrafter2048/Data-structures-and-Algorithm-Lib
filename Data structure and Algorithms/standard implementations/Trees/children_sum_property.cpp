#include <iostream>
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

bool issum(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->data;
    }
    if (root->right != NULL)
    {
        sum += root->right->data;
    }
    return (root->data == sum && issum(root->left) && issum(root->right));
}

/*
    # how does this thing works
    * so here we have to check that the root nodes is the sum of its children
    * so here we consider the leaf case to be true also as when a node is a leaf node it also return true 
    * and we have the base case to add the value of the root node left and right to sum and then check if it 
    * is true or not and then in the return statement we recursively call for the both the left and the 
    * right node and the control moves as in the case for other type of recursion
    * first the root node will be called as it is called it will recursively call its left and right 
    * subtree which will return either true or false and then the control will come back to the original
    * parent node 



*/

int main()
{

    return 0;
}
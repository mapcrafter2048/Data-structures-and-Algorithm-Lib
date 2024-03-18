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

/**
 * The function returns the successor node of a given node in a binary tree.
 * 
 * @param current A pointer to the current node in a binary tree.
 * 
 * @return a pointer to the successor node of the given node.
 */
node *getsuccessor(node *current)
{
    current = current->right;
    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

/**
 * The function `removenode` removes a node with a given key from a binary search tree.
 * 
 * @param root The root node of the binary search tree from which the node with the given key needs to
 * be removed.
 * @param key The key parameter represents the value of the node that needs to be removed from the
 * binary search tree.
 * 
 * @return a pointer to the root node of the modified binary search tree.
 */
node *removenode(node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }
    if (root->data > key)
    {
        root->left = removenode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = removenode(root->right, key);
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
            root->right = removenode(root->right, succ->data);
        }
        return root;
    }
}

/*
so now let us see how this works 
so as we see that we are recursively calling our function based on where we want to travel
and after we have reached the node we want to delete we will use the else condtion in our
function so what it does is that suppose we want to delete the node which only have the right node
not the left node so we will assign the right node temp and then we will delete our desired node 
and since this else is called by the recursion call above in which we assign the root-> right 
or root -> left node so that temp node gets connected 

one more thing the else condition is being satsifed because our intial both the two conditions will fail 
when the root -> data = key 

and also the smallest value to be replaced is the rightmost node in the left subtree of the root




*/

int main()
{

    return 0;
}
#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

/**
 * The function "getsize" calculates the size of a binary tree by recursively counting the number of
 * nodes in the tree.
 * 
 * @param root The root parameter is a pointer to the root node of a binary tree.
 * 
 * @return the size of the binary tree rooted at the given node.
 */
int getsize(node * root){
    if (root == nullptr)
    {
        return 0;
    }
    else{
        return (1 + getsize(root -> left) + getsize(root -> right));
    }
    
}

int main()
{

    return 0;

}
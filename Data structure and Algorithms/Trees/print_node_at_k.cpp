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
 * The function "print" recursively prints the values of nodes at a given distance "k" from the root
 * node in a binary tree.
 * 
 * @param root A pointer to the root node of a binary tree.
 * @param k The parameter "k" represents the distance from the root node. It determines how far away
 * from the root node we want to print the nodes.
 * 
 * @return void, which means it is not returning any value.
 */
void print(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    else
    {
        print(root->left, k - 1);
        print(root->right, k - 1);
    }
}

/*

            10
           /  \   
         20    30
        /  \    \
      40    50   70
                   \
                    80

    #Dry run of the above function:
    print(10, 2)
        |
        |-> print(20, 1)
        |    |
        |    |->print(40, 0)
        |    |->print(50, 0)
        |
        |->print(30, 1)
            |
            |->print(null, 0)
            |->print(70, 0)

    so here the code run bt the recursion as we call the function recursively.
    so as the function call is made, the value of k decreases by 1. and the function is called again
    and again each time decresing the value of k. and then as the value of k is 0, the function is execute 
    and then the value is printed

*/


int main()
{

    return 0;
}
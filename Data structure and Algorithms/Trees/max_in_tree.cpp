// find the max value in a tree using recursion

#include <iostream>
#include <climits>
#include <algorithm>
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

/*
    # node diagram

            20
           /  \   
         80    30
               / \
              40  50
    @note
    1. if the tree is empty, return INT_MIN
    2. if the tree is not empty, return the max of the data in the root node

    getmax(20)
            |-> getmax(80)
            |   |-> getmax(null)
            |   |-> getmax(null)   
            |
            |
            |-> getmax(30)
                |-> getmax(40)
                |    |-> getmax(null)
                |    |-> getmax(null)
                |
                |->getmax(50)
                    |->getmax(null)
                    |->getmax(null)
    % explaination of the code
    * so here we also recursively call the function on the left and right subtree
    * and here we can see as the function continus to run first for the root node 20 and 
    * then for 80 node and then for the null node of the 80 and and since the base condition 
    * is satisfied it will return -infinity to its parent node that is 80 and then the node 80
    * will perform the two max operation adn will retrun the value 80 to tis aprent node that is the root 
    * node of 20 and then the function will move the the 30 node which will also call the function for the 
    * 40 node recursively and then to its null node which will again satisfy it s base condtion and return
    * - infinty and then the 40 node will compute the 2 max operation and will return the value 40 to its parent
    * node that is 30 node same will happen for the 50 node and it will return the value 50 to its parent node
    * that is 30 and now 30 will perform its two max operation and will return 50 to its parent 
    * and then finally 20 will do its two max oepration and then retrun 80
*/

int getmax(node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    else
    {
        return max(root->data, max(getmax(root->left), getmax(root->right)));
    }
}

int main()
{

    return 0;
}
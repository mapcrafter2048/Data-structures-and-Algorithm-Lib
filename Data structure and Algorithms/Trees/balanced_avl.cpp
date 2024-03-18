#include <iostream>
#include <algorithm>
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

bool isbalanced(node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);

    return (abs(left_height - right_height) < 1 && isbalanced(root->left) && isbalanced(root->right));
}

int isbalanced2(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left_height = isbalanced2(root->left);
    if (left_height == -1)
    {
        return -1;
    }
    int right_height = isbalanced2(root->right);
    if (right_height == -1)
    {
        return -1;
    }
    if (abs(left_height - right_height) > 1)
    {
        return -1;
    }
    else
    {
        return max(left_height, right_height) + 1;
    }
}

/*
    # how the balanced2 function works 
    lets take a tree example to understand it 
           18
          /  \
        12   15
       / \    \
     13  14   16
                \
                17

    * so now lets see how the code will work for this as we can see that when the call 
    * is done for 18 it will recursively call for the left node unitl the 13 whose left nad right node are null
    * and will return 0 to tis parent which is 13 and then 13 will move foreward and will calculate the 1 + 
    * left_height and right_height of the node and then it will return the max of the two quantity ot its parent 
    * which is 12 and the same wil happen for the 14 node which will return 1 + left_height and right_height
    * to its parent node 12 
    * now if see for the right subtree case the function will call for 15 since its left is null so it 
    * return 0 then it will call for its right tree length which will then return 0 for its elft length 
    * anf then call for its right node which is 17 now since 17 is a left node it will return execute all the 
    * steps and then will return 1 to its parent which will now also complete all its steps and return 2 to its 
    * parent which is 15 now 15 will return 0 as it will disatify one of the condition  
     



*/

/*
    # how this thing works
    * so here we also have to deal with the bool condition so we have to recursively
    * call the function again in the return statement which holds three condition and if
    * either of these condition is false it retrun false to its parent or form where the
    * function call was initallized
*/

int main()
{

    return 0;
}
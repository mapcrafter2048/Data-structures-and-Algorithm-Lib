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

/*
            10
           /  \   
         08    30
              /  \
            40    50
    # so lets make the tree of how the implemetation works

    height(10)
            |
            |-> height(8)
            |   |-> height(null)
            |   |-> height(null)   
            |
            |-> height(30)
                |
                |-> height(40)
                |    |-> height(null)
                |    |-> height(null)
                |
                |->height(50)
                    |->height(null)
                    |->height(null)
    
    % Explaination of the code
        * so now height(10) is going to execute since this is a recursive function
        * so now the height(8) is going to be execute first as in the max function its argument is first
        * and now since node 8 has also 2 nodes of nullptr so both will be called recursively and will return 
        * 0 and 0 to their parent as they will satisfy the base case both so now the +1 part of the node 8
        * will be executed and will retrun 1 to tis parent that is the 10 node and now since 8 was the left node
        * of the tree os now it is executed completely and now the right node is going to be executed
        * and in the right sub tree the node 30 will be passed in the function and its calls the function but since 30
        * is itself a subtree it will itself call the node 40 and node 50 recursively and then after the node 40 is called it will
        * both the null nodes of the 40 will return 0 an 0 to its parent node 40 and tehn 40 will take the max of these and then add
        * 1 to it so it is going to return 1 to its parent now the parent that is the 30 node wil get its control
        * back and then it will call for the 50 same thing will happen for the 50 case and now since the execution
        * for the max function for the 30 node is completed it will add 1 to max that is 1 and then return 2 to its parent node that
        * is the 10 node and now since 10 node has comleted the max function executed it will add 1 to 2 and then finally return 3  

*/

int height(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return (max(height(root->left), height(root->right)) + 1);
    }
}

int main()
{

    return 0;
}
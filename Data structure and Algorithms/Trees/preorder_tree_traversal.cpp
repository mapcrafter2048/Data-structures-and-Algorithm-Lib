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

void inorder(node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
}

/*

    ? So we are going to work with this tree and them do the Traversal in it
            10
           /  \   
         20    30
              /  \
            40    50
    # so lets make the tree of how the implemetation works

    preorder(10)
            |->print(10)
            |
            |-> preorder(20)
            |   |-> print(20)
            |   |-> preorder(null)
            |   |-> preorder(null)   
            |
            |-> preorder(30)
                |
                |->print(30)
                |
                |-> preorder(40)
                |    |-> print(40)
                |    |-> preorder(null)
                |    |-> preorder(null)
                |
                |->preorder(50)
                    |->print(50)
                    |->preorder(null)
                    |->preorder(null)
    % Explaination for this code

    * so this thing works in the smae wasy as the inorder tree travesal but here the order fo the printing 
    * is changed so that the node gets printed first and then the left and right node is called
    * so now here we can see that as the 10 goes in the preorder function it exectues its first line of code
    * and that is printing the first line and then executing the second line which puts it int oa recursive loop and 
    * then it follows the same process unti a leaf noode is reached 
*/

int main()
{

    return 0;
}
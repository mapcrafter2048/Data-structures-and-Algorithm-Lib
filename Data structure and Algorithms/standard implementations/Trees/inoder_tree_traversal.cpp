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

/*
    void inorder(node *root)

    ? So we are going to work with this tree and them do the Traversal in it
            10
           /  \   
         20    30
              /  \
            40    50
    # so lets make the tree of how the implemetation works

    inorder(10)
            |-> inorder(20)
            |   |-> inorder(null)
            |   |-> print(20)
            |   |-> inorder(null)   
            |
            |->print(10)
            |
            |-> inorder(30)
                |-> inorder(40)
                |    |-> inorder(null)
                |    |-> print(40)
                |    |-> inorder(null)
                |
                |->print(30)
                |
                |->inorder(50)
                    |->inorder(null)
                    |->print(50)
                    |->inorder(null)
    
    % Explaination of the process
        * first we input 10 in the inorder function it check the condtion condtion is fullfilled so it call recursively
        * 20 as it is the left node of 20 now the function again starts from the top line for 20
        * we call the function "inorder" for the 20 again exection begins from the first line again the condtion is checked 
        * so the root is not null therefore it proceed now again it call the "inorder" function for the left node of 20 
        * again the condtion is checked which now turns out to be true and then if does not goess into the if condition
        * so it finishes and it gives the control back to the parent that it the inorder(20) function that is still running
        * so it executes the next line so it prints the data after this the next line of code is executed which is the running the
        * inorder function for the right of the 20 node which is null so the null is inputed into the inoder function 
        * and now since the condition is not satisfied so it does not execute the if statement below it so it gives the control 
        * back to the caller which is the inorder(20) and since the caller has done all the three line of it so now since the caller 
        * is also finished it gives control back to its caller that is the inorder(10) node now inorder(10) executes the print statement
        * therefore it print itself now it executes it 3 line of code and calls it right subtree os now it calls for 30 
        * that is inorder(30) is executed and now since inorder(30) is executed it now calls it left node so it now 
        * inorder for 40 is called and since it is the leaf node it gets executed like the same as the 10 leaf node 
        * then the inorder 30 executes its 2nd line that is print so it print it self and then it executes the 50 node which is 
        * also processed same as the 10 and 40 node 
    
    # important observations
        * when the all the lines of code for a recursively function is executed then only it gives control back to its 
        * parent node so this is where it loops 
        
*/

void inorder(node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


int main()
{

    return 0;
}
/*
    * so the in the tree travesal we use recursion
        / Traverse root
        / Traverse left subtree
        / Traverse right subtree

    * There are three most poular way to traverse
        / Inorder (left -> Root -> Right)
        / Preorder (root -> left -> right)
        / post order (left -> right -> root)
*/
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

int preindex = 0;
node *ctree(int in[], int pre[], int is, int ie) {
    if(is > ie ){
        return nullptr;
    }
    node *root = new node(pre[preindex++]);
    // In the code you provided, preindex is incremented after creating the node, 
    //so it indeed creates a node with the value of the current element in the preorder traversal, 
    //not the next element

    int index;
    for(int i = is; i <= ie; i++) {
        if(in[i] == root->data) {
            index = i;
            break;
        }
    }
    root->left = ctree(in, pre, is, index - 1);
    root->right = ctree(in, pre, index + 1, ie);
}

/*
    !!lets take an example to demonstrate this thing 
    in[] = 20,10,40,30,50
    pre[] = 10,20,30,40,50

    inital 
    is = 0
    ie = 4
    preindex = 0

    # node 10 created

    preindex = 1
    index = 1

    *recursion kick in for root -> left

    we consider the item a current pre index that is 1
    and then we increment the preindex to 2 
    20 create and linked to 10
    and now when search for 20 in the inorder array whose position 1 it fullfills the base case and 
    returns null so now the control goes to the parent function so now it is called for 30
    now the 30 gets searched in the inorder array and its range is decided and then we pprick the next item 
    from the preorder traversal that becomes left side of 30

    is = index start
    ie = index end 

    # node 10
    is = 0
    ie = 4

    # node 20
    is = 0
    ie = 0

    # node 30
    is = 2
    ie = 4

    # node 40
    is = 2
    ie = 2

    #node 50 
    is = 4
    ie = 4 

*/

int main()
{

    return 0;

}
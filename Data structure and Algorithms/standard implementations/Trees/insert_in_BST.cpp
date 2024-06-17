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

node* insert(node* root, int value) {
    if(root == nullptr){
        return new node(value);
    }
    if(value < root->data){
        insert(root->left, value);
    }
    else{
        insert(root->right, value);
    }
    return root;
}

int main()
{

    return 0;

}
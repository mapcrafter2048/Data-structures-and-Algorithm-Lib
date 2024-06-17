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

bool ispresent(node* root, int key) {
    if(root == nullptr){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key > root -> data){
        return ispresent(root->right, key);
    }
    else{
        return ispresent(root->left, key);
    }

}

int main()
{

    return 0;

}
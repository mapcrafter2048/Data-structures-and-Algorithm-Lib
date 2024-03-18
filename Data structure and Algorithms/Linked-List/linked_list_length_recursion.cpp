#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};

int ll_size(node* root){
    if(root == nullptr){
        return 0;
    }
    else{
        return (ll_size(root -> next) + 1);
    }
}
    
int main()
{

    return 0;

}
#include<iostream>
using namespace std;

class Node {
    private:
        // Private member variables
        int private_member;

    public:
        int data;
        Node* next;
        // Constructor
        Node(int data) {
            // Constructor code here
            this -> data = data;
            this -> next = NULL;
        }

        // Destructor
        ~Node() {
            // Destructor code here
        }
};

Node* reverselinkedlist(Node* head){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;

    }

}

int main()
{

    return 0;

}
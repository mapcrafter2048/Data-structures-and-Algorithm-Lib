#include <iostream>
using namespace std;

class node
{
private:
    // Private member variables
    int private_member;

public:
    // Constructor
    node(int value)
    {
        // Constructor code here
        data = value;
        next = NULL; // pointer of type node
    }

    // Destructor
    ~node()
    {
        // Destructor code here
    }
    int data;
    node *next;
};

void InsertAtTial(node *&head /* so here &head is the refrence varaiable which is qua; to temp */, int value)
{

    node *n1 = new node(value);

    node *temp = head; // In the code, node* temp = head; creates a new pointer variable temp and initializes it with the value of head.
                       // This means temp now points to the same memory location as head. Both temp and head are aliases for the same pointer.
    while ((*temp).next != NULL)
    {
        temp = (*temp).next;
    }
    (*temp).next = n1;
    
    // or else we can also use
    node n2(value);
    node* n2_pointer = &n2;
    node *temp = head; // In the code, node* temp = head; creates a new pointer variable temp and initializes it with the value of head.
                       // This means temp now points to the same memory location as head. Both temp and head are aliases for the same pointer.
    while ((*temp).next != NULL)
    {
        temp = (*temp).next;
    }

    (*temp).next = n2_pointer;
    // In the first case node* n1 = &n1;, you are assigning the address of the n1 object to the pointer n1. 
    // This means that the pointer n1 is pointing to the same memory location where the n1 object is stored. The & operator is used to get the address of an object.

    // In the second case node* n1 = new node(value);, you are using the new operator to dynamically allocate memory for a new node object on the heap. 
    // The new operator returns the address of the allocated memory, so the pointer n1 is assigned with that address.

}

int main()
{

    return 0;
}
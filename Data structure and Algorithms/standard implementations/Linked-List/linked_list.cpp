#include<iostream>
using namespace std;

class node {
    private:
        // Private member variables
        int private_member;

    public:
        int data;
        node* next;
        // Constructor
        node(int data) {
            // Constructor code here
            this -> data = data; // here the first data is pointer variable of type node " refers to the member variable "data" within the object that the pointer points to
            this -> next = NULL;
        }

        // Destructor
        ~node() {
            // Destructor code here
            int value = this ->data; // By assigning this->data to value, the value of the data member variable is assigned to the value variable.  
            if(this -> next != NULL){
                delete next;
                this -> next = NULL;
            }
        }
};

void insertAtHead(node* &head, int data) {
    // Create a new node with the given data
    node* temp = new node(data);

    // Make the 'next' pointer of the new node point to the current head
    temp->next = head; // head is address.   so next is pointing to head not to next of head 
    // next has the entire address of head node 
    // Update the head to point to the new node
    head = temp; // head is like a poition od power and now temp is promoted to head node thats it 
    // the new node must have a name but it is know as the head now 
}

/*
/how it works:
    * lets start from start:
    * we made a pointer of the type node and name it node 1
    * since it is a pointer of type node it have data and address characterstics
    * now we want to introduce a new node at starting
    * so we have a position of power known aS head 
    * initally node1 have the title of head 
    * now when we call insertathead if creates a new pointer of type node of name temp
    * and we want to give it the position of head so we access its next and made it head 
    * now its pointing to the head node 
    * but only one node can be head so the position of head is given to temp and now its is head not temp
    * all this is done with help of refrecne variable so if we change anything here it happens premanetly 
*/
/*
    * We create a new node named temp using the constructor new node(data). 
    * This allocates memory for a new node and initializes it with the provided data value.
    * To insert the new node at the head, we make the next pointer of the new node (temp->next) point to the current head node. 
    * This ensures that the new node is connected to the rest of the linked list.
    * Finally, we update the head pointer to point to the new node (head = temp). 
    * This step is essential to maintain the correct starting point of the linked list.
    * Regarding the question about setting head = temp, 
    * it is necessary to update the head pointer to the new node because we want the new node to become the new head of the linked list. 
    * By assigning temp to head, we ensure that subsequent operations on the linked list consider the newly inserted node as the starting point.
    * Please note that this implementation assumes that the node struct or class has a member variable named next that represents the next node in the linked list.
*/
void print(node* &head){
    node* temp = head; // this is like int a = b thing
    while(temp != NULL){
        cout << temp -> data << endl;
        temp = temp -> next;
    }
}

void insertattail(node* tail, int data){
    node* temp = new node(data);
    tail -> next = temp; // tail is also like head it is node1 only just another name and its next is catputring the entire address of the temp node
    tail = temp; // now tail position is given to the new node but we havent updated it to update it 
    //Here, tail->next gives us the address of the new tail node, and we assign this address to the tail pointer. Now, the tail pointer correctly points to the new tail node.
}

void insertatposition(node* &tail, node* &head, int position, int data){

    if(position == 1){
        insertAtHead(head, data);
        return;
    }
    
    node* temp = head;

    if(temp -> next == NULL){
        insertattail(tail, data);
        return;
    }

    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }
    node* nodetoinsert = new node(data);
    nodetoinsert -> next = temp -> next; //initally the temp next was pointing to the node next to it now nodetoinsert next points to it 
    temp -> next = nodetoinsert; // and temp next now points to nodetoinsert


}

void deletenode(int position, node* &head){

    if(position == 1){
        node* temp = head;
        head = head -> next; // intially head was pointing to second node so nw the new head is the head-> next 
        temp -> next  = NULL;
        delete temp;
    }
    else{
        node* current = head;
        node* previous = NULL;
        int count = 1;
        while(count < position ){
            previous =current;
            current = current -> next;
            count++;
        } 
        previous -> next = current -> next; // current is the node to be deleted and previous is the node previous to it
        // 1--2--3--4
        // we have to delete 3 node so 3 node is current and 2nd is previous
        // so previous next is 3 and current next is 4 so if we equal them 3rd gets eliminated
        //1--2--4     
        current -> next = NULL; // to delete the pointer of 3 that is still pointing to 4 
        delete current;   
    }

}

int main()
{

    node* node1 = new node(10); // creating a pointer of type node whose name is node1
    //cout << node1 -> data << endl; // we are dereferencing the node1 and calling it data attrbute
    //cout << node1 -> next << endl; // we are dereferencing the node1 and calling it next attrbute
    
    // head pointed to new node
    node* head = node1; // this is like int a = b; thing 
    //cout << head -> data << endl;
    //cout << head -> next << endl;
    node* tail = node1;
    // head is address and node1 is also a adddress

    insertAtHead(head, 11);
    insertAtHead(head, 13);
    insertAtHead(head, 15);
    insertAtHead(tail, 17);
    insertatposition(tail, head, 5, 19);
    deletenode(3, head);
    print(head);
    return 0;

}
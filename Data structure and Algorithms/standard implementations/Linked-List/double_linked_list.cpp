#include<iostream>
using namespace std;

class node {
    private:
        // Private member variables
        int private_member;

    public:
        int data;
        node* prev;
        node* next;
        // Constructor
        node(int data) {
            // Constructor code here
            this -> data = data;
            this -> prev = NULL;
            this -> next = NULL;
        }

        // Destructor
        ~node() {
            // Destructor code here
            int val =  this -> data;
            if(next != NULL){
                delete next;
                next = NULL;
            }
        }
};

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data<<" ";
        temp  = temp -> next;
    }
    cout<<endl;
}

int getlength(node* head){
    int length = 0;
    node* temp = head;

    while(temp != NULL){
        length++;
        temp = temp -> next;
    }
    return length;
}

void insertathead(node* &head, node* &tail, int data){

    if(head == NULL){
        node* temp = new node(data);
        head = temp;
    }
    else{
        node* temp = new node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
        tail = temp;
    }
}

void insertattail(node* &head, node* &tail, int data){
      if(tail == NULL){
        node* temp = new node(data);
        tail = temp;
        head = temp;
    }
    else{
    node* temp = new node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    }
}

void insertatposition(node* &head,node* &tail, int data, int position){
    if(position == 1){
        insertathead(head, tail, data);
        return; 
    }
    node* temp = head;
    int count = 1;

    while(count < position -1){
        temp = temp -> next;
        count ++;
    }
    if(temp -> next = NULL){
        insertattail(head, tail, data);
    }
    node* nodetoinsert  = new node(data);
    nodetoinsert -> next = temp -> next;
    temp -> next -> prev = nodetoinsert;
    temp -> next  = nodetoinsert;
    nodetoinsert -> prev = temp;
}

void deletenode(int position, node* &head){
    if(position == 1){
        node* temp = head;
        temp-> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        node* curr = head;
        node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count ++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}
/*
1==2==3==4
if we have to delete suppose first node so we have to make 2 node left connections to be null
so temp(1) -> next is 2 whose previous is 1 is null 
and head becomes temp(1) next which is 2
*/
/*
1==2==3==4
we have to insert a node between 3 and 4 
so here temp here is 3 so first we change temp(3) next to node to insert next so one connection is made
for the second connection but in opposite direction we use temp(3) -> next that is 4 previous that to nodetoinsert
now for the second side we connect temp(3) next to nodetoinsert
and then we connect nodetoinert previous to temp
*/
int main()
{

    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    print(head);
    insertathead(head, tail, 10);
    print(head);
    insertathead(head, tail, 11);
    print(head);
    insertathead(head, tail, 12);
    print(head);
    insertathead(head, tail, 13);
    print(head);
    insertattail(head, tail, 14);
    print(head);
    insertattail(head, tail, 16);
    print(head);
    insertattail(head, tail, 18);
    print(head);
    insertattail(head, tail, 20);
    print(head);
    insertatposition(head, tail, 15, 5);
    print(head);
    insertatposition(head, tail, 17, 7);
    print(head);
    insertatposition(head, tail, 19, 9);
    print(head);

    return 0;

}
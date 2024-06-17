#include <iostream>
#include <queue>
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

void printlevelorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (q.size() > 1)
    {
        node *current = q.front();
        q.pop();
        if (current == nullptr)
        {
            cout << "\n";
            q.push(nullptr);
            continue;
        }
        cout << (current->data) << " ";
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}

void printlevelorder2(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
        cout << "\n";
    }
}

/*

    # how this thing works 
    * so here we use the 2 loops to full fill our purpose
    * first we input the root node the nit enters into the first loop
    * which calculates its size for the second loop to run 
    * then it runs the loop for the size of queue each time it run i print one entry
    * now here for the root node it runs one time and then exits the loop and print a new line 
    * now suppose there were two nodes in the second level each node having 2 children
    * so now the size of the queues is 2 it prints one node then it also add its 2 children node 
    * to the queue but the loop will run for only 2 times so after the loop has run for 2 times it exit
    * and now the queue size is 4 os the loop runs for 4 times and then exit the for loop and also exit the 
    * while loop 

*/

/*
    # how do this thing works
            10
           /  \
         20   30
        /
       40

    # 10|NULL|  |  |  | 10

    # NULL|20|30|  |  | NEW LINE

    # 20|30|NULL|  |  | 20

    # 30|NULL|40|  |  | 30

    # NULL|40|  |  |  | NEW LINE

    # 40|NULL|  |  |  | 40

    # NULL|  |  |  |  | NEW LINE

    * so here we can see the logic that first we will imput the root node 10
    * and then we will also push nullptr into the queue
    * so the logic is that when we enconter aa null it means that we move to a new line
    * so as we see in the 2nd step we encounter a null so move to a new line
    * and in the third line we pop the null and then also input a null in the next place

*/

int main()
{

    return 0;
}
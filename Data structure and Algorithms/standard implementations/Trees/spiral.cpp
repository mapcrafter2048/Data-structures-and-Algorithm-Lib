#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>

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

void spiral(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<node *> q;
    stack<int> s;
    bool reverse = false;

    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *current = q.front();
            q.pop();
            if (reverse)
            {
                s.push(current->data);
            }
            else
            {
                cout << current->data << endl;
            }
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
        if (reverse)
        {
            while (s.empty() == false)
            {
                cout << s.top() << endl;
                s.pop();
            }
        }
        reverse = !reverse;
        cout << endl;
    }
}

/*
so what it is doing is it is reversing each time the value of false so here we can see that when the
first time the loop runs the value of return is false so it prints directly and the after that the value of the
reverse variable is reversed so now it becomes true and when the second time the loop runs instead
of printing it it stores them in a stack and after that it will empty the stack
*/

// # method 2 
/*
in the method 2 we are taking 2 stacks and then we are doing operations
    push root into stack 1 
    while any of the two stack is not empty 
        while s1 is not empty 
            take out a node print it 
            push children of the taken out node into s2 --> left and then right 
        while s2 is not empty 
            take out a node print it
            push children of the taken out node into s1 in reverse order --> right anf then left 


*/

int main()
{

    return 0;
}
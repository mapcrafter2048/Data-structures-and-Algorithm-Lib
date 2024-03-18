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

void iterativeInoder(node *root)
{
    stack<node *> st;
    node *curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << (curr->data) << " ";
        curr = curr->right;
    }
}

void iterativepreorder(node *root)
{
    if (root == NULL)
        return;
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node* curr = st.top();
        cout << curr->data << " ";  
        st.pop();
        if(curr -> right != nullptr){
            st.push(curr -> right);
        }
        if(curr -> left != nullptr){
            st.push(curr -> left);
        }
    }
}

int main()
{

    return 0;
}
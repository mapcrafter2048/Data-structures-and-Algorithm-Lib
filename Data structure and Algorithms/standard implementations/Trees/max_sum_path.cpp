#include <iostream>
#include <vector>
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

int sum = 0;
vector<int> v;

int max_sum(node *root)
{
    if (root->left != nullptr && root->right != nullptr)
    {
        return root->data;
    }
    else
    {
        max_sum(root->left);
        max_sum(root->right);
    }
}

int main()
{

    return 0;
}
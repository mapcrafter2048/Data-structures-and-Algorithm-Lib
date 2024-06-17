#include <iostream>
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

int maxlevel = 0;
void printleft(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (maxlevel < level)
    {
        cout << root->data << endl;
        maxlevel = level;
    }
    printleft(root->left, level + 1);
    printleft(root->right, level + 1);
}

void printleftview(node* root){
    printleft(root,1);
}

int main()
{

    return 0;
}
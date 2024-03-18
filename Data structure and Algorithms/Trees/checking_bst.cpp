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

int main()
{

    vector<int> v1;
    vector<int> v2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v1.push_back(element);
        v2.push_back(element);
    }

    if (v1[0] != v2[0])
    {
        cout << "Not the same BST" << endl;
    }

    vector<int> v3;
    vector<int> v4;

    return 0;
}
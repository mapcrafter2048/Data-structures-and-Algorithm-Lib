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

bool findPath(node *root, int target, std::vector<int> &path)
{
    if (root == nullptr)
    {
        return false;
    }

    // Add the current node's value to the path
    path.push_back(root->data);

    // If the current node is the target node, return true
    if (root->data == target)
    {
        return true;
    }

    // Recursively search for the target in the left and right subtrees
    if ((root->left && findPath(root->left, target, path)) ||
        (root->right && findPath(root->right, target, path)))
    {
        return true;
    }

    // If the target is not found in the current subtree, backtrack and remove the last node from the path
    path.pop_back();
    return false;
}

// Function to find the Lowest Common Ancestor (LCA) of two nodes in a binary tree
int findLCA(node *root, int p, int q)
{
    std::vector<int> path1, path2;

    // Find paths from the root to the two nodes
    if (!findPath(root, p, path1) || !findPath(root, q, path2))
    {
        return -1; // LCA not found
    }

    // Compare the two paths to find the LCA
    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
    {
        i++;
    }

    // The LCA is the last common element in the two paths
    return path1[i - 1];
}

int main()
{
    // Create a sample binary tree using the provided node class.
    node *root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->right->left = new node(0);
    root->right->right = new node(8);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);

    int node1 = 5; // Value of the first node
    int node2 = 1; // Value of the second node

    int lca = findLCA(root, node1, node2);

    if (lca != -1)
    {
        std::cout << "Lowest Common Ancestor of " << node1 << " and " << node2 << " is " << lca << std::endl;
    }
    else
    {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    // Clean up the allocated memory (you should implement a proper destructor)
    delete root;
    root = nullptr;

    return 0;
}
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
/*
    % problem of this question

    * so we have to print the nodes in each level of the tree and the move downwards
    * but here we cannot use the recursion as when using the recursion first and entire subtree
    * is completed and then it moves to other branch and then it again starts  again from the beginning
    * to counter this problem we use queue

            10
           /  \
         15    20
        /     /  \
       30    40   50
            /  \
           70   80


*/

/**
 * The function prints the level order traversal of a binary tree.
 *
 * @param root The root parameter is a pointer to the root node of a binary tree.
 *
 * @return The function is not returning anything. It has a void return type.
 */
void printLevelOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
}

/*

    ! the way above function works
    # 10|  |  |  |  |  => 10
    # 15|20|  |  |  |  => 15
    # 20|30|  |  |  |  => 20
    # 30|40|50|  |  |  => 30
    # 40|70|80|  |  |  => 40

    ? so here we see how this works
    first we input the root
    then we run the loop and print the root
    then we enqueue its children that is 15 and 20 and now
    the current node is pointing to 15 so it gets poped and then its children is enqued
    same process repeates and the whole tree is printed


*/

int main()
{

    return 0;
}
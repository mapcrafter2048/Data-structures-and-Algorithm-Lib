#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

/*
Given the root of a binary tree, return the sum of values of nodes with an
even-valued grandparent. If there are no nodes with an even-valued grandparent,
return 0.

A grandparent of a node is the parent of its parent if it exists.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
To solve the problem of finding the sum of values of nodes with an even-valued
grandparent in a binary tree, we can use a recursive approach. Below is a
detailed explanation of the solution logic and steps of implementation:

### Problem Understanding:
1. **Grandparent Definition**: A grandparent of a node is the parent of its
parent. For example, in a binary tree, if a node `A` has a child `B`, and `B`
has a child `C`, then `A` is the grandparent of `C`.
2. **Even-Valued Grandparent**: We are only interested in nodes whose
grandparent's value is even. If a node does not have a grandparent or its
grandparent's value is odd, it does not contribute to the sum.
3. **Tree Traversal**: To solve this problem, we need to traverse the entire
binary tree and check each node to determine if its grandparent's value is even.

### Solution Logic:
1. **Recursive Traversal**: Use a recursive function to traverse the binary
tree. During the traversal, keep track of the current node, its parent, and its
grandparent.
2. **Sum Calculation**: For each node, check if its grandparent's value is even.
If it is, add the current node's value to the sum.
3. **Base Case**: If the current node is `nullptr`, return 0, as there are no
nodes to process.

### Steps of Implementation:
1. **Recursive Function**: Create a helper function `solve(TreeNode *root, int
parent, int gparent)`:
    - This function takes three arguments: the current node (`root`), its parent
(`parent`), and its grandparent (`gparent`).
    - If the current node is `nullptr`, return 0 (base case).
    - Recursively call the function for the left and right children of the
current node, passing the current node's value as the parent and the parent's
value as the grandparent.
    - If the grandparent's value is even, add the current node's value to the
sum.
2. **Edge Cases**: Handle cases where the tree is empty or there are no nodes
with an even-valued grandparent.
3. **Main Function**: Implement the main function `sumEvenGrandparent(TreeNode
*root)`:
    - This function initializes the recursion by calling the helper function
`solve` with default values for parent and grandparent (e.g., -1, which is not a
valid node value).

### Implementation Details:
- The `solve` function performs the recursive traversal and calculates the sum.
- The `sumEvenGrandparent` function acts as a wrapper to call the recursive
function with initial values.

### Complexity Analysis:
1. **Time Complexity**: O(n), where `n` is the number of nodes in the binary
tree. Each node is visited exactly once during the traversal.
2. **Space Complexity**: O(h), where `h` is the height of the binary tree. This
is the space used by the recursion stack. In the worst case (for a skewed tree),
`h` can be equal to `n`. In the best case (for a balanced tree), `h` is log(n).

### Example Walkthrough:
Consider the following binary tree:

        6
       / \
      7   8
     / \   \
    2   7   1
   /   / \
  9   1   4

- The nodes with even-valued grandparents are: 9, 7, 1, and 4.
- Their sum is: 9 + 7 + 1 + 4 = 21.

The recursive function will traverse the tree and calculate this sum.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

int solve(TreeNode *root, int parent, int gparent) {
    if (root == nullptr) {
        return 0;
    }

    return solve(root->left, root->val, parent) +
           solve(root->right, root->val, parent) +
           (gparent % 2 ? 0 : root->val);
}

int sumEvenGrandparent(TreeNode *root) { return solve(root, -1, -1); }

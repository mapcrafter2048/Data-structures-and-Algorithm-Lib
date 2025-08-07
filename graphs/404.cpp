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
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child
of another node.
*/

/*
Solution Logic and Steps of Implementation:

1. **Understanding the Problem**:
    - We need to calculate the sum of all "left leaves" in a binary tree.
    - A "leaf" is a node with no children (both left and right pointers are
`nullptr`).
    - A "left leaf" is a leaf node that is the left child of its parent.

2. **Approach**:
    - Use a recursive helper function to traverse the binary tree.
    - Pass an additional parameter (`left`) to the helper function to indicate
whether the current node is a left child.
    - If the current node is a leaf and is a left child, add its value to the
sum.
    - Recursively calculate the sum for the left and right subtrees.

3. **Steps of Implementation**:
    - Define a helper function `help(TreeNode *node, bool left)`:
      - Base Case: If the current node is `nullptr`, return 0 (no contribution
to the sum).
      - Check if the current node is a leaf:
         - If it is a left leaf (`left == true`), return its value.
         - Otherwise, return 0.
      - Recursively calculate the sum of left leaves in the left and right
subtrees.
      - Return the sum of the left and right subtree results.
    - In the main function `sumOfLeftLeaves(TreeNode *root)`:
      - Call the helper function with the root node and `false` (since the root
is not a left child).

4. **Complexity**:
    - Time Complexity: O(n), where `n` is the number of nodes in the tree. Each
node is visited once.
    - Space Complexity: O(h), where `h` is the height of the tree. This is the
space used by the recursion stack.

The implementation ensures that we correctly identify and sum up all left leaves
in the binary tree.
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

class Solution {
  public:
    int help(TreeNode *node, bool left) {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr) {
            if (left) {
                return node->val;
            } else {
                return 0;
            }
        }

        int lefts = help(node->left, true);
        int rights = help(node->right, false);
        return lefts + rights;
    }

    int sumOfLeftLeaves(TreeNode *root) { return help(root, false); }
};
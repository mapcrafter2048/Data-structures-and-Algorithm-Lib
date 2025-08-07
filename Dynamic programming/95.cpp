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
Given an integer n, return all the structurally unique BST's (binary search
trees), which has exactly n nodes of unique values from 1 to n. Return the
answer in any order.
*/

/*
Solution Explanation:

The task is to generate all structurally unique Binary Search Trees (BSTs) that
can be formed using `n` unique values from 1 to `n`. A BST is a binary tree
where, for each node, all values in the left subtree are smaller, and all values
in the right subtree are larger.

### Step-by-Step Explanation:

1. **TreeNode Structure**:
    - A `TreeNode` structure is defined to represent nodes in the BST. Each node
contains:
        - `val`: The value of the node.
        - `left`: A pointer to the left child.
        - `right`: A pointer to the right child.
    - This structure is the building block for constructing the BSTs.

2. **Main Function (`generateTrees`)**:
    - This function is the entry point for generating all unique BSTs.
    - Input: An integer `n` representing the number of nodes.
    - Output: A vector of pointers to the root nodes of all unique BSTs.
    - If `n == 0`, return an empty vector since no BSTs can be formed.
    - Otherwise, call the helper function `buildTrees` with the range `[1, n]`.

3. **Recursive Helper Function (`buildTrees`)**:
    - This function generates all unique BSTs for a given range `[start, end]`.
    - **Base Case**:
        - If `start > end`, return a vector containing `NULL` (representing an
empty tree).
    - **Recursive Case**:
        - Iterate through all possible root values in the range `[start, end]`.
        - For each root value:
            - Recursively generate all possible left subtrees using the range
`[start, root - 1]`.
            - Recursively generate all possible right subtrees using the range
`[root + 1, end]`.
            - Combine each left subtree with each right subtree, attaching them
to the current root node.
            - Add the resulting tree to the result vector.
    - Return the result vector containing all unique BSTs for the given range.

4. **Combining Subtrees**:
    - For each root value, the function combines all possible left subtrees with
all possible right subtrees.
    - This ensures that all combinations of left and right subtrees are
considered for each root.

5. **Memory Management**:
    - Each tree is dynamically allocated using `new`. The caller is responsible
for freeing the memory of the generated trees to avoid memory leaks.

---

### Example Walkthrough:

Let `n = 3`. We need to generate all unique BSTs using values {1, 2, 3}.

1. **Call `generateTrees(3)`**:
    - Calls `buildTrees(1, 3)`.

2. **Call `buildTrees(1, 3)`**:
    - Iterate through root values: 1, 2, 3.

    - **Root = 1**:
        - Left Subtrees: `buildTrees(1, 0)` → [NULL].
        - Right Subtrees: `buildTrees(2, 3)`.

    - **Call `buildTrees(2, 3)`**:
        - Iterate through root values: 2, 3.

        - **Root = 2**:
            - Left Subtrees: `buildTrees(2, 1)` → [NULL].
            - Right Subtrees: `buildTrees(3, 3)`.

        - **Call `buildTrees(3, 3)`**:
            - Root = 3:
                - Left Subtrees: `buildTrees(3, 2)` → [NULL].
                - Right Subtrees: `buildTrees(4, 3)` → [NULL].
            - Combine:
                - Root = 3, Left = NULL, Right = NULL → Tree: [3].

        - Combine for `buildTrees(2, 3)`:
            - Root = 2, Left = NULL, Right = [3] → Tree: [2, NULL, 3].
            - Root = 3, Left = [2], Right = NULL → Tree: [3, 2, NULL].

    - Combine for `buildTrees(1, 3)`:
        - Root = 1, Left = NULL, Right = [2, NULL, 3] and [3, 2, NULL].

    - **Root = 2**:
        - Left Subtrees: `buildTrees(1, 1)`.
        - Right Subtrees: `buildTrees(3, 3)`.

    - **Call `buildTrees(1, 1)`**:
        - Root = 1:
            - Left Subtrees: `buildTrees(1, 0)` → [NULL].
            - Right Subtrees: `buildTrees(2, 1)` → [NULL].
        - Combine:
            - Root = 1, Left = NULL, Right = NULL → Tree: [1].

    - Combine for `buildTrees(1, 3)`:
        - Root = 2, Left = [1], Right = [3].

    - **Root = 3**:
        - Left Subtrees: `buildTrees(1, 2)`.
        - Right Subtrees: `buildTrees(4, 3)` → [NULL].

    - **Call `buildTrees(1, 2)`**:
        - Iterate through root values: 1, 2.

        - **Root = 1**:
            - Left Subtrees: `buildTrees(1, 0)` → [NULL].
            - Right Subtrees: `buildTrees(2, 2)`.

        - **Call `buildTrees(2, 2)`**:
            - Root = 2:
                - Left Subtrees: `buildTrees(2, 1)` → [NULL].
                - Right Subtrees: `buildTrees(3, 2)` → [NULL].
            - Combine:
                - Root = 2, Left = NULL, Right = NULL → Tree: [2].

        - Combine for `buildTrees(1, 2)`:
            - Root = 1, Left = NULL, Right = [2].

        - **Root = 2**:
            - Left Subtrees: `buildTrees(1, 1)` → [1].
            - Right Subtrees: `buildTrees(3, 2)` → [NULL].
            - Combine:
                - Root = 2, Left = [1], Right = NULL.

    - Combine for `buildTrees(1, 3)`:
        - Root = 3, Left = [1, NULL, 2] and [2, 1, NULL], Right = NULL.

---

### Final Trees:

1. [1, NULL, 2, NULL, 3].
2. [1, NULL, 3, 2, NULL].
3. [2, 1, 3].
4. [3, 1, NULL, NULL, 2].
5. [3, 2, NULL, 1, NULL].
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0)
            return {};
        return buildTrees(1, n);
    }

    vector<TreeNode *> buildTrees(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }

        for (int root = start; root <= end; root++) {
            // All possible left and right subtrees
            vector<TreeNode *> leftTrees = buildTrees(start, root - 1);
            vector<TreeNode *> rightTrees = buildTrees(root + 1, end);

            // Combine
            for (TreeNode *left : leftTrees) {
                for (TreeNode *right : rightTrees) {
                    TreeNode *node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};

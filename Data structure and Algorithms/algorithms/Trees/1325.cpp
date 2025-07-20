#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

#pragma GCC optimize("O3", "unroll-loops")

/*
testcase
root =
[1,2,2,3,null,null,3,4,null,null,4,5,null,null,5,5,null,null,5,5,null,null,5,5,null,null,5]
target = 5

(1,0)
(1,1)(2,0)(2,0)
(1,1)(2,0)(2,1)(3,0)
(1,1)(2,0)(2,1)(3,1)(4,0)
(1,1)(2,0)(2,1)(3,1)(4,1)(5,0)
(1,1)(2,0)(2,1)(3,1)(4,1)(5,1)(5,0)
(1,1)(2,0)(2,1)(3,1)(4,1)(5,1)(5,1)(5,0)
(1,1)(2,0)(2,1)(3,1)(4,1)(5,1)(5,1)(5,1)(5,0)
(1,1)(2,0)(2,1)(3,1)(4,1)(5,1)(5,1)(5,1)(5,1)
(1,1)(2,0)(2,1)(3,1)(4,1)(5,1)(5,1)(5,1)
(1,1)(2,0)(2,1)(3,1)(4,1)(5,1)(5,1)
(1,1)(2,0)(2,1)(3,1)(4,1)(5,1)
(1,1)(2,0)(2,1)(3,1)(4,1)
(1,1)(2,0)(2,1)(3,1)
(1,1)(2,0)(2,1)
(1,1)(2,0)
(1,1)(2,1)(3,0)
(1,1)(2,1)(3,1)(4,0)
(1,1)(2,1)(3,1)(4,1)(5,0)
(1,1)(2,1)(3,1)(4,1)(5,1)(5,0)
(1,1)(2,1)(3,1)(4,1)(5,1)(5,1)(5,0)
(1,1)(2,1)(3,1)(4,1)(5,1)(5,1)(5,1)(5,0)
(1,1)(2,1)(3,1)(4,1)(5,1)(5,1)(5,1)(5,1)
(1,1)(2,1)(3,1)(4,1)(5,1)(5,1)(5,1)
(1,1)(2,1)(3,1)(4,1)(5,1)(5,1)
(1,1)(2,1)(3,1)(4,1)(5,1)
(1,1)(2,1)(3,1)(4,1)
(1,1)(2,1)(3,1)
(1,1)(2,1)
(1,1)
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

using node2 = tuple<TreeNode *, TreeNode *, bool>; // node, parent, visited

TreeNode *removeLeafNodes(TreeNode *root, int target) {
    vector<node2> nodeStack = {{root, nullptr, 0}};

    while (!nodeStack.empty()) {
        auto [node, parent, visited] = nodeStack.back();
        nodeStack.pop_back();

        if (!visited) {
            // Mark the node as visited and repush
            nodeStack.emplace_back(node, parent, 1);

            // push right and left children onto the stack

            if (root->right) {
                nodeStack.emplace_back(root->right, node, 0);
            }
            if (root->left) {
                nodeStack.emplace_back(root->left, node, 0);
            }
        } else {
            // node is a leaf and its value matches the target
            if (!node->left && !node->right && node->val == target) {

                // Check if this leaf node is ALSO the root of the tree
                if (parent) {
                    // This leaf is NOT the root, so update its parent
                    if (parent->left == node) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                    delete node;
                } else {
                    // This leaf IS the root, so set root to null to indicate an
                    // empty tree
                    root = nullptr;
                }
            }
        }
    }

    return root;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
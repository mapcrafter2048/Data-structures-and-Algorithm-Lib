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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/*
In this question, we are given a binary tree and a target value. Our goal is to
find all the paths in the tree where the sum of the values of all the nodes in
the path equals the target value.

To solve this problem, we can create a new function called "solve". Inside this
function, we first specify two base conditions.

The first base condition checks if the current node is null (i.e., we have
reached the end of a branch). If this is the case, we simply return from the
function.

The second base condition is important. It checks if the current node is a leaf
node (i.e., it has no children) and if the value of that node is equal to the
target sum. If this condition is met, it means we have found a path that
satisfies the target sum. In this case, we append that path to our result
vector.

After specifying the base conditions, we recursively call the "solve" function
for the left subtree and the right subtree. We also update the target sum by
subtracting the value of the current node. This adjustment is necessary to
justify our second base condition, as we need to consider the remaining sum
required to reach the target.

During the traversal, if we reach the end of a path without finding a valid sum,
we backtrack by popping the elements from the path. This allows us to explore
other paths in the tree.

By following this approach, we can find all the paths in the binary tree that
sum up to the target value.
*/

void solve(TreeNode *root, int targetSum, vector<int> &path,
           vector<vector<int>> &result) {
    if (root == nullptr) {
        return;
    }

    path.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr &&
        root->val == targetSum) {
        result.push_back(path);
    }

    solve(root->left, targetSum - root->val, path, result);
    solve(root->right, targetSum - root->val, path, result);

    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> result;
    vector<int> currentPath;
    solve(root, targetSum, currentPath, result);
    return result;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
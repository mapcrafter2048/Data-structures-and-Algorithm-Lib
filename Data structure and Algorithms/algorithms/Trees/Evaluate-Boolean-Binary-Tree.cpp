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

bool solve(TreeNode *node) {
    if (node->val == 0 || node->val == 1) {
        return node->val == 1; // Return the Boolean Value
    } else if (node->val == 2) {
        return solve(node->left) || solve(node->right);
    } else if (node->val == 3) {
        return solve(node->left) && solve(node->right);
    }

    return false;
}

bool evaluateTree(TreeNode *root) { return solve(root); }

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
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

class Solution {

  public:
    int distributeCoins(TreeNode *root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }

    void printTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();

                cout << node->val << " ";

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            cout << endl;
        }
    }

    int dfs(TreeNode *node, int &moves) {
        if (!node)
            return 0;

        int left = dfs(node->left, moves);
        int right = dfs(node->right, moves);

        moves += abs(left) + abs(right);
        return node->val + left + right - 1;
        printTree(node);
    }
};

int main() {
    auto start = high_resolution_clock::now();

    // Your code here
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << sol.distributeCoins(root) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}

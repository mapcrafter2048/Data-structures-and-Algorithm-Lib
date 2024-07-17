#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define debarr(a, n)                                                           \
    std::cout << #a << " : ";                                                  \
    for (int i = 0; i < n; i++)                                                \
        std::cerr << a[i] << " ";                                              \
    std::cerr << std::endl;
#define debmat(mat, row, col)                                                  \
    std::cout << #mat << " :\n";                                               \
    for (int i = 0; i < row; i++) {                                            \
        for (int j = 0; j < col; j++)                                          \
            std::cerr << mat[i][j] << " ";                                     \
        std::cerr << std::endl;                                                \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
std::ostream &operator<<(std::ostream &os, const std::pair<S, T> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<S, T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::multiset<T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
std::ostream &operator<<(std::ostream &os, const std::map<S, T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T> void dbs(std::string str, T t) {
    std::cerr << str << " : " << t << "\n";
}
template <class T, class... S> void dbs(std::string str, T t, S... s) {
    int idx = str.find(',');
    std::cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
template <class T> void prc(T a, T b) {
    std::cerr << "[";
    for (T i = a; i != b; ++i) {
        if (i != a)
            std::cerr << ", ";
        std::cerr << *i;
    }
    std::cerr << "]\n";
}
long long int binpow(long long int b, long long int p, long long int mod) {
    long long int ans = 1;
    b %= mod;
    for (; p; p >>= 1) {
        if (p & 1)
            ans = ans * b % mod;
        b = b * b % mod;
    }
    return ans;
}

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

void markParent(TreeNode *root,
                unordered_map<TreeNode *, TreeNode *> &parent_track,
                TreeNode *target) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *currentNode = q.front();
        q.pop(); // Pop the front node after accessing it

        // Track parent for the left child
        if (currentNode->left != nullptr) {
            parent_track[currentNode->left] = currentNode;
            q.push(currentNode->left);
        }
        // Track parent for the right child
        if (currentNode->right != nullptr) {
            parent_track[currentNode->right] = currentNode;
            q.push(currentNode->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    unordered_map<TreeNode *, TreeNode *> parent_track;
    // Mark the parent of each node starting from the root
    markParent(root, parent_track, target);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;

    int currentLevel = 0;
    while (!q.empty()) {
        int size = q.size();
        // Break if we reach the desired level
        if (currentLevel == k) {
            break;
        }
        for (int i = 0; i < size; i++) {
            TreeNode *current = q.front();
            q.pop();
            // Check and enqueue left child if it has not been visited
            if (current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }
            // Check and enqueue right child if it has not been visited
            if (current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }
            // Check and enqueue parent if it has not been visited
            if (parent_track[current] && !visited[parent_track[current]]) {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
        currentLevel++;
    }

    vector<int> result;
    // Collect all nodes at distance k
    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();
        result.push_back(current->val);
    }

    return result;
}

int main() {
    long long int cases;
    cin >> cases;
    while (cases--) {
        // Your code for each test case goes here
    }
    return 0;
}
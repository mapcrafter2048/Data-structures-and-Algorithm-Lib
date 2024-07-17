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

vector<int> leftView(TreeNode *root) {
    vector<int> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode *temp = q.front();
            q.pop();
            if (i == 0)
                ans.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}

void traversal(TreeNode *root, int level, vector<int> &ans) {
    if (root == nullptr) {
        return;
    }
    if (ans.size() == level) {
        ans.push_back(root->val);
    }
    traversal(root->right, level + 1, ans);
    traversal(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    traversal(root, 0, ans);
    return ans;
}

int main() {
    long long int cases;
    cin >> cases;
    while (cases--) {
        // Your code for each test case goes here
    }
    return 0;
}
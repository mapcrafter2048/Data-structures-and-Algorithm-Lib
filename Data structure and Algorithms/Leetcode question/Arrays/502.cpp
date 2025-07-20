/*
Suppose LeetCode will start its IPO soon. In order to sell a good price of its
shares to Venture Capital, LeetCode would like to work on some projects to
increase its capital before the IPO. Since it has limited resources, it can only
finish at most k distinct projects before the IPO. Help LeetCode design the best
way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and
a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its
pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your
final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.
*/
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
    std::cerr << str.substr(0, idx) << s " : " << t << ",";
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

int findMaximizedCapital(int k, int w, vector<int> &profits,
                         vector<int> &capital) {
    int n = profits.size();
    vector<pair<int, int>> corresponding;

    for (int i = 0; i < n; i++) {
        corresponding.push_back({capital[i], profits[i]});
    }

    sort(corresponding.begin(), corresponding.end());
    priority_queue<int> pq;
    int i = 0;

    for (int j = 0; j < k; j++) {
        while (i < n && corresponding[i].first <= w) {
            pq.push(corresponding[i].second);
            i++;
        }

        if (pq.empty()) {
            break;
        }

        w += pq.top();
        pq.pop();
    }

    return w;
}

/*
so this question is a greedy question with a particular straight forward approah
so what we have to do is for a given w we have to find the maximum profit we can
make by selecting atmost k projects so first we make pair of capital and profit
and sort them according to capital and then we iterate over the capital and
check if the capital is less than or equal to w then we push the profit in the
priority queue and then we iterate over the k and add the top of the priority
queue to the w and then pop the top of the priority queue and then return the w
*/

int main() {
    long long int cases;
    cin >> cases;
    while (cases--) {
        // Your code for each test case goes here
    }
    return 0;
}
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

/*
 * Lets have a dry run of the duthc flag algorithm on the array
 * [0,1,1,0,1,2,1,2,0,0,0]
 * nums : [ 0 1 1 0 1 2 1 2 0 0 0 ] low = 0 mid = 0 high = 10
 * nums : [ 0 1 1 0 1 2 1 2 0 0 0 ] low = 1 mid = 1 high = 10
 * nums : [ 0 1 1 0 1 2 1 2 0 0 0 ] low = 1 mid = 2 high = 10
 * nums : [ 0 0 1 1 1 2 1 2 0 0 0 ] low = 1 mid = 3 high = 10
 * nums : [ 0 0 1 1 1 2 1 2 0 0 0 ] low = 2 mid = 4 high = 10
 * nums : [ 0 0 1 1 1 0 1 2 0 0 2 ] low = 2 mid = 5 high = 10
 * nums : [ 0 0 0 1 1 1 1 2 0 0 2 ] low = 2 mid = 5 high = 9
 * nums : [ 0 0 0 1 1 1 1 2 0 0 2 ] Low = 3 mid = 6 high = 9
 * nums : [ 0 0 0 1 1 1 1 0 0 2 2 ] Low = 3 mid = 7 high = 8
 * nums : [ 0 0 0 0 1 1 1 1 0 2 2 ] Low = 3 mid = 7 high = 8
 * nums : [ 0 0 0 0 0 1 1 1 1 2 2 ] Low = 3 mid = 7 high = 8
 */

void sortColors(vector<int> &nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
        pr(nums);
    }
}

int main() {
    vector<int> nums{0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
    sortColors(nums);
    return 0;
}
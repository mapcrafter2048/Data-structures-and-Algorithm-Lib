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
This algorithm solves the problem of finding the minimum number of patches
needed to make the given array nums contain all numbers from 1 to n (inclusive).

The algorithm works by iteratively checking if the current missing number is
present in the nums array. If it is, we increment the missing number by adding
the value at the current index in nums and move to the next index. If the
current missing number is not present in nums, we add the missing number itself
to the array and increment the patches count.

Here's a step-by-step breakdown of how the algorithm works:

Initialize the missing variable to 1, which represents the smallest missing
number. Initialize the patches variable to 0, which represents the number of
patches added to the array. Initialize the index variable to 0, which represents
the current index in the nums array. Enter a loop that continues until the
missing number exceeds n. Inside the loop, check if the current missing number
is present in the nums array by comparing it with the value at the current index
(nums[index]). If the current missing number is less than or equal to the value
at the current index, it means that the number is present in the array. In this
case, increment the missing number by adding the value at the current index
(missing += nums[index]) and move to the next index (index++). If the current
missing number is greater than the value at the current index or the index
exceeds the size of the nums array, it means that the number is missing. In this
case, add the missing number itself to the array (missing += missing) and
increment the patches count (patches++). Repeat steps 5-7 until the missing
number exceeds n. Return the final value of the patches variable, which
represents the minimum number of patches needed to make the array contain all
numbers from 1 to n. This algorithm works because it greedily adds the missing
numbers to the array in a way that ensures the smallest number of patches are
needed. By iterating through the nums array and comparing the current missing
number with the values in the array, we can determine if a number is missing or
present. If a number is missing, we add it to the array and
*/

int minPatches(vector<int> &nums, int n) {
    long missing = 1;
    int patches = 0;
    int index = 0;

    while (missing <= n) {
        if (index < nums.size() && nums[index] <= missing) {
            missing += nums[index];
            index++;
        } else {
            missing += missing;
            patches++;
        }
    }

    return patches;
}

int main() {
    long long int cases;
    cin >> cases;
    while (cases--) {
        // Your code for each test case goes here
    }
    return 0;
}
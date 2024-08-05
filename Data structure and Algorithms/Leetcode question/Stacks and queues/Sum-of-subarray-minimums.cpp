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

// Problem Link: https://leetcode.com/problems/sum-of-subarray-minimums/

int sumSubarrayMins_Brute(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int min = arr[i];
        for (int j = i; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
            }
            sum += min;
        }
    }

    return sum;
}

vector<int> nextSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nextSmaller(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nextSmaller[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nextSmaller;
}
// we are storing the index of the next smaller element in the array not the
// value itself because we need to calculate the number of subarrays that can be
// formed with the current element as the minimum element in the subarray
vector<int> previousSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> previousSmaller(n, -1);
    stack<int> st;
    for (int i = 0; i < n - 1; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        previousSmaller[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return previousSmaller;
}

// approach using next smaller and previous smaller element
//  Logic : For each element we need to find the next smaller element and
//  previous smaller element and then calculate the number of subarrays that can
//  be formed with the current element as the minimum element in the subarray
//  and add the product of the number of subarrays with the current element to
//  the total sum of subarray minimums and return the total sum

int sumSubarrayMins_opti(vector<int> &arr) {
    vector<int> nextSmaller = nextSmallerElement(arr);
    vector<int> previousSmaller = previousSmallerElement(arr);
    int total = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < arr.size(); i++) {
        int prev = i - previousSmaller[i];
        int next = nextSmaller[i] - i;
        total = (total + arr[i] * prev * next * 1LL) % mod;
    }

    return total;
}

int main() {
    long long int cases;
    cin >> cases;
    while (cases--) {
        // Your code for each test case goes here
    }
    return 0;
}
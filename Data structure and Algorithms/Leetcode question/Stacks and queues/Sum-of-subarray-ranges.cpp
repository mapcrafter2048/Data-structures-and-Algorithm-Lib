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

int sumSubarrayRanges_Brute(vector<int> arr) {
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int largest = arr[i];
        int smallest = arr[i];
        for (int j = i; j < n; j++) {
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);
            sum += largest - smallest;
        }
    }
    return sum;
}

vector<int> nextSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nextSmaller(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        nextSmaller[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nextSmaller;
}

vector<int> previousSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> prevSmaller(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        prevSmaller[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return prevSmaller;
}

// need to know the next greater element so if we iterate from start to end we
// cannot find it as we dont know the next element so we iterate from end to
// start
vector<int> nextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nextGreater(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        nextGreater[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nextGreater;
}

// need to know the previous greater element so if we iterate from end to start
// we cannot find it as we dont know the previous element so we iterate from
// start to end
vector<int> previousGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> prevGreater(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        prevGreater[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return prevGreater;
}

int sumSubarrayMaximums(vector<int> arr) {
    int n = arr.size();
    vector<int> nextGreater = nextGreaterElement(arr);
    vector<int> prevGreater = previousGreaterElement(arr);
    int totalSum = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); i++) {
        int prev = i - prevGreater[i];
        int next = nextGreater[i] - i;
        totalSum = (totalSum + arr[i] * prev * next) % mod;
    }
    return totalSum;
}

int sumSubarrayMinimums(vector<int> &arr) {
    int n = arr.size();
    vector<int> nextSmaller = nextSmallerElement(arr);
    vector<int> prevSmaller = previousSmallerElement(arr);
    int totalSum = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); i++) {
        int prev = i - prevSmaller[i];
        int next = nextSmaller[i] - i;
        totalSum = (totalSum + arr[i] * prev * next) % mod;
    }
    return totalSum;
}

int sumSubarrayRanges_Optimized(vector<int> arr) {
    int sum = 0;
    sum = sumSubarrayMaximums(arr) - sumSubarrayMinimums(arr);
    return sum;
}

int main() {
    long long int cases;
    cin >> cases;
    while (cases--) {
        // Your code for each test case goes here
    }
    return 0;
}
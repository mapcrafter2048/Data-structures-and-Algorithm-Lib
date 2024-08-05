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

// question link:
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// question desc: You are given a string s and an array of strings words of the
// same length. Return all starting indices of substring(s) in s that is a
// concatenation of each word in words exactly once, in any order, and without
// any intervening characters. You can return the answer in any order.

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result; // To store the resulting starting indices
        if (s.empty() || words.empty() || words[0].empty()) {
            return result; // Edge case: if s or words are empty, return empty
                           // result
        }

        int wordLength = words[0].length(); // Length of each word in words (all
                                            // words are the same length)
        int numWords = words.size();        // Number of words in words
        int substringLength =
            wordLength * numWords; // Total length of the concatenated substring

        unordered_map<string, int>
            wordsCount; // Hash map to store the frequency of each word in words
        for (const string &word : words) {
            wordsCount[word]++; // Populate the wordsCount map with the
                                // frequency of each word
        }

        // We will have `wordLength` different starting points (i.e., 0, 1, ...,
        // wordLength-1)
        for (int i = 0; i < wordLength; i++) {
            unordered_map<string, int>
                seenWords; // Hash map to track words seen in the current window
            int left = i;  // Initialize the left pointer of the sliding window
            int count = 0; // Counter to keep track of the number of words
                           // matched in the current window

            // Slide the window over the string starting from index `i`
            for (int j = i; j <= static_cast<int>(s.length()) - wordLength;
                 j += wordLength) {
                string word = s.substr(
                    j, wordLength); // Extract a word of length `wordLength`
                                    // starting from index `j`
                if (wordsCount.find(word) != wordsCount.end()) {
                    seenWords[word]++; // If the word is in wordsCount,
                                       // increment its count in seenWords
                    count++;           // Increment the count of words matched

                    // If a word's frequency in seenWords exceeds its frequency
                    // in wordsCount
                    while (seenWords[word] > wordsCount[word]) {
                        string leftWord = s.substr(
                            left,
                            wordLength); // Extract the word at the left pointer
                        seenWords[leftWord]--; // Decrement its count in
                                               // seenWords
                        count--; // Decrement the count of words matched
                        left +=
                            wordLength; // Move the left pointer to the right
                    }

                    // If the number of words matched equals the number of words
                    // in words
                    if (count == numWords) {
                        result.push_back(
                            left); // Add the starting index to the result
                    }
                } else {
                    // If the word is not in wordsCount, reset the window
                    seenWords.clear();     // Clear the seenWords map
                    count = 0;             // Reset the count of words matched
                    left = j + wordLength; // Move the left pointer to the next
                                           // possible starting position
                }
            }
        }

        return result; // Return the resulting starting indices
    }
};
int main() {
    long long int cases;
    cin >> cases;
    while (cases--) {
        // Your code for each test case goes here
    }
    return 0;
}
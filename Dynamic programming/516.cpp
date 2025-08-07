#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
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

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by
deleting some or no elements without changing the order of the remaining
elements.
*/

/*
Solution Logic:

The problem is to find the length of the longest palindromic subsequence in a
given string `s`. A subsequence is a sequence derived from another sequence by
deleting some or no elements without changing the order of the remaining
elements.

Steps of Implementation:

1. **Reverse the String**:
    - To find the longest palindromic subsequence, we can think of it as finding
the longest common subsequence (LCS) between the original string `s` and its
reverse. This is because a palindrome reads the same forward and backward.

2. **Dynamic Programming Approach**:
    - Use a 2D DP table `dp` where `dp[i][j]` represents the length of the LCS
between the first `i` characters of the original string `s1` and the first `j`
characters of the reversed string `s2`.

3. **Recursive Function with Memoization**:
    - Define a recursive function `solve(index1, index2, s1, s2, dp)` to compute
the LCS.
    - Base Case: If either `index1` or `index2` exceeds the length of their
respective strings, return 0.
    - Memoization: If the result for `dp[index1][index2]` is already computed,
return it to avoid redundant calculations.
    - Recursive Case:
      - If `s1[index1] == s2[index2]`, the characters match, so include it in
the LCS and move both indices forward.
      - Otherwise, take the maximum LCS by either moving `index1` forward or
`index2` forward.

4. **Initialization and Result**:
    - Initialize the DP table with `-1` to indicate uncomputed states.
    - Call the recursive function starting from the beginning of both strings
(`index1 = 0`, `index2 = 0`).
    - The result of the function gives the length of the longest palindromic
subsequence.

5. **Time Complexity**:
    - The time complexity is `O(n^2)` where `n` is the length of the string, as
we compute each state in the DP table once.
    - The space complexity is also `O(n^2)` due to the DP table.

This approach ensures an efficient solution to the problem.
*/

class Solution {
  public:
    int solve(int index1, int index2, string &s1, string &s2,
              vector<vector<int>> &dp) {
        if (index1 >= s1.size() || index2 >= s2.size()) {
            return 0;
        }

        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        if (s1[index1] == s2[index2]) {
            dp[index1][index2] = 1 + solve(index1 + 1, index2 + 1, s1, s2, dp);
        } else {
            dp[index1][index2] = max(solve(index1 + 1, index2, s1, s2, dp),
                                     solve(index1, index2 + 1, s1, s2, dp));
        }

        return dp[index1][index2];
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;

        vector<vector<int>> dp(s1.size(), vector<int>(s2.size() + 1, -1));
        return solve(0, 0, s1, s2, dp);
    }
};
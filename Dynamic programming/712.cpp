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
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters
to make two strings equal.
*/

/*
The problem is to find the minimum ASCII sum of characters that need to be
deleted from two strings to make them equal. Here's the detailed solution logic
and steps:

1. **Understanding the Problem**:
    - Given two strings `s1` and `s2`, we need to make them equal by deleting
some characters from either string.
    - The goal is to minimize the sum of the ASCII values of the deleted
characters.

2. **Dynamic Programming Approach**:
    - Use a 2D DP table `dp` where `dp[i][j]` represents the minimum ASCII sum
of deleted characters to make `s1[i:]` and `s2[j:]` equal.
    - Base cases:
      - If one string is empty, the cost is the sum of ASCII values of the
remaining characters in the other string.
    - Recursive relation:
      - If `s1[i] == s2[j]`, no deletion is needed for these characters, so
`dp[i][j] = dp[i+1][j+1]`.
      - Otherwise, we have two choices:
         1. Delete `s1[i]` and add its ASCII value to the result: `dp[i][j] =
dp[i+1][j] + ASCII(s1[i])`.
         2. Delete `s2[j]` and add its ASCII value to the result: `dp[i][j] =
dp[i][j+1] + ASCII(s2[j])`.
      - Take the minimum of the two choices.

3. **Implementation Steps**:
    - Define a helper function `fallback` to calculate the sum of ASCII values
of the remaining characters in a string.
    - Use a recursive function `solve` with memoization to compute the result
for each state `(index1, index2)`.
    - Initialize the DP table with `-1` to indicate uncomputed states.
    - Start the recursion from the beginning of both strings (`index1 = 0`,
`index2 = 0`).
    - Return the result stored in `dp[0][0]`.

4. **Optimization**:
    - The solution uses memoization to avoid redundant computations, ensuring an
efficient time complexity of `O(n * m)`, where `n` and `m` are the lengths of
`s1` and `s2`.

5. **Edge Cases**:
    - One or both strings are empty.
    - Strings with no common characters.

The implementation provided in the `Solution` class follows this approach. The
`minimumDeleteSum` function initializes the DP table and starts the recursive
computation using the `solve` function. The `fallback` function handles the base
cases where one string is exhausted.
*/

class Solution {
  public:
    int fallback(string &a, int j) {
        int sum = 0;
        for (int i = j; i < a.size(); i++) {
            sum += int(a[i]);
        }
        return sum;
    }

    int solve(int index1, int index2, string &s1, string &s2,
              vector<vector<int>> &dp) {
        if (index1 == s1.size() && index2 == s2.size())
            return 0;
        if (index1 == s1.size())
            return fallback(s2, index2);
        if (index2 == s2.size())
            return fallback(s1, index1);

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        int sum;
        if (s1[index1] == s2[index2]) {
            sum = solve(index1 + 1, index2 + 1, s1, s2, dp);
        } else {
            sum = min(solve(index1 + 1, index2, s1, s2, dp) + int(s1[index1]),
                      solve(index1, index2 + 1, s1, s2, dp) + int(s2[index2]));
        }

        return dp[index1][index2] = sum;
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solve(0, 0, s1, s2, dp);
    }
};

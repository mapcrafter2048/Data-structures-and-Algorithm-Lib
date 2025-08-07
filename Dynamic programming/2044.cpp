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
Given an integer array nums, find the maximum possible bitwise OR of a subset of
nums and return the number of different non-empty subsets with the maximum
bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting
some (possibly zero) elements of b. Two subsets are considered different if the
indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1]
(0-indexed).
*/

/*
Logic and Steps of Implementation:

1. **Problem Understanding**:
    - We are tasked with finding the maximum possible bitwise OR of a subset of
an array `nums`.
    - Additionally, we need to count the number of subsets that achieve this
maximum bitwise OR.

2. **Key Observations**:
    - The bitwise OR operation is cumulative, meaning if we OR two numbers, the
result will have all the bits set that are set in either of the two numbers.
    - The maximum bitwise OR of the array can be calculated by OR-ing all the
elements of the array together.
    - The problem boils down to counting subsets whose bitwise OR equals this
maximum value.

3. **Approach**:
    - Use recursion with memoization (dynamic programming) to explore all
subsets of the array.
    - Maintain a `curr` variable to track the current bitwise OR value of the
subset being considered.
    - Use a `target` variable to store the maximum bitwise OR value of the
array.
    - For each element in the array, we have two choices:
      - Include the element in the current subset (update `curr` with OR
operation).
      - Exclude the element from the current subset.
    - Base Case:
      - If we reach the end of the array, check if `curr` equals `target`. If
yes, return 1 (valid subset), otherwise return 0.
    - Memoization:
      - Use a 2D `dp` array where `dp[index][curr]` stores the result of solving
the problem for a given `index` and `curr`.

4. **Steps of Implementation**:
    - Calculate the maximum bitwise OR (`maxi`) of the array by OR-ing all
elements.
    - Initialize a 2D `dp` array with dimensions `[n][maxi + 1]` and fill it
with `-1` to indicate uncomputed states.
    - Define a recursive function `solve` that takes the current index, current
OR value, target OR value, and the `dp` array as parameters.
    - Use the recursive function to explore all subsets and count the valid
ones.
    - Return the result of the recursive function starting from index 0 and
`curr = 0`.

5. **Complexity**:
    - Time Complexity: `O(n * maxi)` where `n` is the size of the array and
`maxi` is the maximum bitwise OR value.
    - Space Complexity: `O(n * maxi)` for the `dp` array and recursion stack.

6. **Code Implementation**:
    - The implementation is provided in the `countMaxOrSubsets` function and the
helper function `solve`.
*/

class Solution {
  public:
    int solve(vector<int> &nums, int index, int curr, int target,
              vector<vector<int>> &dp) {
        if (index == nums.size()) {
            if (curr == target) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[index][curr] != -1) {
            return dp[index][curr];
        }

        int nottake = solve(nums, index + 1, curr, target, dp);
        int take = solve(nums, index + 1, curr | nums[index], target, dp);

        return dp[index][curr] = nottake + take;
    }

    int countMaxOrSubsets(vector<int> &nums) {
        int n = nums.size();
        int maxi = 0;

        for (int x : nums) {
            maxi |= x;
        }

        vector<vector<int>> dp(n, vector<int>(maxi + 1, -1));

        return solve(nums, 0, 0, maxi, dp);
    }
};
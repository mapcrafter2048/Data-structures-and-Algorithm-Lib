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
You are given a 0-indexed array nums of n integers and an integer target.

You are initially positioned at index 0. In one step, you can jump from index i
to any index j such that:

    0 <= i < j < n
    -target <= nums[j] - nums[i] <= target

Return the maximum number of jumps you can make to reach index n - 1.

If there is no way to reach index n - 1, return -1.
*/

/*
Solution Logic:

The problem is to find the maximum number of jumps you can make to reach the
last index of the array, given the constraints on the difference between the
values at the indices. If it's not possible to reach the last index, return -1.

Steps of Implementation:

1. **Recursive Function with Memoization**:
    - Define a recursive function `solve(index, nums, target, dp)` that
calculates the maximum number of jumps starting from the given `index`.
    - Use a `dp` array for memoization to store the results of subproblems and
avoid redundant calculations.

2. **Base Case**:
    - If the current `index` is the last index (`nums.size() - 1`), return 0
because no further jumps are needed.

3. **Memoization Check**:
    - If the result for the current `index` is already computed (`dp[index] !=
-1`), return the stored result.

4. **Iterate Over Possible Jumps**:
    - For each possible jump from the current `index` to a future index `i`
(`index + 1` to `nums.size() - 1`):
      - Check if the absolute difference between `nums[i]` and `nums[index]` is
within the `target` range (`abs(nums[i] - nums[index]) <= target`).
      - If valid, recursively calculate the maximum jumps from `i` and update
the result for the current `index`.

5. **Store and Return the Result**:
    - Store the maximum number of jumps in `dp[index]` and return it.

6. **Driver Function**:
    - In the `maximumJumps` function, initialize the `dp` array with `-1` to
indicate uncomputed states.
    - Call the `solve` function starting from index 0.
    - If the result is non-negative, return it. Otherwise, return `-1` to
indicate that reaching the last index is not possible.

The algorithm uses a top-down dynamic programming approach with memoization to
optimize the recursive solution. The time complexity is approximately O(n^2),
where `n` is the size of the array, due to the nested loop structure.
*/

class Solution {
  public:
    int solve(int index, vector<int> &nums, int target, vector<int> &dp) {
        if (index == nums.size() - 1) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int ans = INT_MIN;
        for (int i = index + 1; i < nums.size(); i++) {
            if (abs(nums[i] - nums[index]) <= target) {
                ans = max(ans, 1 + solve(i, nums, target, dp));
            }
        }

        return dp[index] = ans;
    }

    int maximumJumps(vector<int> &nums, int target) {
        vector<int> dp(nums.size(), -1);
        int ans = solve(0, nums, target, dp);
        if (ans >= 0) {
            return ans;
        }

        return -1;
    }
};
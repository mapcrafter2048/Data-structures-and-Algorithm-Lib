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
You are given an integer array nums with length n.

The cost of a

nums[l..r], where 0 <= l <= r < n, is defined as:

cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)r − l

Your task is to split nums into subarrays such that the total cost of the
subarrays is maximized, ensuring each element belongs to exactly one subarray.

Formally, if nums is split into k subarrays, where k > 1, at indices i1, i2,
..., ik − 1, where 0 <= i1 < i2 < ... < ik - 1 < n - 1, then the total cost will
be:

cost(0, i1) + cost(i1 + 1, i2) + ... + cost(ik − 1 + 1, n − 1)

Return an integer denoting the maximum total cost of the subarrays after
splitting the array optimally.

Note: If nums is not split into subarrays, i.e. k = 1, the total cost is simply
cost(0, n - 1).
*/

/*
Detailed Solution and Steps of Implementation:

Problem Analysis:
1. The problem involves splitting an array `nums` into subarrays such that the
total cost of the subarrays is maximized.
2. The cost of a subarray `nums[l..r]` is defined as:
    cost(l, r) = nums[l] - nums[l + 1] + nums[l + 2] - nums[l + 3] + ... +
nums[r] * (-1)^(r - l) This alternates between addition and subtraction based on
the index difference.
3. If the array is split into multiple subarrays, the total cost is the sum of
the costs of all subarrays.

Approach:
1. Use dynamic programming to solve the problem optimally.
2. Define a recursive function `solve(index, nums, take, dp)`:
    - `index` represents the current position in the array.
    - `take` is a boolean indicating whether the current element is being added
or subtracted.
    - `dp` is a memoization table to store intermediate results and avoid
redundant calculations.
3. Base Case:
    - If `index` reaches the end of the array, return 0 as there are no more
elements to process.
4. Recursive Case:
    - If `take` is true, add the current element to the cost and recursively
process the next element with `take = false`.
    - If `take` is false, subtract the current element from the cost and
recursively process the next element with `take = true`.
    - Additionally, consider starting a new subarray from the current index and
calculate its cost.
    - Take the maximum of the above options to maximize the total cost.
5. Use a 2D `dp` table to store results for each `index` and `take` state to
avoid recomputation.

Steps of Implementation:
1. Define the recursive function `solve` with parameters `index`, `nums`,
`take`, and `dp`.
2. Implement the base case to return 0 when `index` equals the size of the
array.
3. Check if the result for the current state is already computed in `dp`. If
yes, return it.
4. Compute the cost for the current element based on the `take` flag and
recursively calculate the cost for the next element.
5. Consider starting a new subarray and calculate its cost.
6. Store the maximum of the computed costs in the `dp` table and return it.
7. In the `maximumTotalCost` function:
    - Initialize the `dp` table with `INT_MIN` to indicate uncomputed states.
    - Call the `solve` function starting from index 0 with `take = true` to
maximize the total cost.
8. Return the result from the `solve` function as the final answer.
*/

class Solution {
  public:
    long long int solve(long long int index, vector<int> &nums, bool take,
                        vector<vector<long long int>> &dp) {
        if (index == nums.size()) {
            return 0;
        }
        if (dp[index][take] != INT_MIN) {
            return dp[index][take];
        }

        long long int old = 0;
        if (take) {
            old = nums[index] + solve(index + 1, nums, false, dp);
        } else {
            old = -(nums[index]) + solve(index + 1, nums, true, dp);
        }

        long long int newV = nums[index] + solve(index + 1, nums, false, dp);

        return dp[index][take] = max(old, newV);
    }

    long long maximumTotalCost(vector<int> &nums) {
        long long int n = nums.size();
        vector<vector<long long int>> dp(n + 1,
                                         vector<long long int>(2, INT_MIN));
        return solve(0, nums, true, dp);
    }
};
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
You are given an integer array prices where prices[i] is the price of a given
stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at
most one share of the stock at any time. However, you can buy it then
immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/

/*
Detailed Solution Logic:

The problem is to maximize the profit from stock trading, where you can buy and
sell stocks multiple times, but you can only hold at most one stock at a time.
This means you cannot buy another stock until you sell the one you currently
hold.

### Steps of Implementation:

1. **Recursive Approach with Memoization**:
    - Use a recursive function `solve` to explore all possible states of buying
and selling stocks.
    - The function takes the following parameters:
      - `index`: The current day in the `prices` array.
      - `buy`: A flag indicating whether we are allowed to buy (1) or sell (0)
on the current day.
      - `prices`: The array of stock prices.
      - `dp`: A 2D vector for memoization to store the results of subproblems.

2. **Base Case**:
    - If `index` is greater than or equal to the size of the `prices` array,
return 0 because no more transactions can be made.

3. **Memoization Check**:
    - If the result for the current state (`index`, `buy`) is already computed
and stored in `dp`, return it to avoid redundant calculations.

4. **Recursive Cases**:
    - If `buy == 1` (we are allowed to buy):
      - We have two choices:
         1. Buy the stock on the current day, which decreases our profit by
`prices[index]`, and move to the next day with `buy = 0` (not allowed to buy
again until we sell).
         2. Skip buying and move to the next day with `buy = 1`.
      - Take the maximum of these two choices.
    - If `buy == 0` (we are allowed to sell):
      - We have two choices:
         1. Sell the stock on the current day, which increases our profit by
`prices[index]`, and move to the next day with `buy = 1` (allowed to buy again).
         2. Skip selling and move to the next day with `buy = 0`.
      - Take the maximum of these two choices.

5. **Store the Result**:
    - Store the result of the current state (`index`, `buy`) in `dp` to avoid
recalculating it in the future.

6. **Driver Function**:
    - The `maxProfit` function initializes the `dp` table with `-1` to indicate
uncomputed states and calls the `solve` function starting from day 0 with `buy =
1` (allowed to buy).

### Complexity:
- **Time Complexity**: O(n * 2) = O(n), where `n` is the size of the `prices`
array. This is because there are `n` days and 2 possible states (`buy = 0` or
`buy = 1`) for each day, and each state is computed only once due to
memoization.
- **Space Complexity**: O(n * 2) = O(n) for the `dp` table, plus O(n) for the
recursion stack.

This approach ensures that we explore all possible transactions while avoiding
redundant calculations, leading to an optimal solution.
*/

class Solution {
  public:
    int solve(int index, int buy, vector<int> &prices,
              vector<vector<int>> &dp) {
        int n = prices.size();
        if (index >= n) {
            return 0;
        }

        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + solve(index + 1, 0, prices, dp),
                         solve(index + 1, 1, prices, dp));
        } else {
            profit = max(prices[index] + solve(index + 1, 1, prices, dp),
                         solve(index + 1, 0, prices, dp));
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int> &prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};

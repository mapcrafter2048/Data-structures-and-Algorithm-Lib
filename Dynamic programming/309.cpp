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

class Solution {
  public:
    int solve(int index, bool buy, int n, vector<int> &prices,
              vector<vector<int>> &dp) {
        if (index >= n)
            return 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];

        if (buy) {
            int b = solve(index + 1, !buy, n, prices, dp) - prices[index];
            int nb = solve(index + 1, buy, n, prices, dp);

            dp[index][buy] = max(b, nb);
        } else {
            int s = solve(index + 2, !buy, n, prices, dp) + prices[index];
            int ns = solve(index + 1, buy, n, prices, dp);

            dp[index][buy] = max(s, ns);
        }
        return dp[index][buy];
    }

    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, true, n, prices, dp);
    }
};

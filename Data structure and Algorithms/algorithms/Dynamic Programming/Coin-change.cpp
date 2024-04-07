#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

int solve(vector<int> &coins, vector<vector<int>> &dp, int currentCoin, int amount)
{
    // invalid case as the amount is negative or the currentCoin is greater than the size of coins
    if (currentCoin >= coins.size() || amount < 0)
    {
        return INT_MAX;
    }

    // if the amount is 0 then return 0
    if (amount == 0)
    {
        return 0;
    }

    if (dp[currentCoin][amount] != -1)
    {
        return dp[currentCoin][amount];
    }

    if (coins[currentCoin] > amount)
    {
        return dp[currentCoin][amount] = solve(coins, dp, currentCoin + 1, amount);
    }
    else
    {

        int take = (solve(coins, dp, currentCoin, amount - coins[currentCoin]) == INT_MAX ? INT_MAX : 1 + solve(coins, dp, currentCoin, amount - coins[currentCoin])); // take the current coin and call the function again with the same coin
        int notTake = solve(coins, dp, currentCoin + 1, amount);
        dp[currentCoin][amount] = min(take, notTake);
        return dp[currentCoin][amount];
    }
}

int coinChange(vector<int> &coins, int amount)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int result = solve(coins, dp, 0, amount);
    return result == INT_MAX ? -1 : result;
}

int main()
{
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
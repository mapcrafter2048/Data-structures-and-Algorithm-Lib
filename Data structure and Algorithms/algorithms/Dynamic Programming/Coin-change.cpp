/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

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
    // for invalid case we are assigning INT_MAX because we are taking the minimum of the two cases
    if (currentCoin >= coins.size() || amount < 0)
    {
        return INT_MAX;
    }

    // if the amount is 0 then return 0
    if (amount == 0)
    {
        return 0;
    }

    // if the value is already calculated then return the value
    if (dp[currentCoin][amount] != -1)
    {
        return dp[currentCoin][amount];
    }

    // if the current coin is greater than the amount then call the function with the next coin
    if (coins[currentCoin] > amount)
    {
        return dp[currentCoin][amount] = solve(coins, dp, currentCoin + 1, amount);
    }
    else
    {
        // take the current coin and call the function again with the same coin
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

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
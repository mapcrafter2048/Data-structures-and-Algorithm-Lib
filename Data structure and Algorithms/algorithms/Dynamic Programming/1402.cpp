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

int solve(int i, int time, vector<vector<int>> &dp,
          vector<int> &satisfaction)
{
    int n = satisfaction.size();
    if (i == n)
    {
        return 0;
    }

    if (dp[i][time] != -1)
    {
        return dp[i][time];
    }

    return dp[i][time] = max((satisfaction[i] * time +
                              solve(i + 1, time + 1, dp, satisfaction)),
                             solve(i + 1, time, dp, satisfaction));
}

int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    sort(satisfaction.begin(), satisfaction.end());

    return solve(0, 1, dp, satisfaction);
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
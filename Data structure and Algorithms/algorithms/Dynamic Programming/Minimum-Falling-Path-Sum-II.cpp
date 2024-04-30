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

int minFallingPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = grid[0][j];
    }

    for (int row = 1; row < n; row++)
    {
        for (int colA = 0; colA < n; colA++)
        {
            int ans = INT_MAX;
            for (int colB = 0; colB < n; colB++)
            {
                if (k != j)
                {
                    ans = min(ans, grid[row][ColA] + dp[row - 1][ColB]);
                }
                dp[row][colA] = ans;
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }

    return ans;
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
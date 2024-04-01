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

bool solve(int n, vector<int> &dp)
{
    if (n == 1)
    {
        return true;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    bool result = false;
    if (n % 2 == 0)
    {
        result = result || solve(n / 2, dp);
    }
    if (n % 3 == 0)
    {
        result = result || solve(n / 3, dp);
    }
    if (n % 5 == 0)
    {
        result = result || solve(n / 5, dp);
    }
    dp[n] = result;
    return result;
}

pair<int, vector<int>> nthUglyNumber(int n)
{
    vector<int> dp(n + 1, -1);
    dp[1] = 1;

    int count = 1;
    int current = 2;
    vector<int> uglyNumbers;

    while (count < n)
    {
        if (solve(current, dp))
        {
            count++;
            uglyNumbers.push_back(current);
        }
        current++;
    }

    return {current - 1, uglyNumbers};
}

int main()
{
    auto start = high_resolution_clock::now();

    pair<int, vector<int>> result = nthUglyNumber(1690);
    cout << "The " << 1690 << "th ugly number is: " << result.first << endl;
    cout << "The ugly numbers are: ";
    for (int i = 0; i < result.second.size(); i++)
    {
        cout << result.second[i] << " ";
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
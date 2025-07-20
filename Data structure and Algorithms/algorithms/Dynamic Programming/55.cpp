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

bool solve(int i, vector<int> &nums, vector<int> &dp)
{
    if (i >= nums.size() - 1)
    {
        return true;
    }
    if (nums[i] == 0)
    {
        return false;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    for (int j = 1; j <= nums[i]; j++)
    {
        if (solve(i + j, nums, dp))
        {
            return dp[i] = true;
        }
    }
    return dp[i] = false;
}

bool canJump(vector<int> &nums, int n)
{
    vector<int> dp(n, -1);
    return (solve(0, nums, dp));
}

int main()
{
    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening input.txt" << endl;
        return 1; // Indicate failure
    }

    int numTestCases;
    inputFile >> numTestCases;

    auto start = high_resolution_clock::now();

    for (int testCase = 1; testCase <= numTestCases; ++testCase)
    {
        int arraySize;
        inputFile >> arraySize;

        vector<int> nums(arraySize);
        for (int i = 0; i < arraySize; ++i)
        {
            inputFile >> nums[i];
        }

        bool result = canJump(nums, arraySize);

        cout << "Test Case " << testCase << ": ";
        cout << (result ? "Can Jump" : "Cannot Jump") << endl;
    }

    inputFile.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}
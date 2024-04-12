/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.
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

int solve(int target, vector<int> &dp, vector<int> &nums)
{
    if (target == 0)
    {
        return 1;
    }

    if (target < 0)
    {
        return 0;
    }

    if (dp[target] != -1)
    {
        return dp[target];
    }

    int answer = 0;
    // for each number in the array we will call the function with the target - nums[i] and add the result to the answer
    for (int i = 0; i < nums.size(); i++)
    {
        answer += solve(target - nums[i], dp, nums);
    }

    dp[target] = answer;
    return dp[target];
}

int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, -1);
    return solve(target, dp, nums);
}

int main()
{
    auto start = high_resolution_clock::now();

    ifstream inputFile("Combination-Sum-IV-Test-Cases.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening input.txt" << endl;
        return 1; // Indicate failure
    }

    int numTestCases;
    inputFile >> numTestCases;

    for (int testCase = 1; testCase <= numTestCases; ++testCase)
    {
        int arraySize;
        inputFile >> arraySize;

        int targetSum;
        inputFile >> targetSum;

        vector<int> nums(arraySize);
        for (int i = 0; i < arraySize; ++i)
        {
            inputFile >> nums[i];
        }

        bool result = combinationSum4(nums, targetSum);
        ofstream outputFile("Combination-Sum-IV-output.txt", ios::app);
        outputFile << "Test Case " << testCase << ": " << result << endl;
        cout << targetSum << endl;
        cout << arraySize << endl;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
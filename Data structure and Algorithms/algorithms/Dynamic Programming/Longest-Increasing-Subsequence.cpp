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

int longestIncreasingSubsequenceDp(int size, vector<int> nums, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr == size)
    {
        return 0;
    }

    if (dp[curr][prev] != -1)
    {
        return dp[curr][prev];
    }

    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + longestIncreasingSubsequenceDp(size, nums, curr + 1, curr, dp);
    }

    int exclude = longestIncreasingSubsequenceDp(size, nums, curr + 1, prev, dp);

    return dp[curr][prev + 1] = max(include, exclude);
}

/*
The function starts by getting the size n of the input vector A. It then creates a new vector ans of size n, initializing all elements to 1. This ans vector will store the length of the longest increasing subsequence ending at each position in A.

The function then enters a nested loop. The outer loop iterates over each element in A from the first to the last. The inner loop, for each i, iterates over all previous elements in A (from the first to the i-th). If the i-th element of A is greater than the j-th element and the length of the longest increasing subsequence ending at j plus 1 is greater than the current length of the longest increasing subsequence ending at i, it increments the i-th element of ans.

In the context of the longest increasing subsequence problem, each entry dp[i] usually represents the length of the longest increasing subsequence ending at position i.
*/

pair<int, vector<int>> longestIncreasingSubsequence(vector<int> A)
{
    int n = A.size();
    vector<int> ans(n, 1);
    ans[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // if the next element is greater than the pervious element and if we can increase the length of the subsequence
            if (A[i] > A[j] && ans[j] + 1 > ans[i])
            {
                ans[i]++;
            }
        }
    }

    int max = *max_element(ans.begin(), ans.end());

    return {max, ans};
}

int main()
{
    auto start = high_resolution_clock::now();

    ifstream inputFile("input.txt");
    ofstream outputFile("Longest-Increasing-Subsequence-output.txt");

    if (!inputFile)
    {
        cerr << "Error opening input file" << endl;
        return -1;
    }

    int TestCases;
    inputFile >> TestCases;

    int i = 0;

    while (TestCases--)
    {
        i++;
        int n;
        inputFile >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            inputFile >> A[i];
        }

        pair<int, vector<int>> result = longestIncreasingSubsequence(A);
        outputFile << "Test Case " << i << ": ";
        outputFile << "Length of Longest Increasing Subsequence: " << result.first << endl;
        outputFile << "Longest Increasing Subsequence: ";
        for (int i = 0; i < n; i++)
        {
            outputFile << result.second[i] << " ";
        }
        outputFile << endl;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
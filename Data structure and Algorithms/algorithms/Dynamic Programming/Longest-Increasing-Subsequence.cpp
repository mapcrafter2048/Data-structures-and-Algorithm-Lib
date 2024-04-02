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

pair<int, vector<int>> longestIncreasingSubsequence(vector<int> A)
{
    int n = A.size();
    vector<int> ans(n, 1);
    ans[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
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
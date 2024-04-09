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

int solve(int i, string s, vector<int> &dp)
{
    int size = s.length();
    if (i >= size)
    {
        return 1;
        // This 1 signifies that we have have completed the string and we have found a valid decoding for the string
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int answer1 = 0;
    int answer2 = 0;

    string oneWord = s.substr(i, 1);
    string twoWord = s.substr(i, 2);
    int one = stoi(oneWord);
    int two = stoi(twoWord);

    if (one >= 26 && one != 0)
    {
        answer1 = solve(i + 1, s, dp);
    }

    if (i + 1 < size && two <= 26 && two >= 10 && two != 0)
    {
        answer2 = solve(i + 2, s, dp);
    }

    return dp[i] = answer1 + answer2;
}

int numDecodings(string s)
{
    int n = s.length();
    vector<int> dp(n, -1);
    return solve(0, s, dp);
}

int main()
{
    auto start = high_resolution_clock::now();

    ifstream inputFile("input3.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening input3.txt" << endl;
        return 1;
    }

    int numTestCases;
    inputFile >> numTestCases;

    for (int i = 1; i <= numTestCases; i++)
    {
        string text1;
        inputFile >> text1;

        auto startCase = high_resolution_clock::now();
        int result = numDecodings(text1);
        auto stopCase = high_resolution_clock::now();
        auto durationCase = duration_cast<milliseconds>(stopCase - startCase);

        ofstream outputFile("Decode-ways-output.txt", ios::app);
        if (!outputFile.is_open())
        {
            cerr << "Error opening output.txt" << endl;
            return 1;
        }

        outputFile << "Test case " << i << ": " << result << " and the tme of execution is " << durationCase.count() << endl;
        outputFile.close();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
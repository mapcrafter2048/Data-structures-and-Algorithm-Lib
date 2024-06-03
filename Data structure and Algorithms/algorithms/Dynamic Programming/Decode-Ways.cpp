/*
A message containing letters from A-Z can be encoded into numbers using the
following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back
into letters using the reverse of the mapping above (there may be multiple
ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into
'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
*/
#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

int solve(int i, string s, vector<int> &dp) {
    int size = s.length();
    if (i >= size) {
        return 1;
        // This 1 signifies that we have have completed the string and we have
        // found a valid decoding for the string
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    int answer1 = 0;
    int answer2 = 0;

    string oneWord = s.substr(i, 1);
    string twoWord = s.substr(i, 2);
    int one = stoi(oneWord);
    int two = stoi(twoWord);

    // This is the case when we have a single digit number and we can decode it
    if (one <= 26 && one != 0) {
        answer1 = solve(i + 1, s, dp);
    }

    // This is the case when we have a double digit number and we can decode it
    // and the additional condition is that the number should be less than 26
    // and greater than 10 and the index should be less than the size of the
    // string
    if (i + 1 < size && two <= 26 && two >= 10 && two != 0) {
        answer2 = solve(i + 2, s, dp);
    }

    return dp[i] = answer1 + answer2;
}

int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n, -1);
    return solve(0, s, dp);
}

int main() {
    auto start = high_resolution_clock::now();

    ifstream inputFile("input3.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input3.txt" << endl;
        return 1;
    }

    int numTestCases;
    inputFile >> numTestCases;

    for (int i = 1; i <= numTestCases; i++) {
        string text1;
        inputFile >> text1;

        auto startCase = high_resolution_clock::now();
        int result = numDecodings(text1);
        auto stopCase = high_resolution_clock::now();
        auto durationCase = duration_cast<milliseconds>(stopCase - startCase);

        ofstream outputFile("Decode-ways-output.txt", ios::app);
        if (!outputFile.is_open()) {
            cerr << "Error opening output.txt" << endl;
            return 1;
        }

        outputFile << "Test case " << i << ": " << result
                   << " and the tme of execution is " << durationCase.count()
                   << endl;
        outputFile.close();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
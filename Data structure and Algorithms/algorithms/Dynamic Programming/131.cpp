#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
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

vector<vector<string>> partition(string s) {
    // Main function: Finds all palindrome partitions of string 's'
    vector<vector<string>> res; // Stores all valid palindrome partitions
    vector<string> path;        // Stores the current partition being built
    solve(0, s, path, res);     // Starts recursive partitioning from index 0
    return res;                 // Returns all found partitions
}

bool isPalindrome(string s, int start, int end) {
    // Helper function: Checks if substring from 'start' to 'end' is a
    // palindrome
    while (start < end) {
        if (s[start] != s[end]) { // If characters don't match, not a palindrome
            return false;
        }
        start++; // Move towards center from both ends
        end--;
    }
    return true; // All characters matched, it's a palindrome
}

void solve(int index, string s, vector<string> &path,
           vector<vector<string>> &res) {
    // Recursive function to explore partitions
    if (index == s.size()) { // Base case: reached the end of the string
        res.push_back(path); // Add the current partition 'path' to results
        return;              // Backtrack from here
    }

    for (int i = index; i < s.size();
         ++i) { // Iterate through potential palindrome ends
        if (isPalindrome(s, index, i)) { // If substring is a palindrome
            path.push_back(s.substr(index, i - index + 1)); // Add it to 'path'
            solve(i + 1, s, path,
                  res); // Recurse to the next character after the palindrome
            path.pop_back(); // Backtrack: remove the last palindrome for
                             // exploring other options
        }
    }
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
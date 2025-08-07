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

/*
You are given a string s and an array of strings words. All the strings of words
are of the same length.

A concatenated string is a string that exactly contains all the strings of any
permutation of words concatenated.

    For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef",
"cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a
concatenated string because it is not the concatenation of any permutation of
words.

Return an array of the starting indices of all the concatenated substrings in s.
You can return the answer in any order.
*/

/*
This is a sliding window problem where we need to find all starting indices
of substrings in s that are concatenations of all words in the given list. The
idea is to use a hashmap to count the occurrences of each word in the list
and then use a sliding window to find all valid substrings in s.
*/

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (words.empty())
            return {};
        int wordLen = words[0].size();
        int m = words.size();
        int n = s.size();

        unordered_map<string, int> need;
        for (auto &w : words)
            need[w]++;

        vector<int> ans;

        // Iterate over each possible starting offset for the sliding window
        // This allows us to handle cases where the words might not start at
        // index 0
        for (int off = 0; off < wordLen; ++off) {
            unordered_map<string, int> seen;
            int left = off, count = 0;
            // Slide the window across the string s
            for (int right = off; right + wordLen <= n; right += wordLen) {
                string w = s.substr(right, wordLen);
                // If the word is not in the need map, reset the window
                if (need.count(w) == 0) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                seen[w]++;
                count++;
                // If we have seen too many instances of the current word,
                // we need to move the left pointer to maintain the valid window
                while (seen[w] > need[w]) {
                    string lw = s.substr(left, wordLen);
                    seen[lw]--;
                    left += wordLen;
                    count--;
                }
                // If we have a valid window, add the starting index to the
                // result
                if (count == m) {
                    ans.push_back(left);
                    string lw = s.substr(left, wordLen);
                    seen[lw]--;
                    left += wordLen;
                    count--;
                }
            }
        }
        return ans;
    }
};
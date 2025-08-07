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
Given an array of strings words representing an English Dictionary, return the
longest word in words that can be built one character at a time by other words
in words.

If there is more than one possible answer, return the longest word with the
smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional
character being added to the end of a previous word.
*/

/*
Solution Logic and Steps of Implementation:

1. **Problem Understanding**:
    - We are given a list of words (`words`) representing an English dictionary.
    - The goal is to find the longest word that can be built one character at a
time by other words in the list.
    - If there are multiple valid answers, return the lexicographically smallest
one.
    - If no such word exists, return an empty string.

2. **Approach**:
    - Sort the words lexicographically. This ensures that shorter words and
lexicographically smaller words come first.
    - Use a hash set (`unordered_set`) to store valid words that can be used to
build longer words.
    - Iterate through the sorted list of words:
      - If the word has only one character or its prefix (all characters except
the last one) exists in the hash set, it is valid.
      - Add the valid word to the hash set.
      - Update the result (`ans`) if the current word is longer than the
previous result or if it is lexicographically smaller when the lengths are the
same.

3. **Steps of Implementation**:
    - Sort the input list of words.
    - Initialize an empty hash set (`good`) to store valid words.
    - Initialize an empty string (`ans`) to store the result.
    - Iterate through each word in the sorted list:
      - Check if the word is valid (either it has one character or its prefix
exists in the hash set).
      - If valid, add it to the hash set.
      - Update the result if the current word is better (longer or
lexicographically smaller).
    - Return the result after processing all words.

4. **Complexity Analysis**:
    - Sorting the words takes \(O(n \log n)\), where \(n\) is the number of
words.
    - Iterating through the words and performing operations on the hash set
takes \(O(n \cdot k)\), where \(k\) is the average length of the words.
    - Overall time complexity: \(O(n \log n + n \cdot k)\).
    - Space complexity: \(O(n \cdot k)\) for storing the words in the hash set.

5. **Edge Cases**:
    - Empty input list: Return an empty string.
    - Words with no valid prefixes: Return an empty string.
    - Multiple valid answers: Return the lexicographically smallest one.
*/

class Solution {
  public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end());
        unordered_set<string> good;
        string ans = "";

        for (auto &w : words) {
            if (w.size() == 1 || good.count(w.substr(0, w.size() - 1))) {
                good.insert(w);
                if (w.size() > ans.size() ||
                    (w.size() == ans.size() && w < ans)) {
                    ans = w;
                }
            }
        }

        return ans;
    }
};

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
Sometimes people repeat letters to represent extra feeling. For example:

    "hello" -> "heeellooo"
    "hi" -> "hiiii"

In these strings like "heeellooo", we have groups of adjacent letters that are
all the same: "h", "eee", "ll", "ooo".

You are given a string s and an array of query strings words. A query word is
stretchy if it can be made to be equal to s by any number of applications of the
following extension operation: choose a group consisting of characters c, and
add some number of characters c to the group so that the size of the group is
three or more.

    For example, starting with "hello", we could do an extension on the group
"o" to get "hellooo", but we cannot get "helloo" since the group "oo" has a size
less than three. Also, we could do another extension like "ll" -> "lllll" to get
"helllllooo". If s = "helllllooo", then the query word "hello" would be stretchy
because of these two extension operations: query = "hello" -> "hellooo" ->
"helllllooo" = s.

Return the number of query strings that are stretchy.
*/

/*
Logic and Steps of Implementation:

1. **Understanding the Problem**:
    - The goal is to determine how many words in the `words` array can be
transformed into the string `s` by stretching groups of characters in `s`.
    - Stretching means increasing the size of a group of identical characters in
`s` to three or more, while ensuring the transformed word matches `s`.

2. **Steps to Solve**:
    - **Step 1**: Create a helper function `getgroup` to group consecutive
identical characters in a string along with their counts.
      - Example: For "heeellooo", the groups would be `{'h', 1}, {'e', 3}, {'l',
2}, {'o', 3}`.
    - **Step 2**: Create another helper function `help` to compare the groups of
`s` and a word from `words`.
      - Ensure the groups match in character and satisfy the stretching
conditions.
    - **Step 3**: Implement the main function `expressiveWords`:
      - Generate groups for `s` using `getgroup`.
      - Iterate through each word in `words`, generate its groups, and use
`help` to check if the word is stretchy.
      - Count and return the number of stretchy words.

3. **Key Conditions**:
    - A group in `s` can be stretched only if its size is 3 or more.
    - The size of the group in `s` must be greater than or equal to the size of
the corresponding group in the word.

4. **Implementation**:
    - The solution uses two helper functions (`getgroup` and `help`) and the
main function (`expressiveWords`) to solve the problem efficiently.
    - The complexity is driven by the grouping operation and comparison for each
word in `words`.

*/

class Solution {
  public:
    vector<pair<char, int>> getgroup(const string &str) {
        vector<pair<char, int>> groups;
        int n = str.size();
        int i = 0;

        while (i < n) {
            char curr = str[i];
            int count = 0;
            while (i < n && str[i] == curr) {
                i++;
                count++;
            }
            groups.push_back({curr, count});
        }

        return groups;
    }

    bool help(const vector<pair<char, int>> &sGroups,
              const vector<pair<char, int>> &wGroups) {
        if (sGroups.size() != wGroups.size()) {
            return false;
        }

        for (int i = 0; i < sGroups.size(); i++) {
            char schar = sGroups[i].first;
            int scount = sGroups[i].second;
            char wchar = wGroups[i].first;
            int wcount = wGroups[i].second;

            if (schar != wchar) {
                return false;
            }

            if (scount == wcount) {
                continue;
            }

            if (scount >= 3 && scount >= wcount) {
                continue;
            }

            return false;
        }

        return true;
    }

    int expressiveWords(string s, vector<string> &words) {
        vector<pair<char, int>> sGroups = getgroup(s);
        int ans = 0;

        for (string word : words) {
            vector<pair<char, int>> wGroups = getgroup(word);
            if (help(sGroups, wGroups)) {
                ans++;
            }
        }

        return ans;
    }
};

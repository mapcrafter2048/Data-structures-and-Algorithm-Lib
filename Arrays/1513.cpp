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
Given a binary string s, return the number of substrings with all characters
1's. Since the answer may be too large, return it modulo 109 + 7.
*/

// Solution Explanation:
// The problem is to count the number of substrings in a binary string `s` where
// all characters are '1's. Since the result can be large, we return the answer
// modulo 10^9 + 7.

// Steps of Implementation:
// 1. Define a constant `MOD` to store the modulo value (10^9 + 7).
// 2. Create a vector `grp` to store the lengths of consecutive '1's groups in
// the string.
// 3. Traverse the string `s`:
//    - If the current character is '1' and it is the start of a new group
//    (either the first character or the previous character is '0'),
//      add a new group with length 1 to `grp`.
//    - If the current character is '1' and it is part of an existing group,
//    increment the length of the last group in `grp`.
// 4. Initialize a variable `ans` to store the result.
// 5. For each group length in `grp`, calculate the number of substrings that
// can be formed using the formula:
//    - For a group of length `len`, the number of substrings is `len * (len +
//    1) / 2`.
//    - Add this value to `ans` modulo `MOD`.
// 6. Return the final value of `ans` as the result.

class Solution {
  public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        vector<int> grp;

        if (s[0] == '1') {
            grp.push_back(1);
        }

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') {
                if (s[i - 1] == '1') {
                    grp.back()++; // increment last group's count
                } else {
                    grp.push_back(1); // start a new group
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < grp.size(); i++) {
            long long len = grp[i];
            ans = (ans + (len * (len + 1) / 2) % MOD) % MOD;
        }

        return ans;
    }
};

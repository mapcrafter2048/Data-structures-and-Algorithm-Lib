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
Given a binary string s, return the number of non-empty substrings that have the
same number of 0's and 1's, and all the 0's and all the 1's in these substrings
are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.
*/

/*
Solution Logic and Steps of Implementation:

1. **Problem Understanding**:
    - We need to count the number of non-empty substrings in a binary string `s`
such that:
      - The number of `0`s and `1`s in the substring are equal.
      - All `0`s and all `1`s in the substring are grouped consecutively.
    - For example, in the string "00110011", valid substrings are "0011", "01",
"1100", "10", "0011", "01".

2. **Approach**:
    - Group consecutive `0`s and `1`s together and count their lengths.
    - Use these group lengths to calculate the number of valid substrings.

3. **Steps**:
    - Traverse the string and group consecutive characters together, storing
their lengths in a vector `group`.
    - For example, for the string "00110011", the `group` vector will be `[2, 2,
2, 2]` (2 `0`s, 2 `1`s, 2 `0`s, 2 `1`s).
    - Iterate through the `group` vector and calculate the number of valid
substrings by taking the minimum of two adjacent group lengths (e.g.,
`min(group[i-1], group[i])`).
    - Sum up these values to get the total count of valid substrings.

4. **Implementation**:
    - Use a vector `group` to store the lengths of consecutive characters.
    - Traverse the string to populate the `group` vector.
    - Iterate through the `group` vector to calculate the result.

5. **Complexity**:
    - Time Complexity: O(n), where `n` is the length of the string `s`. This is
because we traverse the string once to populate the `group` vector and once to
calculate the result.
    - Space Complexity: O(n), for storing the `group` vector.

The implementation of this logic is provided in the `countBinarySubstrings`
function.
*/

class Solution {
  public:
    int countBinarySubstrings(string s) {
        vector<int> group(s.size());
        int k = 0;
        // Initialize the first group length to 1 as the first character is
        // always counted
        group[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] != s[i]) {
                group[++k] = 1;
            } else {
                group[k]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            ans += min(group[i - 1], group[i]);
        }

        return ans;
    }
};
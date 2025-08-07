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
You have intercepted a secret message encoded as a string of numbers. The
message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different
ways you can decode the message because some codes are contained in other codes
("2" and "5" vs "25").

For example, "11106" can be decoded into:

    "AAJF" with the grouping (1, 1, 10, 6)
    "KJF" with the grouping (11, 10, 6)
    The grouping (1, 11, 06) is invalid because "06" is not a valid code (only
"6" is valid).

Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it.
If the entire string cannot be decoded in any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.
*/

/*
Detailed Solution Logic:

The problem is to determine the number of ways to decode a string of digits into
letters using the given mapping. This is a classic dynamic programming problem
where we break the problem into smaller subproblems and solve them recursively
with memoization.

Steps of Implementation:

1. **Base Case**:
    - If the current index `i` is greater than or equal to the length of the
string `s`, it means we have successfully decoded the string, so we return 1.

2. **Memoization**:
    - Use a `dp` array to store the results of subproblems. If `dp[i]` is not
`-1`, it means we have already computed the result for index `i`, so we return
`dp[i]`.

3. **Recursive Cases**:
    - Decode one digit:
      - Extract the substring of length 1 starting at index `i` and convert it
to an integer.
      - If the integer is between 1 and 26 (inclusive) and not 0, recursively
solve for the next index (`i + 1`).
    - Decode two digits:
      - Extract the substring of length 2 starting at index `i` and convert it
to an integer.
      - If the integer is between 10 and 26 (inclusive), recursively solve for
the index after the next (`i + 2`).

4. **Combine Results**:
    - The total number of ways to decode the string starting at index `i` is the
sum of the results from decoding one digit and two digits.

5. **Edge Cases**:
    - If the string starts with '0', it is invalid and cannot be decoded, so the
result is 0.

6. **Driver Function**:
    - The `numDecodings` function initializes the `dp` array with `-1` and calls
the recursive `solve` function starting from index 0.

By following this approach, we ensure that each subproblem is solved only once,
making the solution efficient with a time complexity of O(n) and space
complexity of O(n) due to the `dp` array.

*/

class Solution {
  public:
    int solve(string &s, int i, vector<int> &dp) {

        if (i >= s.length()) {
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int ans1 = 0, ans2 = 0;

        string oneDigit = s.substr(i, 1);
        int one1 = stoi(oneDigit);
        if (one1 <= 26 && one1 != 0) {
            ans1 = solve(s, i + 1, dp);
        }

        string twoDigit = s.substr(i, 2);
        int two2 = stoi(twoDigit);
        if (i + 1 < s.length() && two2 <= 26 && two2 != 0 && two2 >= 10)
            ans2 = solve(s, i + 2, dp);
        return dp[i] = ans2 + ans1;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, -1);
        return solve(s, 0, dp);
    }
};
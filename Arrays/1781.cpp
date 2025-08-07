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
The beauty of a string is the difference in frequencies between the most
frequent and least frequent characters.

    For example, the beauty of "abaacc" is 3 - 1 = 2.

Given a string s, return the sum of beauty of all of its substrings.
*/

/*
To solve the problem, we need to calculate the "beauty" of all substrings of a
given string `s`. The beauty of a substring is defined as the difference between
the maximum frequency and the minimum frequency of characters in that substring.

### Steps to Solve the Problem:

1. **Iterate Over All Substrings**:
    - Use two nested loops to generate all substrings of the string `s`.
    - The outer loop starts the substring at index `i`, and the inner loop
extends the substring to index `j`.

2. **Track Character Frequencies**:
    - For each substring, maintain a frequency array `freq` of size 26 (for all
lowercase English letters).
    - Increment the frequency of the character at position `j` in the substring.

3. **Calculate Maximum and Minimum Frequencies**:
    - After updating the frequency array for the current substring, calculate
the maximum and minimum frequencies of characters in the substring.
    - Ignore characters with a frequency of 0 when calculating the minimum
frequency.

4. **Update the Total Beauty Sum**:
    - Compute the beauty of the current substring as `maxFreq - minFreq` and add
it to the total sum.

5. **Return the Result**:
    - After iterating through all substrings, return the total beauty sum.

### Implementation Details:
- The outer loop runs from `i = 0` to `n - 1` (where `n` is the length of the
string).
- The inner loop runs from `j = i` to `n - 1`, generating substrings starting at
`i` and ending at `j`.
- The frequency array `freq` is reset for each new starting index `i`.
- The time complexity of this approach is O(n^2 * 26) ≈ O(n^2), where `n` is the
length of the string. This is because for each substring, we iterate over the
frequency array of size 26 to calculate `maxFreq` and `minFreq`.

### Example:
For the string `s = "abaacc"`:
- Substrings: "a", "ab", "aba", "abaa", ..., "abaacc".
- For "abaacc":
  - Frequencies: {'a': 3, 'b': 1, 'c': 2}.
  - maxFreq = 3 (for 'a'), minFreq = 1 (for 'b').
  - Beauty = 3 - 1 = 2.
- Sum up the beauty of all substrings to get the final result.
*/

class Solution {
  public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxFreq = 0, minFreq = INT_MAX;
                for (int f : freq) {
                    if (f > 0) {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }
                ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};

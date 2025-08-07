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
Given a string word, compress it using the following algorithm:

    Begin with an empty string comp. While word is not empty, use the following
operation: Remove a maximum length prefix of word made of a single character c
repeating at most 9 times. Append the length of the prefix followed by c to
comp.

Return the string comp.
*/

/*
Solution Logic and Steps of Implementation:

The problem is to compress a given string `word` by grouping consecutive
identical characters into a compressed format where each group is represented by
the count of characters followed by the character itself. The count for each
group is capped at 9.

Steps of Implementation:

1. **Edge Case Handling**:
    - If the input string `s` is empty, return an empty string immediately.

2. **Initialization**:
    - Create a vector `freq` of pairs to store characters and their respective
counts. The size of the vector is initialized to the size of the input string
`n` to ensure sufficient space.
    - Use an integer `k` to track the current index in the `freq` vector where
the next character group will be stored.

3. **Iterate Through the String**:
    - Start by initializing the first character and its count in `freq[0]`.
    - Traverse the string from the second character to the end:
      - If the current character is different from the previous character or the
count of the current group has reached 9, increment `k` to start a new group in
`freq` and initialize it with the current character and a count of 1.
      - Otherwise, increment the count of the current group.

4. **Build the Compressed String**:
    - Initialize an empty string `ans` and reserve space for efficiency.
    - Iterate through the `freq` vector up to index `k` (inclusive):
      - Append the count of each group (converted to a character) followed by
the character itself to the `ans` string.

5. **Return the Result**:
    - Return the compressed string `ans`.

Example Walkthrough:
- Input: `"aaabbbccccc"`
- Step 1: Initialize `freq` and `k`.
- Step 2: Traverse the string:
  - Group 1: `'a'` appears 3 times → `freq[0] = {'a', 3}`
  - Group 2: `'b'` appears 3 times → `freq[1] = {'b', 3}`
  - Group 3: `'c'` appears 5 times → `freq[2] = {'c', 5}`
- Step 3: Build the compressed string:
  - Append `'3a'`, `'3b'`, and `'5c'` to `ans`.
- Output: `"3a3b5c"`

This approach ensures that the string is processed efficiently in O(n) time
complexity, where `n` is the length of the input string.
*/

class Solution {
  public:
    string compressedString(string s) {
        if (s.empty())
            return "";

        int n = s.size();
        vector<pair<char, int>> freq(n);
        int k = 0;

        freq[0] = {s[0], 1};
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1] || freq[k].second == 9) {
                k++;
                freq[k] = {s[i], 1};
            } else {
                freq[k].second++;
            }
        }

        string ans;
        ans.reserve((k + 1) * 2);
        for (int i = 0; i <= k; i++) {
            ans += char('0' + freq[i].second);
            ans += freq[i].first;
        }
        return ans;
    }
};

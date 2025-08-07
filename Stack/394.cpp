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
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the
square brackets is being repeated exactly k times. Note that k is guaranteed to
be a positive integer.

You may assume that the input string is always valid; there are no extra white
spaces, square brackets are well-formed, etc. Furthermore, you may assume that
the original data does not contain any digits and that digits are only for those
repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed
105.
*/

/*
Solution Logic and Steps of Implementation:

The problem is to decode a string that is encoded using the format
`k[encoded_string]`, where `k` is a positive integer representing the number of
times the `encoded_string` should be repeated. The goal is to return the fully
decoded string.

### Steps of Implementation:

1. **Initialization**:
    - Use two stacks:
      - `occur` to store the repetition counts (`k` values).
      - `strings` to store the intermediate strings before encountering a
closing bracket `]`.
    - Use a string `ans` to build the current decoded string.
    - Use an integer `k` to accumulate the repetition count when parsing digits.

2. **Iterate Through the Input String**:
    - For each character in the input string `s`:
      - **If the character is a digit**:
         - Update `k` by multiplying the current value of `k` by 10 and adding
the numeric value of the digit (`ch - '0'`). This handles multi-digit numbers.
      - **If the character is an opening bracket `[`**:
         - Push the current value of `k` onto the `occur` stack.
         - Push the current value of `ans` onto the `strings` stack.
         - Reset `ans` to an empty string to start building the new substring
inside the brackets.
         - Reset `k` to 0 for the next repetition count.
      - **If the character is a closing bracket `]`**:
         - Pop the top value from the `occur` stack (this is the repetition
count for the current substring).
         - Pop the top value from the `strings` stack (this is the string built
before the current brackets).
         - Repeat the current `ans` string `rep` times and append it to the
popped string from the `strings` stack.
         - Update `ans` with the concatenated result.
      - **If the character is a letter**:
         - Append the character to `ans` to build the current substring.

3. **Return the Result**:
    - After processing all characters in the input string, `ans` will contain
the fully decoded string. Return `ans`.

### Example Walkthrough:

#### Input: `3[a2[c]]`
- **Step 1**: Parse `3` → `k = 3`.
- **Step 2**: Encounter `[` → Push `k = 3` to `occur`, push `ans = ""` to
`strings`, reset `ans = ""`, reset `k = 0`.
- **Step 3**: Parse `a` → Append to `ans`, `ans = "a"`.
- **Step 4**: Parse `2` → `k = 2`.
- **Step 5**: Encounter `[` → Push `k = 2` to `occur`, push `ans = "a"` to
`strings`, reset `ans = ""`, reset `k = 0`.
- **Step 6**: Parse `c` → Append to `ans`, `ans = "c"`.
- **Step 7**: Encounter `]` → Pop `rep = 2` from `occur`, pop `sub = "a"` from
`strings`, repeat `ans = "c"` twice → `expand = "cc"`, concatenate `sub + expand
= "a" + "cc" = "acc"`, update `ans = "acc"`.
- **Step 8**: Encounter `]` → Pop `rep = 3` from `occur`, pop `sub = ""` from
`strings`, repeat `ans = "acc"` three times → `expand = "accaccacc"`,
concatenate `sub + expand = "" + "accaccacc" = "accaccacc"`, update `ans =
"accaccacc"`.

#### Output: `"accaccacc"`

This approach ensures that the decoding is done efficiently using stacks to
handle nested brackets and repetition counts.
*/

class Solution {
  public:
    string decodeString(string s) {
        stack<int> occur;
        stack<string> strings;
        string ans = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                occur.push(k);
                strings.push(ans);
                ans = "";
                k = 0;
            } else if (ch == ']') {
                int rep = occur.top();
                occur.pop();
                string sub = strings.top();
                strings.pop();
                string expand = "";
                for (int i = 0; i < rep; i++) {
                    expand += ans;
                }

                ans = sub + expand;
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};
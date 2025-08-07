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
Given a string containing just the characters '(' and ')', return the length of
the longest valid (well-formed) parentheses .
*/

/*
Logic and Steps of Implementation:

The problem is to find the length of the longest valid (well-formed) parentheses
substring in a given string `s` containing only '(' and ')'.

Steps of Implementation:
1. **Stack Initialization**:
    - Use a stack to keep track of indices of unmatched parentheses.
    - Push `-1` onto the stack initially to handle edge cases where the valid
substring starts from the beginning of the string.

2. **Iterate Through the String**:
    - Traverse the string character by character.

3. **Handle Opening Parentheses '('**:
    - If the current character is '(', push its index onto the stack. This
indicates that the parenthesis is unmatched for now.

4. **Handle Closing Parentheses ')'**:
    - If the current character is ')', pop the top element from the stack.
    - If the stack becomes empty after popping, push the current index onto the
stack. This is because the current ')' cannot form a valid substring, and we
need to reset the base index for future calculations.
    - If the stack is not empty after popping, calculate the length of the valid
substring using the difference between the current index and the index at the
top of the stack. Update `maxlen` if this length is greater than the current
maximum.

5. **Return the Result**:
    - After traversing the entire string, `maxlen` will contain the length of
the longest valid parentheses substring.

Key Observations:
- The stack helps track unmatched parentheses and provides a way to calculate
the length of valid substrings efficiently.
- Using `-1` as the initial value in the stack ensures that edge cases are
handled correctly.

Example:
Input: `s = "(()"`
- Stack operations:
  - Push `-1`.
  - Push `0` (index of '(').
  - Push `1` (index of '(').
  - Pop `1` (index of '(') for ')' at index `2`.
  - Calculate length: `2 - 0 = 2`.
Output: `2`.

Input: `s = ")()())"`
- Stack operations:
  - Push `-1`.
  - Pop `-1` for ')' at index `0`, then push `0`.
  - Push `1` (index of '(').
  - Pop `1` for ')' at index `2`.
  - Calculate length: `2 - 0 = 2`.
  - Push `3` (index of '(').
  - Pop `3` for ')' at index `4`.
  - Calculate length: `4 - 0 = 4`.
  - Pop `0` for ')' at index `5`, then push `5`.
Output: `4`.

This approach ensures an efficient solution with a time complexity of O(n) and
space complexity of O(n) due to the stack.
*/

class Solution {
  public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxlen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }

        return maxlen;
    }
};
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
Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform
t into s after performing the following operation any number of times:

    Insert string "abc" into any position in t. More formally, t becomes tleft +
"abc" + tright, where t == tleft + tright. Note that tleft and tright may be
empty.

Return true if s is a valid string, otherwise, return false.
*/

/*
Solution Logic:

The problem requires us to determine if a given string `s` can be constructed by
repeatedly inserting the string "abc" into an initially empty string `t`. To
solve this, we can use a stack to simulate the process of constructing the
string `t` and validate whether the given string `s` adheres to the rules.

Steps of Implementation:

1. **Initialize a Stack**:
    - Use a stack to keep track of characters as we iterate through the string
`s`.

2. **Iterate Through the String**:
    - Traverse the string `s` character by character.
    - Push each character onto the stack.

3. **Check for "abc" Pattern**:
    - After pushing a character, check if the top three characters in the stack
form the sequence "abc".
    - If they do, pop these three characters from the stack, as they represent a
valid insertion of "abc".

4. **Handle Invalid Sequences**:
    - If the top three characters do not form "abc", leave them in the stack and
continue processing the next character.

5. **Final Validation**:
    - After processing all characters in `s`, the stack should be empty if the
string is valid. If the stack is not empty, it means there are leftover
characters that do not form valid "abc" sequences.

6. **Return the Result**:
    - Return `true` if the stack is empty, indicating the string is valid.
Otherwise, return `false`.

The stack-based approach ensures that we efficiently validate the string in a
single pass with O(n) time complexity, where `n` is the length of the string
`s`.

Example Walkthrough:
- Input: `s = "aabcbabc"`
- Process:
  - Push 'a', stack: ['a']
  - Push 'a', stack: ['a', 'a']
  - Push 'b', stack: ['a', 'a', 'b']
  - Push 'c', stack: ['a', 'a', 'b', 'c']
     - Top 3: "abc", pop them, stack: ['a']
  - Push 'b', stack: ['a', 'b']
  - Push 'a', stack: ['a', 'b', 'a']
  - Push 'b', stack: ['a', 'b', 'a', 'b']
  - Push 'c', stack: ['a', 'b', 'a', 'b', 'c']
     - Top 3: "abc", pop them, stack: ['a', 'b']
     - Top 3: "abc", pop them, stack: []
- Output: `true` (stack is empty)
*/

class Solution {
  public:
    bool isValid(const string &s) {
        stack<char> st;
        int i = 0, n = s.size();

        while (i < n) {
            st.push(s[i++]);

            if (st.size() >= 3) {
                char x = st.top();
                st.pop();
                char y = st.top();
                st.pop();
                char z = st.top();
                st.pop();

                if (!(z == 'a' && y == 'b' && x == 'c')) {
                    st.push(z);
                    st.push(y);
                    st.push(x);
                }
            }
        }

        return st.empty();
    }
};

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
You are given a string s consisting of lowercase English letters.

You must repeatedly perform the following operation while the string s has at
least two consecutive characters:

    Remove the leftmost pair of adjacent characters in the string that are
consecutive in the alphabet, in either order (e.g., 'a' and 'b', or 'b' and
'a'). Shift the remaining characters to the left to fill the gap.

Return the resulting string after no more operations can be performed.

Note: Consider the alphabet as circular, thus 'a' and 'z' are consecutive.
*/

/*
Detailed Solution Logic:

The problem requires us to repeatedly remove the leftmost pair of adjacent
characters in the string that are consecutive in the alphabet (either in
increasing or decreasing order). The alphabet is considered circular, so 'a' and
'z' are also consecutive. The goal is to return the resulting string after no
more such operations can be performed.

Steps of Implementation:

1. **Understand the Problem**:
    - Two characters are considered consecutive if their ASCII difference is 1
(e.g., 'a' and 'b') or 25 (e.g., 'a' and 'z').
    - We need to repeatedly remove such pairs until no more pairs exist.

2. **Use a Stack for Efficient Pair Removal**:
    - A stack is a suitable data structure for this problem because it allows us
to efficiently check and remove the most recently added character (top of the
stack).
    - As we iterate through the string, we can use the stack to keep track of
characters that are not yet removed.

3. **Iterate Through the String**:
    - Push the first character of the string onto the stack.
    - For each subsequent character, check if it forms a consecutive pair with
the character at the top of the stack:
      - If it does, pop the top character from the stack (remove the pair).
      - Otherwise, push the current character onto the stack.

4. **Handle the Circular Alphabet**:
    - To account for the circular nature of the alphabet, check if the absolute
difference between the ASCII values of the two characters is either 1 or 25.

5. **Construct the Resulting String**:
    - After processing all characters, the stack will contain the characters of
the resulting string in reverse order.
    - Pop all characters from the stack and append them to a result string.
    - Reverse the result string to get the final answer.

6. **Edge Cases**:
    - If the input string is empty, return an empty string.
    - If no pairs are removed, return the original string.

The implementation of the above logic is provided in the `resultingString`
function.
*/

class Solution {
  public:
    string resultingString(string s) {
        if (s.empty())
            return "";

        stack<char> st;
        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (!st.empty() &&
                (abs(st.top() - s[i]) == 1 || abs(st.top() - s[i]) == 25)) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

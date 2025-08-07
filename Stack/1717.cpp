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
You are given a string s and two integers x and y. You can perform two types of
operations any number of times.

    Remove substring "ab" and gain x points.
        For example, when removing "ab" from "cabxbae" it becomes "cxbae".
    Remove substring "ba" and gain y points.
        For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.
*/

/*
Solution Logic:

The problem involves maximizing the points gained by removing specific
substrings ("ab" and "ba") from a given string `s`. Each removal operation
awards a certain number of points (`x` for "ab" and `y` for "ba"). The goal is
to determine the maximum points that can be achieved by strategically removing
these substrings.

Steps of Implementation:

1. **Determine Priority of Substring Removal**:
    - Since removing "ab" awards `x` points and removing "ba" awards `y` points,
we prioritize the substring with the higher point value. This ensures that we
maximize the score in the first pass.

2. **First Pass: Remove High-Priority Substring**:
    - Use a helper function `removeSubstring` to remove all occurrences of the
high-priority substring from the string `s`.
    - Count the number of removed substrings and calculate the score for this
pass by multiplying the count with the higher point value (`max(x, y)`).

3. **Second Pass: Remove Low-Priority Substring**:
    - After the first pass, the string is processed again to remove all
occurrences of the low-priority substring.
    - Count the number of removed substrings and calculate the score for this
pass by multiplying the count with the lower point value (`min(x, y)`).

4. **Helper Function: `removeSubstring`**:
    - This function uses a stack to efficiently remove all occurrences of a
given substring (`targetPair`) from the input string.
    - Iterate through the characters of the string:
      - If the current character forms the target pair with the top of the
stack, pop the stack (indicating the removal of the substring).
      - Otherwise, push the current character onto the stack.
    - After processing the string, reconstruct the remaining string from the
stack.

5. **Combine Scores**:
    - Add the scores from both passes to get the total maximum points.

6. **Return the Result**:
    - Return the total score as the result.

This approach ensures that the removal operations are performed in an optimal
order, maximizing the points gained.
*/

class Solution {
  public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = highPriorityPair == "ab" ? "ba" : "ab";

        // First pass: remove high priority pair
        string stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount =
            (s.length() - stringAfterFirstPass.length()) / 2;

        // Calculate score from first pass
        totalScore += removedPairsCount * max(x, y);

        // Second pass: remove low priority pair
        string stringAfterSecondPass =
            removeSubstring(stringAfterFirstPass, lowPriorityPair);
        removedPairsCount =
            (stringAfterFirstPass.length() - stringAfterSecondPass.length()) /
            2;

        // Calculate score from second pass
        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

  private:
    string removeSubstring(const string &input, const string &targetPair) {
        stack<char> charStack;

        // Iterate through each character in the input string
        for (char currentChar : input) {
            // Check if current character forms the target pair with the top of
            // the stack
            if (currentChar == targetPair[1] && !charStack.empty() &&
                charStack.top() == targetPair[0]) {
                charStack.pop(); // Remove the matching character from the stack
            } else {
                charStack.push(currentChar);
            }
        }

        // Reconstruct the remaining string after removing target pairs
        string remainingChars;
        while (!charStack.empty()) {
            remainingChars += charStack.top();
            charStack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());
        return remainingChars;
    }
};
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
Given a string s and an integer k, return the maximum number of vowel letters in
any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
*/

/*
Logic and Steps of Implementation:

1. **Understand the Problem**:
    - We need to find the maximum number of vowels in any substring of length
`k` from the given string `s`.
    - Vowels are defined as 'a', 'e', 'i', 'o', and 'u'.

2. **Approach**:
    - Use the sliding window technique to efficiently calculate the number of
vowels in substrings of length `k`.
    - Maintain a count of vowels in the current window and update the maximum
count as we slide the window.

3. **Steps**:
    - Define a helper function `isVowel(char c)` to check if a character is a
vowel.
    - Initialize variables:
      - `maxVowels` to store the maximum number of vowels found.
      - `currentVowels` to store the count of vowels in the current window.
      - `left` pointer to track the start of the sliding window.
    - Iterate through the string using a `right` pointer:
      - If the character at `right` is a vowel, increment `currentVowels`.
      - If the window size exceeds `k`:
         - Check if the character at `left` is a vowel and decrement
`currentVowels` if necessary.
         - Move the `left` pointer forward to shrink the window.
      - Update `maxVowels` with the maximum of its current value and
`currentVowels`.
    - Return `maxVowels` as the result.

4. **Efficiency**:
    - Time Complexity: O(n), where `n` is the length of the string `s`, as we
traverse the string once.
    - Space Complexity: O(1), as we use a constant amount of extra space.
*/

class Solution {
  public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int maxVowels = 0, currentVowels = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            // Check if the current character is a vowel
            if (isVowel(s[right])) {
                currentVowels++;
            }

            // If the window size exceeds k, remove the leftmost character
            if (right - left + 1 > k) {
                if (isVowel(s[left])) {
                    currentVowels--;
                }
                left++;
            }

            maxVowels = max(maxVowels, currentVowels);
        }

        return maxVowels;
    }
};
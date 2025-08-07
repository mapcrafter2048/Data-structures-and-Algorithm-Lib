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
Given a palindromic string of lowercase English letters palindrome, replace
exactly one character with any lowercase English letter so that the resulting
string is not a palindrome and that it is the lexicographically smallest one
possible.

Return the resulting string. If there is no way to replace a character to make
it not a palindrome, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if
in the first position where a and b differ, a has a character strictly smaller
than the corresponding character in b. For example, "abcc" is lexicographically
smaller than "abcd" because the first position they differ is at the fourth
character, and 'c' is smaller than 'd'.
*/

/*
Logic: To break the palindrome, we can iterate through the first half of the
string and replace the first non-'a' character with 'a'. If the string is
only made of 'a's, we can replace the last character with 'b'.
Implementation Steps:
1. Iterate through the first half of the string.
2. If a character is not 'a', replace it with 'a' and return the modified
   string.
3. If all characters in the first half are 'a', replace the last character
   with 'b'.
4. If the string is of length 1, return an empty string.
*/

class Solution {
  public:
    string breakPalindrome(string pt) {
        for (int i = 0; i < pt.size() / 2; i++) {
            if (pt[i] != 'a') {
                pt[i] = 'a';
                return pt;
            }
        }
        pt[pt.size() - 1] = 'b';
        return pt.size() < 2 ? "" : pt;
    }
};
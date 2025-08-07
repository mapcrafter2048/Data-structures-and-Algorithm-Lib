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
Given a list of non-negative integers nums, arrange them such that they form the
largest number and return it.

Since the result may be very large, so you need to return a string instead of an
integer.
*/

/*
Logic Steps for Implementation:

1. **Understand the Problem**:
    - You are given a list of non-negative integers.
    - The goal is to arrange these integers such that they form the largest
possible number when concatenated.
    - The result should be returned as a string.

2. **Convert Integers to Strings**:
    - Since the problem involves concatenating numbers, convert all integers in
the input vector to strings. This allows us to manipulate and compare them as
strings.

3. **Custom Sorting**:
    - To form the largest number, define a custom comparator for sorting the
strings.
    - For two strings `a` and `b`, compare the concatenated results of `a + b`
and `b + a`.
    - If `a + b` is greater than `b + a`, then `a` should come before `b` in the
sorted order.

4. **Edge Case for Leading Zeros**:
    - If the largest number after sorting is `"0"`, it means all numbers are
zeros. In this case, return `"0"` as the result.

5. **Concatenate the Sorted Strings**:
    - After sorting, concatenate all the strings in the sorted order to form the
final result.

6. **Return the Result**:
    - Return the concatenated string as the largest number.

Steps in the Code:
- Convert integers to strings using `to_string`.
- Sort the strings using the custom comparator.
- Handle the edge case where the largest number is `"0"`.
- Concatenate the sorted strings to form the result.
- Return the result.
*/

class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        vector<string> numstr;
        for (int num : nums) {
            numstr.push_back(to_string(num));
        }

        sort(numstr.begin(), numstr.end(),
             [](string &a, string &b) { return a + b > b + a; });

        if (numstr[0] == "0") {
            return "0";
        }

        string ans;
        for (string &numStr : numstr) {
            ans += numStr;
        }

        return ans;
    }
};
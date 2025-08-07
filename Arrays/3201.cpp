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
You are given an integer array nums.

A

sub of nums with length x is called valid if it satisfies:

    (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x
- 1]) % 2.

Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.
*/

/*
Logic and Steps of Implementation:

1. Problem Understanding:
    - We need to find the length of the longest valid subsequence of the given
array `nums`.
    - A subsequence is valid if the parity (even/odd) of the sum of consecutive
elements remains consistent throughout the subsequence.

2. Observations:
    - A valid subsequence can either consist of all even numbers or all odd
numbers.
    - Alternatively, a valid subsequence can alternate between even and odd
numbers.

3. Approach:
    - Count the number of even and odd numbers in the array. The maximum count
of either gives one possible valid subsequence length.
    - Check for alternating subsequences:
      - Start with an expected parity (even or odd) and iterate through the
array, counting how many elements match the expected parity while toggling the
expectation.
      - Repeat the process for both starting parities (even and odd).
    - The maximum of these values gives the length of the longest valid
subsequence.

4. Implementation Steps:
    - Count the number of even and odd numbers in the array.
    - Calculate the length of the longest alternating subsequences starting with
even and odd parities.
    - Return the maximum of these values.

The solution is implemented in the `maximumLength` function, which follows the
above steps to compute the result.
*/

class Solution {
  public:
    int maximumLength(vector<int> &nums) {
        int n = nums.size();

        int even = 0;
        int odd = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        int way1 = max(even, odd);

        int alt1 = 0, alt2 = 0;
        int expect1 = 0;
        int expect2 = 1;

        for (int x : nums) {
            int p = x & 1;
            if (p == expect1) {
                ++alt1;
                expect1 ^= 1;
            }
            if (p == expect2) {
                ++alt2;
                expect2 ^= 1;
            }
        }
        int way2 = max(alt1, alt2);

        return max(way1, way2);
    }
};
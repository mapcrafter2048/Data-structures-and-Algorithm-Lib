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
Given an integer array nums and an integer k, return the number of good
subarrays of nums.

A good array is an array where the number of different integers in that array is
exactly k.

    For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

A subarray is a contiguous part of an array.
*/

/*
Logic and Steps of Implementation:

1. **Problem Understanding**:
    - We need to count subarrays with exactly `k` distinct integers.
    - A subarray is a contiguous part of the array.

2. **Challenges**:
    - A simple sliding window approach cannot directly count subarrays with
exactly `k` distinct integers because it is difficult to maintain the exact
count of distinct integers dynamically.

3. **Approach**:
    - Use a helper function `help` to count subarrays with at most `k` distinct
integers.
    - Subarrays with exactly `k` distinct integers can be calculated as:
      `subarraysWithKDistinct(nums, k) = help(nums, k) - help(nums, k - 1)`
    - This works because:
      - `help(nums, k)` counts subarrays with at most `k` distinct integers.
      - `help(nums, k - 1)` counts subarrays with at most `k - 1` distinct
integers.
      - The difference gives subarrays with exactly `k` distinct integers.

4. **Steps in `help` Function**:
    - Use a sliding window approach with two pointers (`left` and `r`).
    - Maintain a frequency map (`freq`) to track the count of each integer in
the current window.
    - Adjust the `left` pointer to ensure the window contains at most `k`
distinct integers.
    - Count the number of valid subarrays ending at each position `r`.

5. **Why This Solution Works**:
    - The helper function efficiently calculates subarrays with at most `k`
distinct integers using a sliding window and frequency map.
    - By subtracting results for `k` and `k - 1`, we isolate subarrays with
exactly `k` distinct integers.
    - This avoids the complexity of directly counting subarrays with exactly `k`
distinct integers.

6. **Why Simple Sliding Window Fails**:
    - A simple sliding window approach cannot dynamically maintain the exact
count of distinct integers in the window.
    - It would require additional checks and adjustments, making it inefficient
and error-prone.
*/

class Solution {
  public:
    int help(vector<int> &A, int k) {
        int n = A.size();
        unordered_map<int, int> freq;
        int ans = 0;
        int left = 0;
        for (int r = 0; r < n; r++) {
            // Increment the frequency of the current element
            // and check if we have added a new distinct element
            if (++freq[A[r]] == 1) {
                --k;
            }
            // If we have more than k distinct elements, move the left pointer
            // until we have at most k distinct elements
            while (k < 0) {
                if (--freq[A[left]] == 0) {
                    ++k;
                }
                left++;
            }

            ans += (r - left + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k) {
        return help(nums, k) - help(nums, k - 1);
    }
};
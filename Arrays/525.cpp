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
Given a binary array nums, return the maximum length of a contiguous subarray
with an equal number of 0 and 1.
*/

/*
Logic and Solution:

The problem is to find the maximum length of a contiguous subarray in a binary
array `nums` such that the subarray contains an equal number of 0s and 1s.

### Key Observations:
1. Replace 0s with -1s:
    - If we replace all 0s in the array with -1s, the problem reduces to finding
the longest subarray with a sum of 0.
    - This is because an equal number of 1s and 0s in the original array
corresponds to a sum of 0 in the transformed array.

2. Use a prefix sum:
    - As we iterate through the array, we maintain a running sum (`sum`) where:
      - Add +1 for every 1.
      - Add -1 for every 0 (transformed as -1).
    - If the same `sum` is encountered at two different indices, it means the
subarray between these indices has a sum of 0.

3. Use a hash map to store the first occurrence of each prefix sum:
    - The hash map (`firstIndex`) maps each prefix sum to the first index where
it occurs.
    - If the same prefix sum is encountered again, calculate the length of the
subarray between the first occurrence and the current index.

4. Track the maximum length:
    - For every repeated prefix sum, calculate the length of the subarray and
update the maximum length (`best`).

### Algorithm:
1. Initialize a hash map `firstIndex` to store the first occurrence of each
prefix sum. Add an entry for `sum = 0` at index `-1` to handle edge cases.
2. Initialize `sum = 0` and `best = 0`.
3. Iterate through the array:
    - Update the running sum (`sum`).
    - Check if `sum` exists in the hash map:
      - If it exists, calculate the length of the subarray and update `best`.
      - If it doesn't exist, store the current index in the hash map for this
`sum`.
4. Return `best` as the maximum length of the subarray.

### Complexity:
- Time Complexity: O(n), where `n` is the size of the array. Each element is
processed once, and hash map operations (insert/find) are O(1) on average.
- Space Complexity: O(n), for storing the hash map.

### Example:
Input: `nums = [0, 1, 0]`
1. Replace 0s with -1s: `nums = [-1, 1, -1]`
2. Compute prefix sums:
    - At index 0: `sum = -1`
    - At index 1: `sum = 0` (subarray [0, 1] has sum 0, length = 2)
    - At index 2: `sum = -1` (subarray [2, 2] has sum 0, length = 2)
3. Maximum length = 2.

Output: `2`
*/

class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size();
        // Create a hash map to store the first occurrence of each prefix sum
        unordered_map<int, int> firstIndex;
        // Reserve space for the hash map to avoid reallocation
        // We reserve space for 2n because the sum can range from -n to n
        firstIndex.reserve(n * 2);
        // Initialize the first occurrence of sum 0 at index -1
        firstIndex[0] = -1;

        int sum = 0, best = 0;
        for (int i = 0; i < n; ++i) {
            // Update the sum: +1 for 1, -1 for 0
            sum += (nums[i] == 1 ? 1 : -1);
            // Check if this sum has been seen before
            auto it = firstIndex.find(sum);
            // If it has not been seen, store the index
            // If it has been seen, calculate the length of the subarray
            if (it == firstIndex.end()) {
                firstIndex[sum] = i;
            } else {

                best = max(best, i - it->second);
            }
        }
        return best;
    }
};

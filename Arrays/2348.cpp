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
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

/*
To solve the problem of counting the number of subarrays filled with 0, we can
break the solution into the following steps:

1. **Understand the Problem**:
    - A subarray is a contiguous sequence of elements in an array.
    - We need to count all subarrays that consist entirely of 0s.

2. **Approach**:
    - Traverse the array and group consecutive 0s together.
    - For each group of consecutive 0s, calculate the number of subarrays that
can be formed.
    - Add up the counts from all groups to get the final result.

3. **Steps of Implementation**:
    - Initialize a vector `grp` to store the lengths of groups of consecutive
0s.
    - Traverse the array:
      - If the current element is 0:
         - If the previous element was also 0, increment the count of the last
group in `grp`.
         - Otherwise, start a new group with a count of 1.
    - After grouping, calculate the number of subarrays for each group:
      - For a group of length `len`, the number of subarrays is given by the
formula: `len * (len + 1) / 2`.
    - Sum up the counts from all groups to get the final answer.

4. **Optimization**:
    - The solution is efficient with a time complexity of O(n), where n is the
size of the array, as we traverse the array once and perform constant-time
operations for each element.

5. **Edge Cases**:
    - An empty array or an array with no 0s should return 0.
    - Arrays with all elements as 0s should handle large groups correctly.

The implementation of the above logic is provided in the `zeroFilledSubarray`
function.
*/

class Solution {
  public:
    long long zeroFilledSubarray(vector<int> &nums) {
        int n = nums.size();
        vector<int> grp;
        if (n > 0 && nums[0] == 0) {
            grp.push_back(1);
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                if (nums[i - 1] == 0) {
                    grp.back()++;
                } else {
                    grp.push_back(1);
                }
            }
        }

        long long ans = 0;
        for (int len : grp) {
            ans += (long long)len * (len + 1) / 2;
        }
        return ans;
    }
};

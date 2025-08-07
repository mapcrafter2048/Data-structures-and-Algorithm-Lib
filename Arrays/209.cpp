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
Given an array of positive integers nums and a positive integer target, return
the minimal length of a whose sum is greater than or equal to target. If there
is no such subarray, return 0 instead.
*/

/*
The problem is to find the minimal length of a contiguous subarray of which the
sum is greater than or equal to a given target. If no such subarray exists,
return 0.

### Approach:
We use the **sliding window technique** to solve this problem efficiently in
O(n) time complexity.

1. **Initialize Variables**:
    - `left`: This pointer represents the start of the current window.
    - `currSum`: This variable keeps track of the sum of the current window.
    - `ans`: This variable stores the minimum length of the subarray found so
far. It is initialized to `INT_MAX`.

2. **Iterate Through the Array**:
    - Use a `for` loop to iterate through the array with the index `i`
representing the end of the current window.
    - Add the current element `nums[i]` to `currSum`.

3. **Shrink the Window**:
    - While `currSum` is greater than or equal to the `target`, calculate the
length of the current window (`i - left + 1`) and update `ans` with the minimum
value between `ans` and the current window length.
    - Subtract `nums[left]` from `currSum` and increment the `left` pointer to
shrink the window from the left.

4. **Check for No Valid Subarray**:
    - If `ans` remains `INT_MAX`, it means no valid subarray was found, so
return 0.

5. **Return the Result**:
    - Return the value of `ans` as the minimal length of the subarray.

### Example:
#### Input:
`target = 7, nums = [2,3,1,2,4,3]`

#### Execution:
- Start with `left = 0`, `currSum = 0`, and `ans = INT_MAX`.
- Iterate through the array:
  - Add `nums[0] = 2` → `currSum = 2` (less than target, continue).
  - Add `nums[1] = 3` → `currSum = 5` (less than target, continue).
  - Add `nums[2] = 1` → `currSum = 6` (less than target, continue).
  - Add `nums[3] = 2` → `currSum = 8` (greater than or equal to target):
     - Calculate window length: `4 - 0 + 1 = 4`, update `ans = 4`.
     - Shrink window: subtract `nums[0] = 2`, `currSum = 6`, increment `left =
1`.
  - Add `nums[4] = 4` → `currSum = 10` (greater than or equal to target):
     - Calculate window length: `5 - 1 + 1 = 4`, update `ans = 4`.
     - Shrink window: subtract `nums[1] = 3`, `currSum = 7`, increment `left =
2`.
     - Calculate window length: `5 - 2 + 1 = 3`, update `ans = 3`.
     - Shrink window: subtract `nums[2] = 1`, `currSum = 6`, increment `left =
3`.
  - Add `nums[5] = 3` → `currSum = 9` (greater than or equal to target):
     - Calculate window length: `6 - 3 + 1 = 3`, `ans` remains 3.
     - Shrink window: subtract `nums[3] = 2`, `currSum = 7`, increment `left =
4`.
     - Calculate window length: `6 - 4 + 1 = 2`, update `ans = 2`.
     - Shrink window: subtract `nums[4] = 4`, `currSum = 3`, increment `left =
5`.

- Final `ans = 2`.

#### Output:
`2` (The subarray `[4,3]` has the minimal length with a sum ≥ 7).

### Complexity:
- **Time Complexity**: O(n), where n is the size of the array. Each element is
processed at most twice (once when expanding the window and once when shrinking
it).
- **Space Complexity**: O(1), as no additional space is used apart from
variables.
*/

class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0;
        int currSum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            while (currSum >= target) {
                ans = min(ans, i - left + 1);
                currSum -= nums[left];
                left++;
            }
        }

        if (ans == INT_MAX) {
            return 0;
        }

        return ans;
    }
};
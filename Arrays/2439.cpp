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
You are given a 0-indexed array nums comprising of n non-negative integers.

In one operation, you must:

    Choose an integer i such that 1 <= i < n and nums[i] > 0.
    Decrease nums[i] by 1.
    Increase nums[i - 1] by 1.

Return the minimum possible value of the maximum integer of nums after
performing any number of operations.
*/

/*
The problem is to minimize the maximum value in the array `nums` after
performing a series of operations. The operations allow us to decrease an
element at index `i` and increase the element at index `i-1`. The goal is to
determine the smallest possible maximum value of the array after any number of
such operations.

### Solution Logic:

1. **Binary Search on the Result**:
    - The problem can be solved using binary search on the possible values of
the maximum element in the array.
    - The range of the binary search is from `0` to the maximum element in the
array (`max_element(nums.begin(), nums.end())`).

2. **Feasibility Check**:
    - For a given candidate maximum value `mid`, we need to check if it is
possible to make all elements in the array less than or equal to `mid` using the
allowed operations.
    - This is done using the helper function `can(nums, mid)`.

3. **Helper Function `can(nums, mid)`**:
    - The function checks if it is possible to make all elements in the array
less than or equal to `mid`.
    - It uses a prefix sum approach to simulate the redistribution of values:
      - For each index `i`, calculate the cumulative sum (`prefix`) of the array
up to that point.
      - If at any point, the cumulative sum exceeds `(i + 1) * mid`, it means it
is not possible to make all elements up to index `i` less than or equal to
`mid`.

4. **Binary Search Implementation**:
    - Start with `low = 0` and `high = max_element(nums.begin(), nums.end())`.
    - For each candidate `mid` (calculated as `low + (high - low) / 2`):
      - If `can(nums, mid)` returns `true`, update the answer to `mid` and
search in the lower half (`high = mid - 1`).
      - Otherwise, search in the upper half (`low = mid + 1`).

5. **Return the Result**:
    - The final value of `ans` after the binary search completes is the minimum
possible value of the maximum integer in the array.

### Steps of Implementation:

1. Define the helper function `can(nums, mid)` to check feasibility for a given
`mid`.
2. Implement the binary search in the `minimizeArrayValue` function.
3. Use the helper function within the binary search to determine the smallest
possible maximum value.

### Complexity Analysis:
- **Time Complexity**:
  - Binary search runs in `O(log(max(nums)))`.
  - The `can` function runs in `O(n)` for each binary search iteration.
  - Overall complexity: `O(n * log(max(nums)))`.
- **Space Complexity**:
  - The solution uses `O(1)` additional space apart from the input array.

This approach ensures an efficient solution to the problem.
*/

class Solution {
  public:
    bool can(vector<int> &nums, int mid) {
        int prefix = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            if (prefix > (i + 1) * mid) {
                return false;
            }
        }
        return true;
    }

    int minimizeArrayValue(vector<int> &nums) {
        int low = 0;
        int high = *max_element(nums.begin(), nums.end());

        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
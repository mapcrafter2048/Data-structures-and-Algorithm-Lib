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
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
integer.

You must write an algorithm that runs in O(n) time and without using the
division operation.
*/

/*
Detailed Solution:

The problem requires us to compute the product of all elements in the array
except the current element, for each element in the array. The constraints
specify that we cannot use division and the solution must run in O(n) time
complexity.

### Approach:
1. **Prefix Product**:
    - Compute the product of all elements to the left of the current element.
    - Use a variable `left` to keep track of the cumulative product as we
iterate through the array from left to right.
    - Store the result in the `res` array.

2. **Suffix Product**:
    - Compute the product of all elements to the right of the current element.
    - Use a variable `right` to keep track of the cumulative product as we
iterate through the array from right to left.
    - Multiply the `res` array (which already contains the prefix product) by
the suffix product.

3. **Final Result**:
    - The `res` array will contain the product of all elements except the
current element for each index.

### Steps:
- Initialize a result array `res` with size `n` and fill it with 1.
- Traverse the array from left to right to calculate the prefix product.
- Traverse the array from right to left to calculate the suffix product and
multiply it with the prefix product stored in `res`.

### Complexity:
- **Time Complexity**: O(n) because we traverse the array twice (once for prefix
and once for suffix).
- **Space Complexity**: O(1) additional space (excluding the output array).

### Example:
Input: nums = [1, 2, 3, 4]
- Prefix product: [1, 1, 2, 6]
- Suffix product: [24, 12, 4, 1]
- Result: [24, 12, 8, 6]

Output: [24, 12, 8, 6]
*/

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int left = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};
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
You are given an integer array nums. You can choose exactly one index
(0-indexed) and remove the element. Notice that the index of the elements may
change after the removal.

For example, if nums = [6,1,7,4,1]:

    Choosing to remove index 1 results in nums = [6,7,4,1].
    Choosing to remove index 2 results in nums = [6,1,4,1].
    Choosing to remove index 4 results in nums = [6,1,7,4].

An array is fair if the sum of the odd-indexed values equals the sum of the
even-indexed values.

Return the number of indices that you could choose such that after the removal,
nums is fair.
*/

/*
Logic and Steps of Implementation:

1. **Understand the Problem**:
    - We need to determine how many indices can be removed from the array such
that the sum of elements at odd indices equals the sum of elements at even
indices in the resulting array.

2. **Approach**:
    - Calculate the total sum of elements at odd indices (`odd`) and even
indices (`even`) in the original array.
    - Iterate through the array, simulating the removal of each element at index
`i`.
    - Adjust the `odd` and `even` sums dynamically as if the element at index
`i` is removed.
    - Check if the adjusted sums are equal after the removal.
    - Restore the sums for the next iteration.

3. **Steps**:
    - Initialize `odd` and `even` sums to 0.
    - Traverse the array to compute the initial `odd` and `even` sums.
    - Use a second loop to iterate through each index:
      - Subtract the current element from the respective sum (`odd` or `even`).
      - Check if the sums are equal after the removal.
      - Restore the sums for the next iteration.
    - Count the indices where the sums are equal.
    - Return the count.

4. **Optimization**:
    - The solution avoids creating a new array for each removal, making it
efficient with a time complexity of O(n).
*/

class Solution {
  public:
    int waysToMakeFair(vector<int> &nums) {
        int odd = 0;
        int even = 0;

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                even += nums[i];
            } else {
                odd += nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                even -= nums[i];
            } else {
                odd -= nums[i];
            }

            if (odd == even) {
                cnt++;
            }
            // Restore the sums for the next iteration
            // Why opposite? Because we are simulating the removal
            // of the current index `i`.
            if (i % 2 != 0) {
                even += nums[i];
            } else {
                odd += nums[i];
            }
        }
        return cnt;
    }
};
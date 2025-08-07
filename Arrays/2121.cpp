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
You are given a 0-indexed array of n integers arr.

The interval between two elements in arr is defined as the absolute difference
between their indices. More formally, the interval between arr[i] and arr[j] is
|i - j|.

Return an array intervals of length n where intervals[i] is the sum of intervals
between arr[i] and each element in arr with the same value as arr[i].

Note: |x| is the absolute value of x.
*/

/*
To solve the problem, we need to calculate the sum of intervals for each element
in the array `arr`. The interval is defined as the absolute difference between
the indices of two elements with the same value. Here's the step-by-step
explanation of the solution:

1. **Group Indices by Value**:
    - Use an unordered_map to group the indices of elements with the same value.
The key is the value of the element, and the value is a vector of indices where
this element appears.

2. **Prefix Sum for Efficient Calculation**:
    - For each group of indices, calculate the prefix sum of the indices. This
allows us to efficiently compute the sum of intervals for each index in the
group.

3. **Calculate Left and Right Contributions**:
    - For each index in the group, calculate the contribution of indices to the
left and to the right:
      - **Left Contribution**: The sum of intervals for indices to the left of
the current index can be calculated using the prefix sum.
      - **Right Contribution**: Similarly, the sum of intervals for indices to
the right of the current index can also be calculated using the prefix sum.

4. **Combine Contributions**:
    - Add the left and right contributions to get the total sum of intervals for
the current index.

5. **Store the Result**:
    - Store the result in the `ans` vector, which will be returned as the final
output.

The algorithm ensures that we efficiently calculate the sum of intervals for
each element in the array.

**Time Complexity**:
- Grouping indices by value: O(n), where n is the size of the array.
- Calculating prefix sums and contributions: O(n) for each unique value in the
array. In the worst case, this is O(n) for all elements.
- Overall complexity: O(n).

**Space Complexity**:
- The space complexity is O(n) due to the use of the unordered_map and prefix
sum arrays.

Below is the implementation of the solution:
*/

class Solution {
  public:
    vector<long long> getDistances(vector<int> &arr) {
        // Create a map to store indices of each value
        unordered_map<long long int, vector<long long int>> pos(arr.size());
        vector<long long int> ans(arr.size(), 0);
        // Fill the map with indices of each value
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }

        for (auto it : pos) {
            vector<long long int> A = it.second;
            if (A.size() == 1) {
                continue;
            }
            // Create a prefix sum array for the indices
            vector<long long int> pre(A.size() + 1);
            for (long long int i = 0; i < A.size(); i++) {
                pre[i + 1] = pre[i] + A[i];
            }
            // Calculate the sum of intervals for each index
            // left = i * A[i] - pre[i]
            // right = pre[A.size()] - pre[i + 1] - (A.size() - i - 1) * A[i]
            // ans[A[i]] = left + right
            for (long long int i = 0; i < A.size(); i++) {
                long long int left = i * A[i] - pre[i];
                long long int right =
                    pre[A.size()] - pre[i + 1] - (A.size() - i - 1) * A[i];
                ans[A[i]] = left + right;
            }
        }

        return ans;
    }
};
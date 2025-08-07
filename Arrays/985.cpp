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
You are given an integer array nums and an array queries where queries[i] =
[vali, indexi].

For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print
the sum of the even values of nums.

Return an integer array answer where answer[i] is the answer to the ith query.
*/

/*
Detailed Solution and Steps of Implementation:

Problem:
You are given an integer array `nums` and an array `queries` where each query is
represented as `[vali, indexi]`. For each query:
1. Update the value at `nums[indexi]` by adding `vali` to it.
2. Calculate the sum of all even numbers in the updated `nums` array.
3. Return an array `answer` where `answer[i]` is the sum of even numbers after
processing the `i-th` query.

Steps of Implementation:
1. Initialize a variable `eve` to store the sum of all even numbers in the
`nums` array.
    - Iterate through the `nums` array and add all even numbers to `eve`.

2. Create an empty vector `ans` to store the results of each query.

3. Iterate through each query in the `queries` array:
    - Extract the `index` and `val` from the current query.
    - Check if the current value at `nums[index]` is even:
      - If it is, subtract it from `eve` because it will be updated and may no
longer be even.
    - Update `nums[index]` by adding `val` to it.
    - Check if the updated value at `nums[index]` is even:
      - If it is, add it to `eve`.
    - Append the current value of `eve` to the `ans` vector.

4. Return the `ans` vector as the result.

Key Observations:
- Instead of recalculating the sum of even numbers after every query, we
maintain the sum `eve` and update it incrementally. This optimization reduces
the time complexity significantly.
- The solution ensures that we only process the affected index in each query,
making it efficient.

Time Complexity:
- Calculating the initial sum of even numbers: O(n), where `n` is the size of
`nums`.
- Processing each query: O(1) per query.
- Total time complexity: O(n + m), where `m` is the number of queries.

Space Complexity:
- The solution uses O(1) additional space apart from the input and output
arrays.
*/

class Solution {
  public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &q) {
        int eve = 0;
        for (auto x : nums) {
            if (x % 2 == 0) {
                eve += x;
            }
        }

        vector<int> ans;
        for (int i = 0; i < q.size(); i++) {
            int index = q[i][1];
            int val = q[i][0];
            // If the current value at nums[index] is even, subtract it from eve
            // because it will be updated and may no longer be even
            if (nums[index] % 2 == 0) {
                eve -= nums[index];
            }
            // Update nums[index] and check if it is even after the update
            nums[index] += val;
            // If the updated value is even, add it to eve
            if (nums[index] % 2 == 0) {
                eve += nums[index];
            }
            ans.push_back(eve);
        }

        return ans;
    }
};
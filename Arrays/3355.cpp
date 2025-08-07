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
You are given an integer array nums of length n and a 2D array queries, where
queries[i] = [li, ri].

For each queries[i]:

    Select a

    of indices within the range [li, ri] in nums.
    Decrement the values at the selected indices by 1.

A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after
processing all the queries sequentially, otherwise return false.
*/

/*
Logic: We can use a difference array to efficiently apply the queries. For each
query, we increment the start index and decrement the index after the end index.
After processing all queries, we can compute the prefix sum to find the final
values in the array. If any value is less than the corresponding value in nums,
we return false; otherwise, we return true.

Difference Array:
1. Initialize a difference array of the same size as nums with all zeros.
2. For each query [li, ri], increment diff[li] by 1 and decrement diff[ri + 1]
by 1 (if ri + 1 is within bounds).
3. Compute the prefix sum of the difference array to get the final values.

Intutuion:
1. The difference array allows us to efficiently apply multiple range updates.
2. The prefix sum gives us the final values after all queries.
3. We check if the final values can be transformed into a Zero Array by
comparing them with the original nums array.

*/

class Solution {
  public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &q) {
        vector<int> diff(nums.size(), 0);
        for (int i = 0; i < q.size(); i++) {
            int start = q[i][0];
            int end = q[i][1];

            diff[start] += 1;
            if (end + 1 < nums.size()) {
                diff[end + 1] -= 1;
            }
        }

        vector<int> psum(nums.size(), 0);
        int csum = 0;
        for (int i = 0; i < nums.size(); i++) {
            csum += diff[i];
            psum[i] = csum;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (psum[i] < nums[i]) {
                return false;
            }
        }

        return true;
    }
};
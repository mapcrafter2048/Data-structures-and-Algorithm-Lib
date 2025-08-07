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
You are given a 0-indexed integer array nums. There exists an array arr of
length nums.length, where arr[i] is the sum of |i - j| over all j such that
nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

Return the array arr.
*/

/*
Detailed Explanation:

The problem requires calculating the sum of absolute differences between indices
for elements in the array that are equal. If no such elements exist for a given
index, the result for that index should be 0.

Steps to Solve:
1. **Group Indices by Value**:
    - Use a hash map (`unordered_map`) to group indices of the same value in the
array. The key is the value of the element, and the value is a vector of indices
where the element appears.

2. **Prefix Sum for Efficient Calculation**:
    - For each group of indices, calculate the prefix sum of the indices. This
allows us to efficiently compute the sum of distances for each index in the
group.

3. **Calculate Distances**:
    - For each index in the group, calculate the sum of distances to all other
indices in the group using the prefix sum:
      - `left` represents the sum of distances to all indices to the left of the
current index.
      - `right` represents the sum of distances to all indices to the right of
the current index.
      - Combine `left` and `right` to get the total distance for the current
index.

4. **Store Results**:
    - Store the computed distance for each index in the result array.

5. **Return the Result**:
    - Return the result array after processing all groups.

Time Complexity:
- Grouping indices: O(n), where n is the size of the array.
- Processing each group: O(k), where k is the total number of indices across all
groups. In the worst case, k = n.
- Overall: O(n).

Space Complexity:
- The space used by the hash map and prefix sum array is proportional to the
size of the input, so O(n).

This approach ensures that the solution is efficient and works within the
constraints.
*/

class Solution {
  public:
    vector<long long> distance(vector<int> &nums) {
        unordered_map<long long int, vector<long long int>> freq;
        vector<long long int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]].push_back(i);
        }

        for (auto it : freq) {
            vector<long long int> A = it.second;
            if (A.size() == 1) {
                continue;
            }
            vector<long long int> prefix(A.size() + 1);
            for (int i = 0; i < A.size(); i++) {
                prefix[i + 1] = prefix[i] + A[i];
            }

            for (int i = 0; i < A.size(); i++) {
                // Calculate the sum of distances for A[i]
                // left: sum of distances to all indices to the left of A[i]
                // right: sum of distances to all indices to the right of A[i]
                // left = i * A[i] - prefix[i];
                // right = prefix[A.size()] - prefix[i + 1] - (A.size() - i - 1)
                // * A[i];
                long long int left = i * A[i] - prefix[i];
                long long int right = prefix[A.size()] - prefix[i + 1] -
                                      (A.size() - i - 1) * A[i];
                ans[A[i]] = left + right;
            }
        }

        return ans;
    }
};
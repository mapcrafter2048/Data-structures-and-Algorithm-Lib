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
You are given an integer n which represents an array nums containing the numbers
from 1 to n in order. Additionally, you are given a 2D array conflictingPairs,
where conflictingPairs[i] = [a, b] indicates that a and b form a conflicting
pair.

Remove exactly one element from conflictingPairs. Afterward, count the number of

of nums which do not contain both a and b for any remaining conflicting pair [a,
b].

Return the maximum number of subarrays possible after removing exactly one
conflicting pair.
*/

/*
Solution Logic:

The problem involves finding the maximum number of subarrays possible after
removing exactly one conflicting pair from the given list of conflicting pairs.
Here's the step-by-step breakdown of the solution:

1. **Understanding the Problem**:
    - We are given an array `nums` containing integers from `1` to `n`.
    - A conflicting pair `[a, b]` means that any subarray containing both `a`
and `b` is invalid.
    - We need to remove exactly one conflicting pair from the list of
conflicting pairs and calculate the maximum number of valid subarrays.

2. **Key Observations**:
    - The total number of subarrays in an array of size `n` is `n * (n + 1) /
2`.
    - Conflicting pairs reduce the number of valid subarrays because subarrays
containing both elements of a conflicting pair are invalid.
    - By removing one conflicting pair, we can maximize the number of valid
subarrays.

3. **Approach**:
    - Sort the conflicting pairs based on the second element of each pair. This
helps in efficiently calculating the number of invalid subarrays.
    - Use a greedy approach to calculate the total number of invalid subarrays
caused by the conflicting pairs.
    - For each conflicting pair, calculate the "gain" in valid subarrays if that
pair is removed. The gain is the number of subarrays that would become valid
after removing the pair.
    - Keep track of the maximum gain and use it to compute the final result.

4. **Steps of Implementation**:
    - **Step 1**: Normalize the conflicting pairs such that the smaller element
is always the first element of the pair.
    - **Step 2**: Sort the conflicting pairs based on the second element.
    - **Step 3**: Iterate through the sorted conflicting pairs and calculate the
total number of invalid subarrays.
    - **Step 4**: For each conflicting pair, calculate the gain in valid
subarrays if that pair is removed.
    - **Step 5**: Keep track of the maximum gain and use it to compute the final
result.

5. **Complexity**:
    - Sorting the conflicting pairs takes `O(m log m)`, where `m` is the number
of conflicting pairs.
    - Calculating the total invalid subarrays and the gain for each pair takes
`O(m)`.
    - Overall time complexity: `O(m log m)`.

6. **Edge Cases**:
    - If there are no conflicting pairs, the result is simply the total number
of subarrays.
    - If `n` is very small, the calculations should handle small inputs
efficiently.

The implementation follows these steps to compute the result.
*/

class Solution {
  public:
    long long maxSubarrays(int n,
                           std::vector<std::vector<int>> &conflictingPairs) {
        for (auto &pair : conflictingPairs) {
            if (pair[1] < pair[0]) {
                std::swap(pair[0], pair[1]);
            }
        }

        std::sort(conflictingPairs.begin(), conflictingPairs.end(),
                  [](const std::vector<int> &a, const std::vector<int> &b) {
                      return a[1] < b[1];
                  });

        int m = conflictingPairs.size();
        int max1 = 0;
        int max2 = 0;
        long long gain = 0;
        long long maxGain = 0;
        long long totalOccupied = 0;

        for (int i = 0; i < m; ++i) {
            int start = conflictingPairs[i][0];
            int base = n + 1 - conflictingPairs[i][1];
            if (i < m - 1) {
                base = conflictingPairs[i + 1][1] - conflictingPairs[i][1];
            }

            if (start > max1) {
                max2 = max1;
                max1 = start;
                gain = 0;
            } else if (start > max2) {
                max2 = start;
            }

            gain += static_cast<long long>(max1 - max2) * base;
            totalOccupied += static_cast<long long>(max1) * base;

            if (gain > maxGain) {
                maxGain = gain;
            }
        }

        long long total = static_cast<long long>(n) * (n + 1) / 2;
        return total - totalOccupied + maxGain;
    }
};

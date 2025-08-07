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
You are given an integer array nums and an integer k.

For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i]
+ k or nums[i] - k.

The score of nums is the difference between the maximum and minimum elements in
nums.

Return the minimum score of nums after changing the values at each index.
*/

/*
Solution Logic:

The problem is to minimize the score of the array after modifying each element
by either adding or subtracting `k`. The score is defined as the difference
between the maximum and minimum values in the array.

Steps of Implementation:

1. **Sort the Array**:
    - Sorting the array helps us to easily identify the smallest and largest
elements after modification.

2. **Initial Score**:
    - Calculate the initial score as the difference between the largest and
smallest elements in the sorted array (`nums.back() - nums.front()`).

3. **Iterate Through the Array**:
    - For each index `i` in the array (except the last one), consider splitting
the array into two parts:
      - The first part includes elements from `nums[0]` to `nums[i]`.
      - The second part includes elements from `nums[i+1]` to `nums.back()`.

4. **Modify the Elements**:
    - For the first part, the maximum value can be `nums[i] + k`.
    - For the second part, the maximum value can be `nums.back() - k`.
    - For the first part, the minimum value can be `nums[0] + k`.
    - For the second part, the minimum value can be `nums[i+1] - k`.

5. **Calculate the New Score**:
    - The new score is the difference between the maximum and minimum values
after modification.

6. **Update the Answer**:
    - Keep track of the minimum score encountered during the iteration.

7. **Return the Result**:
    - After iterating through the array, return the minimum score.

Key Observations:
- By sorting the array, we ensure that the elements are in increasing order,
which simplifies the calculation of maximum and minimum values after
modification.
- The split point `i` allows us to consider different ways of modifying the
array to minimize the score.

Time Complexity:
- Sorting the array takes `O(n log n)`.
- Iterating through the array takes `O(n)`.
- Overall time complexity is `O(n log n)`.

Space Complexity:
- The algorithm uses constant extra space, so the space complexity is `O(1)`.
*/

class Solution {
  public:
    int smallestRangeII(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int score = nums[nums.size() - 1] - nums[0];

        int ans = score;

        for (int i = 0; i < nums.size() - 1; i++) {

            int tmp1 = max(nums[i] + k, nums[nums.size() - 1] - k);
            int tmp2 = min(nums[i + 1] - k, nums[0] + k);

            score = tmp1 - tmp2;

            ans = min(ans, score);
        }

        return ans;
    }
};
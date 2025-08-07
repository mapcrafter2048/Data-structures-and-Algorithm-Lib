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
Given an integer array nums of length n and an integer target, find three
integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

/*
Logic and Implementation Steps:

1. Sort the input array `nums` in ascending order. Sorting helps in using the
two-pointer technique effectively.

2. Initialize a variable `initial` to store the sum of the first three elements
of the sorted array. This will act as the closest sum initially.

3. Iterate through the array using a loop. For each element `nums[i]`, treat it
as the first number of the triplet.

4. Use two pointers, `left` and `right`, to find the other two numbers:
    - `left` starts at `i + 1` (next element after `nums[i]`).
    - `right` starts at the last element of the array.

5. Calculate the sum of the triplet (`nums[i] + nums[left] + nums[right]`) and
compare its absolute difference with the target against the current closest sum
(`initial`):
    - If the new sum is closer to the target, update `initial`.

6. Adjust the pointers based on the comparison of the sum with the target:
    - If the sum equals the target, return the sum immediately as it is the
closest possible.
    - If the sum is less than the target, increment the `left` pointer to
increase the sum.
    - If the sum is greater than the target, decrement the `right` pointer to
decrease the sum.

7. Continue the process until `left` is no longer less than `right`.

8. After the loop ends, return the value of `initial` as the closest sum.

This approach ensures that the solution is efficient with a time complexity of
O(n^2), where n is the size of the array.
*/

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int initial = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - initial)) {
                    initial = sum;
                }
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return initial;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = sol.threeSumClosest(nums, target);
    cout << "The sum of the three integers closest to the target is: " << result
         << endl;
    return 0;
}
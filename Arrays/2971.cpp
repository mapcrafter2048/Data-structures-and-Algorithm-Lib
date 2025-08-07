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
You are given an array of positive integers nums of length n.

A polygon is a closed plane figure that has at least 3 sides. The longest side
of a polygon is smaller than the sum of its other sides.

Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ..., ak
where a1 <= a2 <= a3 <= ... <= ak and a1 + a2 + a3 + ... + ak-1 > ak, then there
always exists a polygon with k sides whose lengths are a1, a2, a3, ..., ak.

The perimeter of a polygon is the sum of lengths of its sides.

Return the largest possible perimeter of a polygon whose sides can be formed
from nums, or -1 if it is not possible to create a polygon.
*/

/*
Detailed Solution Logic:

The problem is to find the largest possible perimeter of a polygon that can be
formed using the given array of positive integers. A polygon can only be formed
if the sum of the lengths of any two sides is greater than the length of the
third side. This is known as the triangle inequality.

Steps of Implementation:

1. **Sort the Array**:
    - First, sort the array in ascending order. Sorting helps us easily check
the triangle inequality condition for consecutive elements.

2. **Iterate from the Largest Elements**:
    - Start iterating from the end of the sorted array (largest elements). This
ensures that we are checking for the largest possible perimeter first.

3. **Check the Triangle Inequality**:
    - For every triplet of elements (nums[i], nums[i-1], nums[i-2]), check if
`nums[i-2] + nums[i-1] > nums[i]`. If this condition is satisfied, it means
these three sides can form a triangle.

4. **Calculate the Perimeter**:
    - If the triangle inequality condition is satisfied, calculate the perimeter
as `nums[i] + nums[i-1] + nums[i-2]` and return it immediately since we are
looking for the largest perimeter.

5. **Return -1 if No Triangle is Possible**:
    - If no triplet satisfies the triangle inequality condition, return -1 as it
is not possible to form a polygon.

Code Implementation:
*/

class Solution {
  public:
    long long largestPerimeter(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        long long int sum = 0;
        long long int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= 2 && nums[i] < sum) {
                ans = nums[i] + sum;
            }
            sum += nums[i];
        }

        return ans;
    }
};
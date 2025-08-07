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
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] <
nums[3]....

You may assume the input array always has a valid answer.
*/

/*
Detailed Solution:

The problem requires us to reorder the array such that the elements alternate
between smaller and larger values: nums[0] < nums[1] > nums[2] < nums[3]...

To achieve this, we can use the following approach:

1. **Sort the Array**:
    First, sort the array in ascending order. This ensures that the smaller
elements are at the beginning and larger elements are at the end.

2. **Reorder the Array**:
    After sorting, we split the array into two halves:
    - The first half contains the smaller elements.
    - The second half contains the larger elements.

    Then, we interleave the two halves:
    - Place the largest element from the second half at the odd indices.
    - Place the smallest element from the first half at the even indices.

    This ensures the wiggle property:
    - nums[0] < nums[1] because the smallest element is followed by the largest
element.
    - nums[1] > nums[2] because the largest element is followed by the next
smallest element.
    - This pattern continues for the entire array.

3. **Implementation**:
    We use two pointers:
    - One pointer starts at the middle of the sorted array (for the smaller
elements).
    - The other pointer starts at the end of the sorted array (for the larger
elements). We alternate between these two pointers to fill the original array.

This approach works in O(n log n) time due to the sorting step, and it uses O(n)
extra space for the temporary sorted array.

*/

class Solution {
  public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        vector<int> nums2;
        nums2 = nums;
        sort(nums2.begin(), nums2.end());
        int i = n - 1;
        int j = 0;
        int k = i / 2 + 1;
        while (i >= 0) {
            if (i % 2 == 1) {
                nums[i] = nums2[k];
                k++;
            } else {
                nums[i] = nums2[j];
                j++;
            }
            i--;
        }
    }
};
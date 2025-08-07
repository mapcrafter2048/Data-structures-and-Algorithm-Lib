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
You are given an integer array target. You have an integer array initial of the
same size as target with all elements initially zeros.

In one operation you can choose any subarray from initial and increment each
value by one.

Return the minimum number of operations to form a target array from initial.

The test cases are generated so that the answer fits in a 32-bit integer.
*/

/*
Detailed Solution Logic:

The problem requires us to determine the minimum number of operations needed to
transform an array `initial` (initialized with all zeros) into the array
`target`. Each operation allows us to increment all elements of a subarray by 1.

Key Observations:
1. To form the first element of `target`, we need at least `target[0]`
operations since `initial[0]` starts at 0.
2. For subsequent elements, if `target[i] > target[i-1]`, we need additional
`target[i] - target[i-1]` operations to increase the value at index `i` to match
`target[i]`.
3. If `target[i] <= target[i-1]`, no additional operations are needed because
the value at index `i` can already be achieved by previous operations.

Steps of Implementation:
1. Initialize a variable `count` to store the total number of operations. Start
with `count = target[0]` since we need at least `target[0]` operations for the
first element.
2. Iterate through the array `target` from the second element to the last.
3. For each element `target[i]`, calculate the difference `target[i] -
target[i-1]`. If the difference is positive, add it to `count`.
4. Return the total `count` as the result.

This approach ensures that we only count the necessary operations to increment
the array values, minimizing redundant operations.

Time Complexity:
- O(n), where n is the size of the `target` array. We iterate through the array
once.

Space Complexity:
- O(1), as we use a constant amount of extra space.
*/

class Solution {
  public:
    int minNumberOperations(vector<int> &target) {
        int count = target[0];
        for (int i = 1; i < target.size(); i++)
            count += max(target[i] - target[i - 1], 0);
        return count;
    }
};
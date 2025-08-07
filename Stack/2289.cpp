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
You are given a 0-indexed integer array nums. In one step, remove all elements
nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.

Return the number of steps performed until nums becomes a non-decreasing array.
*/

/*
Logic:
The problem requires determining the number of steps needed to make the array non-decreasing by repeatedly removing elements that violate the non-decreasing property. To solve this, we use a stack to track elements and their "death time" (the number of steps after which they are removed).

Detailed Steps of Implementation:
1. Initialize a stack `st` to store pairs of integers, where each pair consists of an element from the array and its "death time".
2. Initialize a variable `ans` to track the maximum "death time" encountered during the process.
3. Iterate through the array `nums`:
    - For each element `nums[i]`:
        a. Initialize a variable `t` to 0. This variable will store the maximum "death time" of elements that are removed by the current element.
        b. While the stack is not empty and the top element of the stack is less than or equal to `nums[i]`:
            i. Update `t` to be the maximum of `t` and the "death time" of the top element of the stack.
            ii. Pop the top element from the stack, as it is "killed" by the current element.
        c. Determine the "death time" of the current element:
            i. If the stack is empty, the current element's "death time" is 0 (it cannot be removed by any subsequent element).
            ii. Otherwise, the current element's "death time" is `t + 1` (it is removed one step after the maximum "death time" of the elements it kills).
        d. Update `ans` to be the maximum of `ans` and the "death time" of the current element.
        e. Push the current element and its "death time" onto the stack.
4. After processing all elements, return `ans` as the result. This represents the total steps needed to make the array non-decreasing.
*/

class Solution {
  public:
    int totalSteps(vector<int> &nums) {
        int n = nums.size();
        stack<pair<int, int>> st;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int t = 0;
            while (!st.empty() && st.top().first <= nums[i]) {
                t = max(t, st.top().second);
                st.pop();
            }
            int died = 0;
            if (st.empty()) {
                died = 0;
            } else {
                died = t + 1;
            }
            ans = max(ans, died);
            st.push({nums[i], died});
        }

        return ans;
    }
};
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
Given an array of integers nums and a positive integer k, check whether it is
possible to divide this array into sets of k consecutive numbers.

Return true if it is possible. Otherwise, return false.
*/

/*
Solution Logic and Steps of Implementation:

The problem is to determine if an array of integers can be divided into sets of
`k` consecutive numbers. To solve this, we need to ensure that every number in
the array can be grouped into such sets without leaving any number ungrouped.

Steps of Implementation:

1. **Check if the array size is divisible by `k`:**
    - If the size of the array is not divisible by `k`, it is impossible to
divide the array into sets of `k` consecutive numbers. Return `false`
immediately.

2. **Count the frequency of each number:**
    - Use a `map` (or `unordered_map`) to store the frequency of each number in
the array. This helps us keep track of how many times each number appears.

3. **Iterate through the map to form groups:**
    - For each number in the map (starting from the smallest number), check if
it can form a group of `k` consecutive numbers.
    - If the frequency of the current number is greater than `0`, attempt to
form a group starting from this number.
    - For each number in the group (from `num` to `num + k - 1`), check if it
exists in the map with sufficient frequency. If not, return `false`.
    - Reduce the frequency of each number in the group by the frequency of the
starting number.

4. **Return `true` if all numbers are successfully grouped:**
    - If the loop completes without returning `false`, it means all numbers have
been grouped into valid sets of `k` consecutive numbers. Return `true`.

Key Observations:
- Sorting the array or using a `map` ensures that we process numbers in
ascending order, which is crucial for forming consecutive groups.
- The use of a `map` allows efficient frequency tracking and updates.

Time Complexity:
- Sorting the array (or iterating through the map) takes `O(n log n)`.
- Iterating through the map and forming groups takes `O(n * k)` in the worst
case.
- Overall complexity is `O(n log n)` due to the sorting step.

Space Complexity:
- The space complexity is `O(n)` for the frequency map.
*/

class Solution {
  public:
    bool isPossibleDivide(vector<int> &nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }

        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto it : mp) {
            int num = it.first;
            int cnt = it.second;

            if (cnt > 0) {
                for (int i = 0; i < k; i++) {
                    int curr = num + i;
                    if (mp[curr] < cnt) {
                        return false;
                    }

                    mp[curr] -= cnt;
                }
            }
        }

        return true;
    }
};
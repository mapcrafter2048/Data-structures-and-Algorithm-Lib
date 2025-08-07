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
You are given a 0-indexed integer array mapping which represents the mapping
rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped
to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each
occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in
non-decreasing order based on the mapped values of its elements.

Notes:

    Elements with the same mapped values should appear in the same relative
order as in the input. The elements of nums should only be sorted based on their
mapped values and not be replaced by them.

*/

/*
Detailed Solution and Steps of Implementation:

Problem Understanding:
1. We are given a mapping array `mapping` where `mapping[i]` represents the
digit `i` being mapped to digit `mapping[i]`.
2. We are also given an array `nums` of integers.
3. The task is to sort the array `nums` based on the "mapped value" of each
integer. The "mapped value" of an integer is obtained by replacing each digit of
the integer with its corresponding value in the `mapping` array.
4. The sorting should be stable, meaning that if two integers have the same
mapped value, their relative order in the original array should be preserved.

Steps of Implementation:
1. Define a helper function `changed(int num, vector<int> &mapping)`:
    - This function computes the mapped value of a given integer `num` using the
`mapping` array.
    - If `num` is 0, directly return `mapping[0]`.
    - Otherwise, extract each digit of `num`, map it using `mapping`, and
reconstruct the mapped value.

2. Define the main function `sortJumbled(vector<int> &mapping, vector<int>
&nums)`:
    - Create a vector of tuples `vec` to store the mapped value, the original
index, and the original number for each element in `nums`.
    - Iterate through `nums`, compute the mapped value for each number using the
`changed` function, and store the tuple `{mapped_value, index, original_number}`
in `vec`.
    - Use `stable_sort` to sort `vec` based on the mapped value. If two mapped
values are equal, the original index is used to maintain stability.
    - Extract the sorted numbers from `vec` into a new array `ans` and return
it.

3. Use the `stable_sort` function:
    - This ensures that the sorting is stable, preserving the relative order of
elements with the same mapped value.

4. Return the sorted array `ans`.

Key Points:
- The `changed` function handles the digit-by-digit mapping of each number.
- The use of `stable_sort` ensures that the sorting is stable.
- The auxiliary vector `vec` helps in associating the mapped value and original
index with each number, making it easier to sort and reconstruct the result.

Time Complexity:
- Computing the mapped value for each number takes O(d), where d is the number
of digits in the number. For n numbers, this is O(n * d).
- Sorting the array using `stable_sort` takes O(n * log(n)).
- Overall time complexity: O(n * d + n * log(n)).

Space Complexity:
- The auxiliary vector `vec` takes O(n) space.
- Overall space complexity: O(n).
*/
class Solution {
  public:
    int changed(int num, vector<int> &mapping) {
        if (num == 0) {
            return mapping[0];
        }

        int place = 1;
        int ans = 0;
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            int mapp = mapping[digit];
            ans += mapp * place;
            place *= 10;
        }

        return ans;
    }

    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        vector<vector<int>> vec;
        vec.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int newV = changed(nums[i], mapping);
            vec.push_back({newV, i, nums[i]});
        }

        sort(vec.begin(), vec.end(), [&](auto &a, auto &b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = (int)vec[i][2];
        }
        return ans;
    }
};
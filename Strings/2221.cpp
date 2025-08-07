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
You are given a 0-indexed integer array nums, where nums[i] is a digit between 0
and 9 (inclusive).

The triangular sum of nums is the value of the only element present in nums
after the following process terminates:

    Let nums comprise of n elements. If n == 1, end the process. Otherwise,
create a new 0-indexed integer array newNums of length n - 1. For each index i,
where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) %
10, where % denotes modulo operator. Replace the array nums with newNums. Repeat
the entire process starting from step 1.

Return the triangular sum of nums.
*/

class Solution {
  public:
    int triangularSum(vector<int> &nums) {
        string s = "";
        for (int num : nums) {
            s += to_string(num);
        }

        while (s.length() > 1) {
            string next = "";
            for (int i = 0; i < s.length() - 1; ++i) {
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                int sum = (a + b) % 10;
                next += to_string(sum);
            }
            s = next;
        }

        return s[0] - '0';
    }
};
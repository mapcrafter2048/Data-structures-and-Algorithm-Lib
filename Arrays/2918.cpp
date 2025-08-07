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

class Solution {
  public:
    long long minSum(vector<int> &nums1, vector<int> &nums2) {
        // 1) Compute sums of non-zero entries and counts of zeros in one pass.
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;
        for (int x : nums1) {
            if (x == 0)
                ++zero1;
            else
                sum1 += x;
        }
        for (int x : nums2) {
            if (x == 0)
                ++zero2;
            else
                sum2 += x;
        }

        // 2) Minimal possible sums when all zeros are replaced by 1.
        long long min1 = sum1 + zero1;
        long long min2 = sum2 + zero2;

        // 3) Handle the three main cases.
        // Case A: No zeros in either array.
        if (zero1 == 0 && zero2 == 0) {
            return (sum1 == sum2) ? sum1 : -1;
        }
        // Case B1: Only nums2 has no zeros.
        if (zero2 == 0) {
            // We can only raise sum1 from min1 upward; must exactly match sum2.
            return (sum2 >= min1) ? sum2 : -1;
        }
        // Case B2: Only nums1 has no zeros.
        if (zero1 == 0) {
            return (sum1 >= min2) ? sum1 : -1;
        }
        // Case C: Both have zeros.
        return max(min1, min2);
    }
};

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
You have two fruit baskets containing n fruits each. You are given two 0-indexed
integer arrays basket1 and basket2 representing the cost of fruit in each
basket. You want to make both baskets equal. To do so, you can use the following
operation as many times as you want:

    Chose two indices i and j, and swap the ith fruit of basket1 with the jth
fruit of basket2. The cost of the swap is min(basket1[i],basket2[j]).

Two baskets are considered equal if sorting them according to the fruit cost
makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.
*/

/*
Solution Logic:

1. **Understand the Problem**:
    - We are given two baskets of fruits represented by their costs.
    - We need to make both baskets equal by swapping fruits between them.
    - The cost of a swap is the minimum of the two fruit costs being swapped.
    - If it's impossible to make the baskets equal, return -1.

2. **Key Observations**:
    - For the baskets to be equal, the total frequency of each fruit across both
baskets must be even. If any fruit has an odd frequency, it's impossible to make
the baskets equal.
    - We need to calculate the minimum cost to balance the baskets.

3. **Steps to Solve**:
    - **Step 1**: Count the frequency of each fruit in both baskets combined.
      - If any fruit has an odd frequency, return -1.
    - **Step 2**: Calculate the excess fruits in each basket.
      - For each fruit, determine how many extra fruits are in `basket1` and
`basket2` compared to the balanced state.
      - Store these excess fruits in two separate vectors: `extra1` (excess in
`basket1`) and `extra2` (excess in `basket2`).
    - **Step 3**: Sort the excess fruits.
      - Sort `extra1` in ascending order and `extra2` in descending order to
minimize the cost of swaps.
    - **Step 4**: Calculate the minimum cost to balance the baskets.
      - For each pair of excess fruits from `extra1` and `extra2`, calculate the
cost of swapping directly or via the smallest fruit in both baskets (double the
global minimum fruit cost).
      - Accumulate the minimum cost for all swaps.

4. **Edge Cases**:
    - If the baskets are already equal, return 0.
    - If there are no excess fruits in either basket, return 0.
    - Handle cases where the baskets contain only one type of fruit or have very
large/small values.

5. **Complexity**:
    - Time Complexity: O(n log n) due to sorting of the excess fruits.
    - Space Complexity: O(n) for storing the frequency maps and excess fruits.

The implementation follows these steps to ensure correctness and efficiency.
*/

class Solution {
  public:
    long long minCost(vector<int> &basket1, vector<int> &basket2) {
        int n = basket1.size();
        unordered_map<int, int> freq;

        for (int x : basket1) {
            freq[x]++;
        }
        for (int x : basket2) {
            freq[x]++;
        }

        for (auto &p : freq) {
            if (p.second % 2 != 0)
                return -1;
        }

        unordered_map<int, int> count1, count2;
        for (int x : basket1)
            count1[x]++;
        for (int x : basket2)
            count2[x]++;

        vector<int> extra1, extra2;
        for (auto &p : freq) {
            int val = p.first;
            int diff = count1[val] - count2[val];
            if (diff > 0) {
                for (int i = 0; i < diff / 2; i++)
                    extra1.push_back(val);
            } else if (diff < 0) {
                for (int i = 0; i < (-diff) / 2; i++)
                    extra2.push_back(val);
            }
        }

        if (extra1.empty())
            return 0;

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        int global_min = min(*min_element(basket1.begin(), basket1.end()),
                             *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < extra1.size(); i++) {
            int x = extra1[i];
            int y = extra2[i];
            int direct = min(x, y);
            int via_double = 2 * global_min;
            cost += min(direct, via_double);
        }

        return cost;
    }
};
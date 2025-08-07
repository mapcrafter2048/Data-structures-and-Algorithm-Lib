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
An array is considered special if every pair of its adjacent elements contains
two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where
for queries[i] = [fromi, toi] your task is to check that

nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if
nums[fromi..toi] is special.
*/

/*
Logic: We can use a set to keep track of indices where adjacent elements have
the same parity. For each query, we can check if there are any such indices in
the range specified by the query. If there are no such indices, the subarray is
special.
Implementation Steps:
1. Initialize a set to store indices where adjacent elements have the same
parity.
2. Iterate through the array and populate the set with indices where adjacent
    elements have the same parity.
3. For each query, check if there are any indices in the set that fall within
the range specified by the query. If there are no such indices, the subarray is
   special.
*/

class Solution {
  public:
    vector<bool> isArraySpecial(vector<int> &nums,
                                vector<vector<int>> &queries) {
        set<int> bad;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if ((nums[i] % 2) == (nums[i + 1] % 2))
                bad.insert(i);
        }
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            auto it = bad.lower_bound(queries[i][0]);
            bool anst = (it == bad.end() || *it > queries[i][1] - 1);
            ans.push_back(anst);
        }

        return ans;
    }
};
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
A magician has various spells.

You are given an array power, where each element represents the damage of a
spell. Multiple spells can have the same damage value.

It is a known fact that if a magician decides to cast a spell with a damage of
power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] -
1, power[i] + 1, or power[i] + 2.

Each spell can be cast only once.

Return the maximum possible total damage that a magician can cast.
*/

/*
Detailed Solution Logic:

This problem is a variant of the "House Robber" or "Delete and Earn" dynamic
programming problem, but with a wider exclusion window (±2 instead of ±1).

Key Observations:
1. If you cast a spell with damage x, you cannot cast spells with damage x-2,
x-1, x+1, or x+2.
2. Multiple spells can have the same damage value, so you can sum up all spells
with the same damage and treat them as a single group.
3. The problem reduces to, for each unique damage value, deciding whether to
take all spells of that damage (and skip all values within 2 of it), or skip it
and move to the next.

Step-by-step Implementation:

Step 1: Count the frequency of each unique damage value.
- Use a map<int, int> to count how many times each damage value appears in the
input array.

Step 2: Extract and sort all unique damage values.
- Use a set to get unique values, then convert to a sorted vector for indexed
access.

Step 3: Prepare a DP array for memoization.
- The DP state is defined by the current index in the sorted unique damage
array.
- dp[i] will store the maximum total damage achievable starting from index i.

Step 4: Define the recursive DP function.
- For each index, you have two choices:
    a) Skip the current damage value: move to index+1.
    b) Take all spells of the current damage value:
        - Add total damage for this value (frequency * value).
        - Move to the next index where the damage value is more than 2 greater
than the current (i.e., powers[newindex] > powers[index] + 2).
- Return the maximum of the two choices and memoize the result.

Step 5: In the main function, build the frequency map, sorted unique damage
vector, and initialize the DP array.
- Call the DP function starting from index 0.

This approach ensures that all constraints are respected and the maximum
possible damage is calculated efficiently.

Implementation:
*/

class Solution {
  public:
    // Recursive DP function with memoization
    long long int solve(vector<long long int> &dp, map<int, int> &mp,
                        vector<int> &powers, int index) {
        // Base case: If we've considered all unique damage values
        if (index == powers.size()) {
            return 0;
        }

        // If already computed, return memoized result
        if (dp[index] != -1) {
            return dp[index];
        }

        // Option 1: Skip the current damage value
        long long int notake = solve(dp, mp, powers, index + 1);

        // Option 2: Take all spells of the current damage value
        long long int take = 0;
        int newindex = index + 1;
        // Find the next index where the damage value is more than 2 greater
        while (newindex < powers.size() &&
               powers[newindex] - powers[index] <= 2) {
            newindex++;
        }
        // Total damage for taking all spells of this value
        take = ((1ll) * mp[powers[index]] * powers[index]) +
               solve(dp, mp, powers, newindex);

        // Memoize and return the maximum of the two choices
        return dp[index] = max(notake, take);
    }

    long long maximumTotalDamage(vector<int> &power) {
        // Step 1: Count frequency of each damage value
        map<int, int> mp;
        for (int i = 0; i < power.size(); i++) {
            mp[power[i]]++;
        }

        // Step 2: Extract and sort unique damage values
        set<int> pow(power.begin(), power.end());
        vector<int> powers(pow.begin(), pow.end());

        // Step 3: Initialize DP array
        vector<long long int> dp(mp.size(), -1);

        // Step 4: Call the DP function starting from index 0
        return solve(dp, mp, powers, 0);
    }
};

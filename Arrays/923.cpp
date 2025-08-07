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
Given an integer array arr, and an integer target, return the number of tuples
i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.
*/

/*
Logic: We can use a hash map to store the count of pairs of elements that sum up
to a specific value. We iterate through the array, and for each element, we
check how many pairs of previous elements sum up to the target minus the current
element. We then update the hash map with the new pairs.
*/

class Solution {
  public:
    int threeSumMulti(vector<int> &arr, int target) {
        unordered_map<int, int> mp;
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            // Check how many pairs sum up to target - arr[i]
            ans = (ans + mp[target - arr[i]]) % mod;
            // Update the hash map with pairs formed with arr[i]
            for (int j = 0; j < i; j++) {
                mp[arr[i] + arr[j]]++;
            }
        }
        return ans;
    }
};

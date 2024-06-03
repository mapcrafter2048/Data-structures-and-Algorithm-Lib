/*
The XOR total of an array is defined as the bitwise XOR of all its elements, or
0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums.

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting
some (possibly zero) elements of b.
*/

#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
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

int subsetXORSum(vector<int> &nums) {
    int n = nums.size();
    int totalSum = 0;
    // Iterate through all possible subsets
    // The outer loop iterates over all possible subsets, represented as binary
    // numbers.
    for (int i = 0; i < (1 << n); i++) {
        int subsetXor = 0;
        // The inner loop checks each bit position of the subset representation
        // (i).
        for (int j = 0; j < n; j++) {
            // Check if the j-th element is in the i-th subset
            if (i & (1 << j)) {
                subsetXor ^= nums[j];
            }
        }
        totalSum += subsetXor;
    }
    return totalSum;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
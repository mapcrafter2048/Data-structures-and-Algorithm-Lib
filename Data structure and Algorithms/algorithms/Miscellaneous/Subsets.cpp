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

/*
The fundamental idea behind this code is to build subsets incrementally by
adding elements to existing subsets. Imagine starting with an empty subset, then
gradually adding one element from the input array at a time to create new
subsets.  We'll do this repeatedly until we've considered all possible
combinations.

so in the first iteration, we'll start with an empty subset and add an empty set
in the second iteration the subset will be {1} will be pushed in it as the inner
loop starts from 0 si in the first iteration of the inner loop when i = 0 so the
vector subset will be {} and then we will push num ino the subset vector which
is 1 so we will push {1} in the result.

now we push {2} and {1, 2} this is dues to the fact that the inner loop starts
from 0 upto the size and now the size is 2 so vector subset will be  result[i] =
result[0] = {} and then we will push 2 in it os the set {2} and when i = 1 so
the vector subset will be {1} so will push 2 in the susbet and hence we will
psuh {1, 2} in the result
*/

void printVector(vector<vector<int>> &result) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> result;

    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        result.push_back(subset);
    }

    return result;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    printVector(result);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool h(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if (target == 0) {
        return true;
    }
    if (ind == 0) {
        return arr[0] == target;
    }

    if (dp[ind][target] != -1) {
        return dp[ind][target];
    }

    bool notake = h(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target) {
        take = h(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = take || notake;
}

bool isSubsetSum(vector<int> &arr, int sum) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return h(n - 1, sum, arr, dp);
}

/*
Logic:
1. If the sum is 0, then we can always have an empty subset.
2. If the sum is not 0 and the number of elements is 0, then we can't have any
subset.
3. If the last element is greater than the sum, then we can't include it in the
subset.
4. If the last element is less than or equal to the sum, then we have two
choices: a. Include the last element in the subset. b. Exclude the last element
from the subset.
5. If any of the above two choices is true, then we can have a subset with the
given sum.
6. We can use a 2D dp array to store the results of the subproblems.
7. The dp[i][j] will be true if there is a subset of elements from arr[0....i]
with a sum equal to j.
8. The dp[i][j] will be false if there is no subset of elements from arr[0....i]
with a sum equal to j.
9. The base cases are: a. dp[0][0] = true, as we can have an empty subset with
sum 0. b. dp[0][arr[0]] = true, as we can have a subset with a single element
equal to the sum.
10. For the rest of the cases, the dp[i][j] can be true if: a. dp[i - 1][j] is
true, which means we can exclude the last element. b. dp[i - 1][j - arr[i]] is
true, which means we can include the last element.
11. If any of the above two cases is true, then dp[i][j] will be true.
12. The final answer will be dp[n - 1][sum].
13. The time complexity is O(n * sum), where n is the number of elements in the
array and sum is the given sum.
14. The space complexity is O(n * sum).
*/

int main() {
    // Your code here
    return 0;
}
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

class TreeNode {
  public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Node {
  public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

bool equalPartition(vector<int> &arr) {
    // code here
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum % 2 != 0) {
        return false;
    }

    int target = sum / 2;
    vector<int> dp(target + 1, false);

    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    return dp[target];
}

/*
Logic:
This problem is a variation of the subset sum problem. The subset sum problem is
a special case of the 0/1 knapsack problem. In the subset sum problem, we are
given a set of numbers and a target sum. We have to find whether there is a
subset of the given set that sums up to the target sum. In this problem, we have
to find whether we can partition the given set into two subsets such that the
sum of elements in both subsets is the same. If we can partition the set into
two subsets such that the sum of elements in both subsets is the same, then the
sum of the elements in each subset will be half of the total sum of the set. So,
we can solve this problem by finding whether there is a subset of the given set
that sums up to half of the total sum of the set. We can use the subset sum
problem to solve this problem. We can create a boolean array dp of size sum/2 +
1, where sum is the total sum of the set. dp[i] will be true if there is a
subset of the given set that sums up to i. We can initialize dp[0] to true
because there is an empty subset that sums up to 0. We can iterate over the
elements of the given set and update the dp array. For each element arr[i], we
can iterate over the dp array from sum/2 to arr[i] and update dp[j] to dp[j] ||
dp[j - arr[i]]. After updating the dp array, we can return dp[sum/2]. If
dp[sum/2] is true, then there is a subset of the given set that sums up to half
of the total sum of the set, and we can partition the set into two subsets such
that the sum of elements in both subsets is the same. Otherwise, we cannot
partition the set into two subsets such that the sum of elements in both subsets
is the same.

Example: arr = [1, 5, 11, 5]
sum = 22
target = 11
i = 0:
    j = 11:
        dp[11] = dp[11] || dp[11 - 1] = dp[11] || dp[10] = false || false = false
    j = 10:
        dp[10] = dp[10] || dp[10 - 1] = dp[10] || dp[9] = false || false = false
    j = 9:
        dp[9] = dp[9] || dp[9 - 1] = dp[9] || dp[8] = false || false = false
    j = 8:
        dp[8] = dp[8] || dp[8 - 1] = dp[8] || dp[7] = false || false = false
    j = 7:
        dp[7] = dp[7] || dp[7 - 1] = dp[7] || dp[6] = false || false = false
    j = 6:
        dp[6] = dp[6] || dp[6 - 1] = dp[6] || dp[5] = false || false = false
    j = 5:
        dp[5] = dp[5] || dp[5 - 1] = dp[5] || dp[4] = false || false = false
    j = 4:
        dp[4] = dp[4] || dp[4 - 1] = dp[4] || dp[3] = false || false = false
    j = 3:
        dp[3] = dp[3] || dp[3 - 1] = dp[3] || dp[2] = false || false = false
    j = 2:
        dp[2] = dp[2] || dp[2 - 1] = dp[2] || dp[1] = false || false = false
    j = 1:
        dp[1] = dp[1] || dp[1 - 1] = dp[1] || dp[0] = false || true = true
i = 1:
    j = 11:
        dp[11] = dp[11] || dp[11 - 5] = dp[11] || dp[6] = false || false = false
    j = 10:
        dp[10] = dp[10] || dp[10 - 5] = dp[10] || dp[5] = false || true = true
    j = 9:
        dp[9] = dp[9] || dp[9 - 5] = dp[9] || dp[4] = false || false = false
    j = 8:
        dp[8] = dp[8] || dp[8 - 5] = dp[8] || dp[3] = false || false = false
    j = 7:
        dp[7] = dp[7] || dp[7 - 5] = dp[7] || dp[2] = false || false = false
    j = 6:
        dp[6] = dp[6] || dp[6 - 5] = dp[6] || dp[1] = true || true = true
    j = 5:
        dp[5] = dp[5] || dp[5 - 5] = dp[5] || dp[0] = true || true = true


*/

int main() {
    // Your code here
    return 0;
}

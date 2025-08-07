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
You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and
a positive integer k. You must choose a subsequence of indices from nums1 of
length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

    The sum of the selected elements from nums1 multiplied with the minimum of
the selected elements from nums2. It can defined simply as: (nums1[i0] +
nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).

Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set
{0, 1, ..., n-1} by deleting some or no elements.
*/

/*
Logic: We need to maximize the score by selecting k elements from nums1 and
their corresponding elements from nums2. The score is calculated as the sum of
the selected elements from nums1 multiplied by the minimum of the selected
elements from nums2. To achieve this, we can sort the elements based on their
values in nums2 and use a priority queue to maintain the largest k elements from
nums1.

Implementation Steps:
1. Create a vector of pairs where each pair contains an element from nums2 and
   its corresponding element from nums1.
2. Sort this vector in descending order based on the values of nums2.
3. Use a priority queue to keep track of the largest k elements from nums1.
4. Iterate through the sorted vector, adding elements from nums1 to the priority
    queue and maintaining the sum of the selected elements.
5. If the size of the priority queue exceeds k, remove the smallest element.
6. When the size of the priority queue is exactly k, calculate the score and
   update the maximum score if the current score is greater.
7. Return the maximum score found.
*/

class Solution {
  public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int, int>> A;
        for (int i = 0; i < nums2.size(); i++) {
            A.push_back({nums2[i], nums1[i]});
        }

        sort(A.rbegin(), A.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long int sum = 0;
        long long int ans = 0;

        for (auto it : A) {
            pq.push(it.second);
            sum += it.second;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = max(ans, sum * it.first);
            }
        }

        return ans;
    }
};
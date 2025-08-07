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
You are given two integer arrays nums1 and nums2 both of the same length. The
advantage of nums1 with respect to nums2 is the number of indices i for which
nums1[i] > nums2[i].

Return any permutation of nums1 that maximizes its advantage with respect to
nums2
*/

/*
Logic: We can use a multiset to keep track of the elements in nums1. For each
element in nums2, we want to find the smallest element in nums1 that is greater
than the current element in nums2. If we can't find such an element, we can use
the smallest element in nums1.

Implementation Steps:
1. Create a vector of pairs from nums2, where each pair contains the element and
its index.
2. Sort this vector in descending order based on the elements.
3. Create a multiset from nums1 to allow for efficient retrieval of elements.
4. Iterate through the sorted vector of pairs, and for each element in nums2,
find the smallest element in nums1 that is greater than the current element.
5. If such an element is found, assign it to the corresponding index in the
result vector and remove it from the multiset. If not, assign the smallest
element from nums1.
6. Return the result vector.
*/

class Solution {
  public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        vector<pair<int, int>> nB;
        for (int i = 0; i < nums2.size(); i++) {
            nB.push_back({nums2[i], i});
        }

        sort(nB.rbegin(), nB.rend());

        multiset<int> ms(nums1.begin(), nums1.end());
        vector<int> ans(nums1.size());
        for (auto it : nB) {
            // Find the smallest element in nums1 that is greater than nums2[i]
            auto its = ms.upper_bound(it.first);
            // If no such element exists, use the smallest element in nums1
            if (its == ms.end()) {
                its = ms.begin();
            }
            // Assign the found element to the result at the index of nums2[i]
            // and remove it from the multiset
            ans[it.second] = *its;
            ms.erase(its);
        }

        return ans;
    }
};
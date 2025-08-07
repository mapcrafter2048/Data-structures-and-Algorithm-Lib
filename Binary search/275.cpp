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
Given an array of integers citations where citations[i] is the number of
citations a researcher received for their ith paper and citations is sorted in
non-descending order, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as
the maximum value of h such that the given researcher has published at least h
papers that have each been cited at least h times.

You must write an algorithm that runs in logarithmic time.
*/

/*
Logic: Since the citations array is sorted, we can use binary search to find the
h-index. The h-index is the largest index `i` such that the number of citations
at that index is greater than or equal to the number of papers that have been
published after that index.
Implementation Steps:
1. Initialize `low` to 0 and `high` to the size of the citations array.
2. While `low` is less than `high`, calculate the mid-point.
3. If the number of citations at mid is greater than or equal to the number of
    papers that have been published after mid, set `high` to mid.
4. Otherwise, set `low` to mid + 1.
5. Finally, return the number of papers that have been published after `low`.
*/

class Solution {
  public:
    int hIndex(vector<int> &cit) {
        int low = 0;
        int high = cit.size();

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (cit[mid] >= cit.size() - mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return cit.size() - low;
    }
};
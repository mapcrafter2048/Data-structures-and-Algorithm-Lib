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

#pragma GCC optimize("O2")

class Solution {
  public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
        auto canMakeCuts = [](vector<vector<int>> &rects, int axisStart,
                              int axisEnd) -> bool {
            sort(rects.begin(), rects.end(),
                 [axisStart](const vector<int> &a, const vector<int> &b) {
                     return a[axisStart] < b[axisStart];
                 });

            int cuts = 0, ends = -1;
            for (const auto &rect : rects) {
                int start = rect[axisStart];
                int end = rect[axisEnd];
                if (start >= ends)
                    cuts++;
                ends = max(ends, end);
                if (cuts >= 3)
                    return true;
            }
            return false;
        };

        vector<vector<int>> horizontal = rectangles;
        vector<vector<int>> vertical = rectangles;

        bool hor = canMakeCuts(horizontal, 0, 2);
        bool ver = canMakeCuts(vertical, 1, 3);

        return hor || ver;
    }
};

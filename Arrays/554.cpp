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
There is a rectangular brick wall in front of you with n rows of bricks. The ith
row has some number of bricks each of the same height (i.e., one unit) but they
can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If
your line goes through the edge of a brick, then the brick is not considered as
crossed. You cannot draw a line just along one of the two vertical edges of the
wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the
minimum number of crossed bricks after drawing such a vertical line.
*/

/*
Logic: We can use a map to keep track of the number of bricks crossed at each
vertical line position. For each row in the wall, we can calculate the prefix
sum of the widths of the bricks and update the map accordingly. The key in the
map will be the prefix sum, and the value will be the count of how many times
that prefix sum has been encountered. Finally, we can find the maximum count in
the map and subtract it from the total number of rows to get the minimum number
of crossed bricks.
*/

class Solution {
  public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<long long int, long long int> mp;
        // Calculate the prefix sums for each row and count occurrences
        for (long long int i = 0; i < wall.size(); i++) {
            long long int prefix = 0;
            // We do not consider the last brick in each row
            // because we cannot draw a line along the edge of the wall
            // and we want to avoid counting the last brick in each row
            for (long long int j = 0; j + 1 < wall[i].size(); j++) {
                prefix += wall[i][j];
                mp[prefix]++;
            }
        }

        long long int maxE = 0;
        for (auto it : mp) {
            maxE = max(maxE, it.second);
        }

        return wall.size() - maxE;
    }
};
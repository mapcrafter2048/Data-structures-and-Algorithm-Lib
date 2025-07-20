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

long long maximumValueSum(vector<int> &nums, int k,
                          vector<vector<int>> &edges) {
    long long totalSum = 0;
    int count = 0;
    int positiveMin = INT_MAX;
    int negativeMax = INT_MIN;

    for (int nodeValue : nums) {
        int nodeValAfterOperation = nodeValue ^ k;
        totalSum += nodeValue;
        int netChange = nodeValAfterOperation - nodeValue;

        if (netChange > 0) {
            positiveMin = min(positiveMin, netChange);
            totalSum += netChange;
            count += 1;
        } else {
            negativeMax = max(negativeMax, netChange);
        }
    }

    if (count % 2 == 0) {
        return totalSum;
    }
    return max(totalSum - positiveMin, totalSum + negativeMax);
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
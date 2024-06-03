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

int singleNumber(vector<int> &nums) {
    int answer = 0;
    for (int i = 0; i < nums.size(); i++) {
        answer = answer ^ nums[i];
    }

    return answer;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here
    vector<int> nums = {1, 2, 2};
    cout << singleNumber(nums) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
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
    for (int bitIndex = 0; bitIndex < 32; bitIndex++) { // Iterate over 32 bits
        int count = 0;
        for (int num : nums) {
            if ((num >> bitIndex) &
                1) { // Check the bit directly after shifting
                count++;
            }
        }
        if (count % 3 == 1) {
            answer |=
                (1 << bitIndex); // Set the corresponding bit in the answer
        }
    }
    return answer;
}

int singleNumber2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i = i + 3) {
        if (nums[i] != nums[i - 1]) {
            return nums[i - 1];
        }
    }
    return nums[nums.size() - 1];
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    vector<int> nums = {2, 2, 3, 2};
    cout << singleNumber(nums) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
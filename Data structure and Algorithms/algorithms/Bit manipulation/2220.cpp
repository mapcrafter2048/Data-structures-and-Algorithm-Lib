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

int minBitFlips(int start, int goal) {
    int result = start ^ goal;
    int count = 0;
    for (int i = 0; i < 31; i++) {
        if (result & (1 << i)) {
            count++;
        }
    }
    return count;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here
    int first = 10;
    int second = 7;
    cout << minBitFlips(first, second) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
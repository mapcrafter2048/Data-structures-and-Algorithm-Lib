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
You are given an integer num. You can swap two digits at most once to get the
maximum valued number.

Return the maximum valued number you can get.
*/

/*
Logic: We can convert the number to a string and then find the first digit
that can be swapped with a larger digit that appears later in the string. We
then perform the swap and return the new number.
Implementation Steps:
1. Convert the number to a string.
2. Create a vector to store the original digits.
3. Create a sorted version of the digits in descending order.
4. Iterate through the digits and find the first position where the original
    digit is less than the sorted digit.
5. If such a position is found, find the last occurrence of the sorted digit
   in the original vector.
6. Swap the digits at these two positions.
7. Convert the modified vector back to a string and return the integer value.
*/

class Solution {
  public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<char> orig(s.begin(), s.end());

        vector<char> desc = orig;
        sort(desc.begin(), desc.end(), greater<char>());

        int i = 0;
        // Find the first position where the original digit is less than the
        // sorted digit
        while (i < n && orig[i] == desc[i]) {
            ++i;
        }
        if (i == n) {
            return num;
        }

        int j = n - 1;
        // Find the last occurrence of the sorted digit in the original vector
        while (orig[j] != desc[i]) {
            --j;
        }

        swap(orig[i], orig[j]);
        string t(orig.begin(), orig.end());
        return stoi(t);
    }
};

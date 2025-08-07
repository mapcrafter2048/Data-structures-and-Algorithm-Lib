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
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.
*/

/*
The solution uses a stack to efficiently calculate the number of days until a
warmer temperature for each day in the input array.

Steps of Solution:
1. Iterate through the temperature array.
2. Use a stack to keep track of indices of temperatures that haven't found a
warmer day yet.
3. For each temperature, check if it is warmer than the temperature at the index
stored at the top of the stack.
4. If it is, calculate the difference in days, update the result for that index,
and pop the stack.
5. Repeat the process until the stack is empty or the current temperature is not
warmer.
6. Push the current index onto the stack.
7. At the end of the iteration, any indices left in the stack correspond to days
with no warmer temperature in the future, so their result remains 0.

Steps of Implementation:
1. Initialize a vector `ans` of the same size as the input array `temp` to store
the result, with all elements set to 0.
2. Create an empty stack `st` to store indices of the temperatures.
3. Loop through the input array `temp` using an index `i`.
4. Inside the loop, use a `while` loop to check if the stack is not empty and
the current temperature `temp[i]` is greater than the temperature at the index
stored at the top of the stack.
5. If the condition is true, calculate the difference in days (`i - st.top()`),
update `ans[st.top()]`, and pop the stack.
6. Push the current index `i` onto the stack.
7. After the loop, return the result vector `ans`.
*/

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temp) {
        vector<int> ans(temp.size());
        stack<int> st;

        for (int i = 0; i < temp.size(); i++) {
            while (!st.empty() && temp[st.top()] < temp[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
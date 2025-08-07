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
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced
if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]=
'a'.

Return the minimum number of deletions needed to make s balanced.
*/

/*
Approach:
1. Initialize a stack to keep track of the characters.
2. Iterate through the string:
   - If the stack is not empty and the top is 'b' and the current character is
'a', pop the stack and increment the deletion count.
   - Otherwise, push the current character onto the stack.
3. The deletion count will be the minimum deletions needed to make the string
balanced.
*/

class Solution {
  public:
    int minimumDeletions(string s) {
        int n = s.size();
        stack<char> st;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() == 'b' && s[i] == 'a') {
                st.pop();
                cnt++;
            } else {
                st.push(s[i]);
            }
        }

        return cnt;
    }
};
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
A company has n employees with a unique ID for each employee from 0 to n - 1.
The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i]
is the direct manager of the i-th employee, manager[headID] = -1. Also, it is
guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent
piece of news. He will inform his direct subordinates, and they will inform
their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct
subordinates (i.e., After informTime[i] minutes, all his direct subordinates can
start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent
news.
*/

/*
Solution Logic:

The problem can be solved using Depth First Search (DFS) on the tree structure
formed by the employees and their managers. The goal is to calculate the maximum
time required to inform all employees starting from the head of the company.

Steps of Implementation:

1. Parse the input to construct an adjacency list representation of the tree:
    - Each manager points to their direct subordinates.
    - Use a hash map (unordered_map) where the key is the manager's ID, and the
value is a vector of IDs of their direct subordinates.

2. Use a DFS approach to traverse the tree:
    - Start from the head of the company (`headID`).
    - Recursively calculate the time required to inform all subordinates.

3. At each node (employee):
    - Add the `informTime` of the current employee to the cumulative time.
    - Propagate this updated cumulative time to their subordinates.

4. Keep track of the maximum time encountered during the traversal:
    - Use a global variable `time` to store the maximum time required to inform
all employees.

5. Return the maximum time as the result:
    - After the DFS traversal completes, the `time` variable will hold the total
time required to inform all employees.

Detailed Steps:

1. Create an adjacency list `adj`:
    - Iterate through the `manager` array.
    - For each employee `i`, if `manager[i] != -1`, add `i` to the list of
subordinates of `manager[i]` in the adjacency list.

2. Implement a recursive DFS function:
    - The function takes the current employee ID (`emp`), the cumulative time so
far (`ctime`), the adjacency list (`adj`), and the `informTime` array.
    - Update the global `time` variable to the maximum of its current value and
`ctime`.
    - For each subordinate of the current employee, call the DFS function
recursively, passing the subordinate's ID and the updated cumulative time
(`ctime + informTime[emp]`).

3. Initialize the DFS traversal:
    - Start the DFS from the head of the company (`headID`) with an initial
cumulative time of 0.

4. Return the result:
    - After the DFS traversal completes, return the value of the global `time`
variable, which represents the total time required to inform all employees.
*/

class Solution {
  public:
    int time = 0;

    void dfs(unordered_map<int, vector<int>> &adj, vector<int> &it, int emp,
             int ctime) {
        time = max(time, ctime);
        for (int em : adj[emp]) {
            dfs(adj, it, em, ctime + it[emp]);
        }
    }

    int numOfMinutes(int n, int hi, vector<int> &man, vector<int> &it) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < man.size(); i++) {
            if (man[i] != -1) {
                adj[man[i]].push_back(i);
            }
        }
        dfs(adj, it, hi, 0);
        return time;
    }
};

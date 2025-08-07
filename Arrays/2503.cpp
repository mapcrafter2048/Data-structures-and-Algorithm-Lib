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
Approach 1: Brute Force (TLE)
Intuition

For each query value, we need to determine how many cells in the grid have a
value strictly less than the query while ensuring we only move to adjacent
cells. This naturally forms a graph traversal problem where each cell is treated
as a node connected to its adjacent cells. Since we are interested in finding
all reachable nodes that satisfy a condition, Breadth-First Search (BFS) is a
suitable choice. BFS explores all nodes at the current level before moving to
the next, ensuring we do not miss any reachable cells that meet the criteria.

For each query, we begin at the (0,0) cell and initialize a queue for BFS
traversal. We also maintain a visited boolean matrix to ensure we do not revisit
cells. The traversal continues as long as there are unprocessed cells in the
queue. At each step, we check if the current cell’s value is greater than or
equal to the query value. If it is, we cannot proceed further from this cell.
Otherwise, we count the cell as visited, increment our result, and attempt to
move to its four adjacent cells (up, down, left, and right). Any adjacent cell
that has not been visited and has a value strictly less than the query is added
to the queue.

Since each query is independent, we repeat this process for each of them. The
final result for each query is the total number of unique cells that we were
able to visit while following the movement constraints. Algorithm

    Get the number of rows (rowCount) and columns (colCount) in grid.

    Initialize result array to store the number of points for each query.

    Define DIRECTIONS array to facilitate movement in four directions.

    Iterate over each query:

        Extract queryValue from queries.

        Initialize a BFS queue starting from (0,0).

        Create a visited matrix to track visited cells and mark (0,0) as
visited.

        Initialize points to count valid cells.

        Perform BFS:
            Get the current queue size to process all elements at this level.
            Iterate over the queue:
                Extract currentRow and currentCol from the front.
                If grid[currentRow][currentCol] >= queryValue, skip processing.
                Otherwise, increment points.
                Explore four possible directions:
                    Compute newRow and newCol as the adjacent cell.
                    If within bounds, not visited, and value is < queryValue,
mark (newRow, newCol) as visited and add it to the queue.

        Store points in result at the corresponding query index.

    Return result, containing the count of valid points for each query.

*/

class Solution {
  public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        vector<int> result(queries.size(), 0);
        // Directions for moving in 4 directions (right, down, left, up)
        vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Iterate through each query value
        for (int queryIndex = 0; queryIndex < queries.size(); queryIndex++) {
            int queryValue = queries[queryIndex];
            queue<pair<int, int>> bfsQueue;
            // Start BFS from the top-left corner
            bfsQueue.push({0, 0});
            vector<vector<bool>> visited(rowCount,
                                         vector<bool>(colCount, false));
            // Mark the starting cell as visited
            visited[0][0] = true;
            int points = 0;

            // BFS traversal
            while (!bfsQueue.empty()) {
                int queueSize = bfsQueue.size();
                while (queueSize--) {
                    auto [currentRow, currentCol] = bfsQueue.front();
                    bfsQueue.pop();

                    // If the current cell's value is greater than or equal to
                    // queryValue, stop expanding from here
                    if (grid[currentRow][currentCol] >= queryValue)
                        continue;

                    // Count the valid cell
                    points++;

                    // Explore all four possible directions
                    for (auto [rowOffset, colOffset] : DIRECTIONS) {
                        int newRow = currentRow + rowOffset,
                            newCol = currentCol + colOffset;

                        // Ensure the new position is within bounds and has not
                        // been visited
                        if (newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                            newCol < colCount && !visited[newRow][newCol] &&
                            grid[newRow][newCol] < queryValue) {
                            bfsQueue.push({newRow, newCol});
                            // Mark the new cell as visited
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
            // Store the result for the current query
            result[queryIndex] = points;
        }
        return result;
    }
};

/*
Approach 2: Sorting Queries + Min-Heap Expansion
Intuition

In the brute force approach, we restart the search from the top-left corner for
every query, treating each query as an independent problem. This results in a
significant amount of redundant work because many queries share overlapping
information. If a smaller query has already determined that certain cells are
accessible, then a larger query should be able to reuse that information instead
of starting from scratch. This suggests that instead of treating each query
separately, we can process them in an order that allows us to build on
previously discovered results, avoiding unnecessary recomputation.

A natural way to achieve this is to sort the queries in increasing order while
keeping track of their original indices. By doing this, we ensure that when we
process a query, all smaller queries have already been resolved. This allows us
to maintain a growing region of accessible cells rather than restarting the
search for each query.

To efficiently manage this expanding region, we use a min-heap (priority queue).
The heap allows us to always expand from the lowest-value cell first, ensuring
that we process cells in the correct order. We begin by inserting the top-left
cell (grid[0][0], (0,0)) into the heap.

As long as the smallest cell in the heap has a value less than the current
query, we remove it from the heap, mark it as visited, and attempt to expand
outward by pushing all its unvisited neighbors into the heap. Since the heap
maintains the smallest-value cell at the top, this ensures that we always expand
the lowest-value region before moving to higher values. If the smallest cell's
value is greater than or equal to the current query's value, we store the
current count of reachable cells in the answer array and continue expanding with
the next query's value as the new threshold.

By the time we process a query, all the cells that could have been visited with
smaller query values have already been handled. This allows us to directly store
the number of reachable cells without restarting the traversal. Instead of
performing redundant BFS searches for each query, we maintain a continuous
expansion process, ensuring that each cell is processed only once. Algorithm

    Get the number of rows (rowCount) and columns (colCount) in grid.

    Initialize result array to store the number of points for each query.

    Define DIRECTIONS array to facilitate movement in four directions.

    Create a sortedQueries array to store queries along with their original
indices.

    Sort sortedQueries by query values in ascending order.

    Initialize a min-heap (minHeap) to expand cells in increasing order of grid
values.

    Create a visited matrix to track processed cells and mark (0,0) as visited.

    Push {grid[0][0], {0, 0}} into minHeap to start expansion.

    Initialize totalPoints to count valid cells.

    Iterate over sorted queries:
        Extract queryValue and queryIndex.
        Expand cells while minHeap contains values < queryValue:
            Pop the smallest cellValue and its position.
            Increment totalPoints.
            Explore four possible directions:
                Compute newRow and newCol as the adjacent cell.
                If within bounds and not visited, push {grid[newRow][newCol],
{newRow, newCol}} into minHeap and mark the cell as visited. Store totalPoints
in result at the corresponding query index.

    Return result, containing the count of valid points for each query.

*/

class Solution {
  public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        vector<int> result(queries.size(), 0);
        // Directions for movement (right, down, left, up)
        vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Store queries along with their original indices to restore order
        // later
        vector<pair<int, int>> sortedQueries;
        for (int index = 0; index < queries.size(); index++) {
            sortedQueries.push_back({queries[index], index});
        }
        // Sort queries by value in ascending order
        sort(sortedQueries.begin(), sortedQueries.end());

        // Min-heap (priority queue) to process cells in increasing order of
        // value
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            minHeap;
        vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
        // Keeps track of the number of cells processed
        int totalPoints = 0;
        // Start from the top-left cell
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        // Process queries in sorted order
        for (auto [queryValue, queryIndex] : sortedQueries) {
            // Expand the cells that are smaller than the current query value
            while (!minHeap.empty() && minHeap.top().first < queryValue) {
                auto [cellValue, position] = minHeap.top();
                minHeap.pop();
                int currentRow = position.first, currentCol = position.second;
                // Increment count of valid cells
                totalPoints++;

                // Explore all four possible directions
                for (auto [rowOffset, colOffset] : DIRECTIONS) {
                    int newRow = currentRow + rowOffset,
                        newCol = currentCol + colOffset;

                    // Check if the new cell is within bounds and not visited
                    if (newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                        newCol < colCount && !visited[newRow][newCol]) {
                        minHeap.push({grid[newRow][newCol], {newRow, newCol}});
                        // Mark as visited
                        visited[newRow][newCol] = true;
                    }
                }
            }
            // Store the result for this query
            result[queryIndex] = totalPoints;
        }
        return result;
    }
};

/*
Approach 3: Using Priority Queue with Binary Search
Intuition

In the previous approach, we processed queries sequentially and used a min-heap
to expand the reachable region in increasing order, allowing us to efficiently
determine the number of points collected for each query. In this approach, we
will separate the precomputation step from the answer calculation to improve
algorithmic clarity.

To implement this, we can preprocess the grid once and store the results in a
structured way so that queries can be answered in constant or logarithmic time.
The key insight is that every cell in the grid has a minimum value threshold
that must be met in order for it to be reached. If we can determine the smallest
query value required to reach each number of points, we can use binary search to
efficiently answer all queries.

So we will begin by treating this as a shortest-path problem where we want to
determine the minimum "effort" required to reach each cell. We can use
Dijkstra’s algorithm with a min-heap to explore the grid in order of increasing
cost. Each cell (i, j) is processed in order of its minimum required value, and
we update its neighbors with the maximum value seen along the way. This ensures
that we always determine the optimal way to reach a cell.

Thus, our approach will be divided into three key steps:

    Reformulating the Problem as a Shortest-Path Search
    Running Dijkstra’s Algorithm
    Answering Queries Using Binary Search

Step 1: Reformulating the Problem as a Shortest-Path Search

Instead of handling each query separately, we treat the grid as a weighted graph
where each cell (i, j) has a weight equal to grid[i][j]. The goal is to expand
outwards from (0,0), adding cells in increasing order of their values. We need
to determine the minimum effort required to reach each cell, which means that a
Dijkstra-like algorithm is appropriate.

We use a min-heap (priority queue) to always expand the cell with the lowest
current value. Each time we expand to a new cell, we record the maximum value
encountered along that path. This ensures that we always determine the optimal
way to reach a cell before processing its neighbors.

To keep track of how many points can be collected for any given query threshold,
we maintain an array thresholdForMaxPoints, where thresholdForMaxPoints[k]
stores the smallest query value required to collect k points. Step 2: Running
Dijkstra’s Algorithm

We begin by initializing a min-heap with the starting cell (0,0), assigning it a
value equal to grid[0][0]. This heap will allow us to always expand towards the
next reachable cell with the smallest value, ensuring that we process cells in
the correct order.

As we expand outward, we repeatedly extract the smallest value from the heap,
which represents the next cell to be processed. From there, we attempt to move
to the neighboring cells, as long as they are not already visited— this
guarantees that we always find the optimal path to reach it.

For each newly reached cell (i, j), we compute the minimum threshold required to
access it. This is determined by taking the maximum value encountered along the
path leading to that cell. In other words, we track the largest value that must
be surpassed in order to reach (i, j).

As we continue expanding, we maintain an array thresholdForMaxPoints, where each
entry records the smallest query value required to collect a given number of
points. Each time we reach a new cell, we store its threshold in this array,
associating it with the number of cells we have accessed so far.

By the end of this process, thresholdForMaxPoints[k] holds the minimum query
value needed to collect exactly k points. Step 3: Answering Queries Using Binary
Search

Once we have preprocessed the grid, answering a query reduces to a simple binary
search on thresholdForMaxPoints. Since we stored thresholds in increasing order,
binary search allows us to determine in logarithmic time how many points can be
collected for a given query.

For a query threshold, we search for the largest index k such that
thresholdForMaxPoints[k] < threshold. The answer to the query is simply k, the
number of points that can be collected.

The algorithm is visualized below:

Current
Algorithm

    Define DIRECTIONS to facilitate movement in four directions.

    Initialize result array to store the number of points for each query.

    Get rowCount and colCount from grid, compute totalCells = rowCount *
colCount.

    Create thresholdForMaxPoints, where index i stores the minimum query value
required to reach i cells.

    Create minValueToReach, where minValueToReach[i][j] holds the maximum value
encountered to reach (i, j), initialized to MAX_VALUE.

    Run Dijkstra’s algorithm:
        Use minHeap (min-priority queue) to explore cells in increasing order of
encountered values. Start from (0,0), setting minValueToReach[0][0] = grid[0][0]
and pushing it into minHeap. While minHeap is not empty: Extract the cell with
the smallest encountered value. Store the encountered value in
thresholdForMaxPoints[++visitedCells]. Explore four possible directions: If the
adjacent cell (newRow, newCol) is within bounds and unvisited: Update its
minValueToReach as the maximum of the value to reach the current cell and
grid[newRow][newCol]. Push it into minHeap.

    Process queries using binary search:
        For each queries[i], find the rightmost mid where
thresholdForMaxPoints[mid] < threshold. Initialize left = 0, right = totalCells.
        Perform binary search:
            Compute mid = (left + right + 1) / 2.
            If thresholdForMaxPoints[mid] < threshold, move left = mid.
            Otherwise, adjust right = mid - 1.
        Store left in result[i].

    Return result, containing the number of points collected for each query.

*/

class Solution {
  public:
    static constexpr int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        int queryCount = queries.size();
        vector<int> result(queryCount);
        int rowCount = grid.size();
        int colCount = grid[0].size();

        int totalCells = rowCount * colCount;
        vector<int> thresholdForMaxPoints(totalCells + 1);

        vector<vector<int>> minValueToReach(rowCount,
                                            vector<int>(colCount, INT_MAX));

        minValueToReach[0][0] = grid[0][0];

        // Min-heap for processing cells in increasing order of their maximum
        // encountered value.
        priority_queue<array<int, 3>, vector<array<int, 3>>,
                       greater<array<int, 3>>>
            minHeap;
        minHeap.push({grid[0][0], 0, 0});
        int visitedCells = 0;

        // Dijkstra's algorithm to compute minValueToReach for each cell
        while (!minHeap.empty()) {
            array<int, 3> current = minHeap.top();
            minHeap.pop();

            // Store the value required to reach `visitedCells` points.
            thresholdForMaxPoints[++visitedCells] = current[0];

            // Explore all possible directions.
            for (const auto &direction : DIRECTIONS) {
                int newRow = current[1] + direction[0];
                int newCol = current[2] + direction[1];

                // Check if the new position is within bounds and not visited
                // before.
                if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                    newCol < colCount &&
                    minValueToReach[newRow][newCol] == INT_MAX) {
                    // The max value encountered on the path to this cell.
                    minValueToReach[newRow][newCol] =
                        max(current[0], grid[newRow][newCol]);

                    // Add the cell to the heap for further exploration.
                    minHeap.push(
                        {minValueToReach[newRow][newCol], newRow, newCol});
                }
            }
        }

        // Use binary search to determine the maximum number of points that can
        // be collected for each query.
        for (int i = 0; i < queryCount; i++) {
            int threshold = queries[i];
            int left = 0, right = totalCells;

            // Find the rightmost number of points we can collect before
            // exceeding the query threshold.
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (thresholdForMaxPoints[mid] < threshold) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }

            // Return `left`.
            result[i] = left;
        }

        return result;
    }
};
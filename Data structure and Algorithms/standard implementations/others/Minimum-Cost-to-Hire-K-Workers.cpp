#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
{
    vector<pair<double, int>> ratio;
    for (int i = 0; i < quality.size(); i++)
    {
        ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], i);
    }

    sort(ratio.begin(), ratio.end());
    priority_queue<int> pq;
    int goodQuality = 0;
    double currentRate = 0.0;

    for (int i = 0; i < k; i++)
    {
        goodQuality += quality[ratio[i].second];
        currentRate = max(currentRate, ratio[i].first);
        pq.push(quality[ratio[i].second]);
    }

    double result = currentRate * goodQuality;

    for (int i = k; i < ratio.size(); i++)
    {
        currentRate = max(currentRate, ratio[i].first);
        goodQuality -= pq.top();
        pq.pop();

        goodQuality += quality[ratio[i].second];
        pq.push(quality[ratio[i].second]);
        result = min(result, currentRate * goodQuality);
    }

    return result;
}

int main()
{
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
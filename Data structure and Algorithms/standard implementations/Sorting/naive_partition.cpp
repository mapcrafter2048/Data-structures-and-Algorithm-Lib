#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>

using namespace std;

void partition(int arr[], int low, int high, int partition)
{
    // int temp[high - low + 1], k = 0;
    vector<int> temp;
    int index = 0;
    for (int i = low; i <= high; i++)
    {
        if (arr[i] < arr[partition])
        {
            temp.push_back(arr[i]);
        }
    }
    for (int i = low; i <= high; i++)
    {
        if (arr[i] > arr[partition])
        {
            temp.push_back(arr[i]);
        }
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int main()
{

    return 0;
}
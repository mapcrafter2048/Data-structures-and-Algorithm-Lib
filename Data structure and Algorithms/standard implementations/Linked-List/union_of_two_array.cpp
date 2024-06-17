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

void union_array2(int a[], int b[], int m, int n)
{
    vector<int> vec;
    for (int i = 0; i < m; i++)
    {
        vec.push_back(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        vec.push_back(b[i]);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        if (i > 0 && vec[i] == vec[i - 1])
        {
            continue;
        }
        cout << vec[i] << " ";
    }
}

void union_array(int a[], int b[], int m, int n)
{
    vector<int> vec;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            continue;
        }
        if (j > 0 && a[j - 1] == a[j])
        {
            continue;
        }
        if (a[i] < b[j])
        {
            vec.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j])
        {
            vec.push_back(b[j]);
            j++;
        }
        else
        {
            vec.push_back(a[i]);
            i++;
            j++;
        }
    }
    while (i < m)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            continue;
        }
        vec.push_back(a[i]);
    }
    while (j < m)
    {
        if (j > 0 && a[j - 1] == a[j])
        {
            continue;
        }
        vec.push_back(b[j]);
    }
}

int main()
{

    return 0;
}
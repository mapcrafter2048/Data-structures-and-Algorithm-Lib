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

void interscetionaive(int a[], int b[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                cout << a[i] << " ";
                break;
            }
        }
    }
}

void intersection(int a[], int b[], int m, int n)
{
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            continue;
        }
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] > a[i])
        {
            j++;
        }
        else
        {
            cout << a[i] << " ";
        }
    }
}

int main()
{

    return 0;
}
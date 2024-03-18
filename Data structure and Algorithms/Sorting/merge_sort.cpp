#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>

void merge(int a[], int b[], int m, int n)
{
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < m)
    {
        cout << a[i] << " ";
    }
    while (j < n)
    {
        cout << b[j] << " ";
    }
}

void merge2(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1; // since mid is include so we do +1
    int n2 = high - mid; // the size of the second array
    vector<int> left(n1); 
    vector<int> right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[low + i];   // copy all the elements 
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = a[n1 + i]; // copy all the elements
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
            k++;
        }
        else
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int r){
    if(r > l){
        int m  = l +  (r -l)/2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge2(a, l, m, r);
    }
}

using namespace std;

int main()
{

    return 0;
}
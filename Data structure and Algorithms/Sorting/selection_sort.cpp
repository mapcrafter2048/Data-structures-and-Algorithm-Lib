#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <chrono>

using namespace std;

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void selectionsortnaive(int arr[], int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        int min_index = 0;
        for (int j = 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
            temp.push_back(arr[min_index]);
            arr[min_index] = INT_MIN;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    const int arraySizes[] = {500, 50000};
    srand(time(0));

    for (int arrSize : arraySizes)
    {
        int *sortedInput = new int[arrSize];
        int *reverseSortedInput = new int[arrSize];
        int *randomizedInput = new int[arrSize];

        for (int i = 0; i < arrSize; i++)
        {
            sortedInput[i] = i;
            reverseSortedInput[i] = arrSize - i;
            randomizedInput[i] = rand() % arrSize;
        }

        clock_t start, end;
        double duration;

        start = clock();
        selectionsort(sortedInput, arrSize);
        end = clock();
        duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
        cout << "Sorted Input Runtime for " << arrSize << " elements: " << duration << " microseconds" << endl;

        start = clock();
        selectionsort(reverseSortedInput, arrSize);
        end = clock();
        duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
        cout << "Reverse Sorted Input Runtime for " << arrSize << " elements: " << duration << " microseconds" << endl;

        start = clock();
        selectionsort(randomizedInput, arrSize);
        end = clock();
        duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
        cout << "Randomized Input Runtime for " << arrSize << " elements: " << duration << " microseconds" << endl;

        delete[] sortedInput;
        delete[] reverseSortedInput;
        delete[] randomizedInput;
    }

    return 0;
}
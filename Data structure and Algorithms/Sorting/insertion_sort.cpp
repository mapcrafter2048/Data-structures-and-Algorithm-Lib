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

/**
 * Sorts an array using the insertion sort algorithm.
 *
 * @param arr the array to be sorted
 * @param n the number of elements in the array
 *
 * @return void
 *
 * @throws None
 */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
        insertionSort(sortedInput, arrSize);
        end = clock();
        duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
        cout << "Sorted Input Runtime for " << arrSize << " elements: " << duration << " microseconds" << endl;

        start = clock();
        insertionSort(reverseSortedInput, arrSize);
        end = clock();
        duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
        cout << "Reverse Sorted Input Runtime for " << arrSize << " elements: " << duration << " microseconds" << endl;

        start = clock();
        insertionSort(randomizedInput, arrSize);
        end = clock();
        duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
        cout << "Randomized Input Runtime for " << arrSize << " elements: " << duration << " microseconds" << endl;

        delete[] sortedInput;
        delete[] reverseSortedInput;
        delete[] randomizedInput;
    }

    return 0;
}
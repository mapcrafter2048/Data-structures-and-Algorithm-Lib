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

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubblesortoptimized(int arr[], int n){
    
    for (int i = 0; i < n - 1; i++)
    {
        bool swaped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        }
        if(swaped == false){
            break;
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

int main() {
    const int arraySizes[] = {500, 50000};
    srand(time(0));

    for (int arrSize : arraySizes) {
        int* sortedInput = new int[arrSize];
        int* reverseSortedInput = new int[arrSize];
        int* randomizedInput = new int[arrSize];

        for (int i = 0; i < arrSize; i++) {
            sortedInput[i] = i;
            reverseSortedInput[i] = arrSize - i;
            randomizedInput[i] = rand() % arrSize;
        }

        clock_t start, end;
        double duration;

        start = clock();
        bubblesort(sortedInput, arrSize);
        end = clock();
        duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
        cout << "Sorted Input Runtime for " << arrSize << " elements: " << duration << " microseconds" << endl;

        start = clock();
        bubblesort(reverseSortedInput, arrSize);
        end = clock();
        duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
        cout << "Reverse Sorted Input Runtime for " << arrSize << " elements: " << duration << " microseconds" << endl;

        start = clock();
        bubblesort(randomizedInput, arrSize);
        end = clock();
        duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
        cout << "Randomized Input Runtime for " << arrSize << " elements: " << duration << " microseconds" << endl;

        delete[] sortedInput;
        delete[] reverseSortedInput;
        delete[] randomizedInput;
    }

    return 0;
}
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

class MinHeap
{
public:
    int *arr;
    int size;
    int capacity;

    MinHeap(int maxCapacity)
    {
        capacity = maxCapacity;
        arr = new int[maxCapacity];
        size = 0;
    }

    void insert(int x)
    {
        if (size == capacity)
        {
            // The heap is full, cannot insert more elements
            return;
        }

        // Insert the new element at the end of the heap
        arr[size] = x;
        size++;

        // Maintain the min-heap property by performing a heapify-up operation
        heapifyUp(size - 1);
    }

private:
    // Helper function to maintain the min-heap property (heapify-up)
    void heapifyUp(int index)
    {
        int parent = (index - 1) / 2;

        while (index > 0 && arr[index] < arr[parent])
        {
            std::swap(arr[index], arr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
};

int main()
{

    return 0;
}
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

struct queue
{
    int size, cap;
    int *array;

    queue(int c)
    {
        cap = c;
        size = 0;
        array = new int[cap];
    }

    bool isFull()
    {
        return (size == cap);
    }

    bool isEmpty()
    {
        return (size == 0);                 
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            return;
        }
        array[size] = x;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }
        for (int i = 0; i < size - 1; i++)
        {
            array[i] = array[i + 1];
            size--;
        }
    }
};

int main()
{

    return 0;
}
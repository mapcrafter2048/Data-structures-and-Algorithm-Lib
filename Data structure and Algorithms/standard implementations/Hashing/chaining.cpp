#include <iostream>
#include <list>
using namespace std;

class hash
{

    int bucket;
    list<int> *tabel;
    hash(int b)
    {
        b = bucket;
        tabel = new list<int>[b];
    }

    void insert(int key)
    {   
        int i = key % bucket;
        tabel[i].push_back(key);
    }

    void remove(int key)
    {
        int i = key % bucket;
        tabel[i].remove(key);
    }

    bool search(int key)
    {
        int i = key % bucket;
        for (auto x : tabel[i])
        {
            if (x == key)
            {
                return true;
            }
            return false;
        }
    }
};

int main()
{

    return 0;
}
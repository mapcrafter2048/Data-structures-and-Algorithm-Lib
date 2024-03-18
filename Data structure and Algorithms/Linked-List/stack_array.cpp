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

struct mystack{
    int *array;
    int cap;
    int top;
    mystack(int c){
        cap = c;
        array = new int[cap];
        top = -1;
    }

    void push(int x){
        top ++;
        array[top] = x;
    }

    int pop(){
        int res = array[top];
        top--;
        return res;
    }

    int peek(){
        return array[top];
    }
    
    int size(){
        return top+1;
    }
};

int main()
{

    return 0;

}
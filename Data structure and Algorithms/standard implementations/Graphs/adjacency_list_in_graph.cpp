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

void addedge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printgraph(vector<int> adj[], int v){
    for(int i = 0;  i < v; i++){
        for(int x: adj[i]){
            cout << x << " ";
        }
    }
}

int main()
{

    return 0;

}
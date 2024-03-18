#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class graph {
public:
    vector<vector<int>> vec;

    graph() {
        vec = { {0} };
    }
    graph(int n) {
        vec = { {n} };
    }
    graph(vector<vector<int>> v) {
        vec = v;
    }
    void insert(vector<int> edge) {
        int ver = edge[0];
        int ter = edge[1];
        bool input = false;
        for (int i = 0; i < size(vec); i++) {
            if (vec[i][0] == ver) {
                for (int j = 1; j < size(vec[i]); j++) {
                    if (vec[i][j] == ter) {
                        cout << "Edge already exists" << endl;
                        return;
                    }
                }
                vec[i].push_back(ter);
                input = true;
            }
        }
        if (input == false) {
            vector<int> f = {ver, ter};
            vec.push_back(f);
        }

        input = false;
        for (int i = 0; i < size(vec); i++) {
            if (vec[i][0] == ter) {
                for (int j = 1; j < size(vec[i]); j++) {
                    if (vec[i][j] == ver) {
                        cout << "Edge already exists" << endl;
                        return;
                    }
                }
                vec[i].push_back(ver);
                input = true;
            }
        }
        if (input == false) {
            vector<int> f = {ter, ver};
            vec.push_back(f);
        }
    }

    void bfs() {
        unordered_map<int, int> m;
        for (int i = 0; i < size(vec); i++) {
            m[vec[i][0]] = i;
        }
        queue<int> q;
        vector<bool> visited;

        for (int i = 0; i < size(vec); i++) {
            visited.push_back(false);
        }
        q.push(vec[0][0]);
        visited[0] = true;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            cout << f << ' ';
            int i = m[f];

            for (int j = 1; j < size(vec[i]); j++) {
                if (visited[m[vec[i][j]]] == false) {
                    visited[m[vec[i][j]]] = true;
                    q.push(vec[i][j]);
                }
            }
        }
    }
};

int main() {
    cout << "initializing the graph" << endl;
    graph g(54);
    g.insert({54, 66});
    g.insert({54, 45});
    g.insert({66, 87});
    g.insert({66, 63});
    g.insert({45, 39});
    g.insert({45, 56});
    g.insert({45, 61});
    g.insert({61, 7});
    cout << "printing the graph using bfs" << endl;

    g.bfs();
    return 0;
}

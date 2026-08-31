#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

struct element {
    int node;
    int distance;
    int previous;
};

int bfs(int root) {
    queue<element> q;
    q.push({1, 0, 1});
    while (! q.empty()) {
        element current = q.front();
        q.pop();

        if (current.node == root && current.distance != 0) {
            return current.distance;
        }
        if (visited.at(current.node)) {
            continue;
        }
        visited.at(current.node) = true;

        for (int i = 0; i < adjList.at(current.node).size(); i++) {
            if (adjList.at(current.node).at(i) == current.previous) continue;
            q.push({adjList.at(current.node).at(i), current.distance + 1, current.node});
        }
    }
    return INT_MAX;
}


int main() {
    int n; int m;
    cin >> n; cin >> m;

    adjList.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a; int b;
        cin >> a; cin >> b;
        adjList.at(a).push_back(b);
        adjList.at(b).push_back(a);
    }

    int out = INT_MAX;
    for (int i = 1; i <= n; i++) {
        visited.resize(n + 1);
        out = min(out, bfs(i));
    }
    cout << out;
    return 0;
}
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> dist;

struct element {
    int node;
    int previous;
};

int bfs(int root) {
    queue<element> q;
    q.push({root, root});
    dist.at(root) = -1;

    int ans = INT_MAX;

    while (! q.empty()) {
        element current = q.front();
        q.pop();

        if (visited.at(current.node)) {
            int cycleLength = 1 + dist.at(current.node) + dist.at(current.previous);
            ans = min(ans, cycleLength);
            continue;
        }
        visited.at(current.node) = true;

        dist.at(current.node) = 1 + dist.at(current.previous);

        for (int i = 0; i < adjList.at(current.node).size(); i++) {
            if (adjList.at(current.node).at(i) == current.previous) continue;
            q.push({adjList.at(current.node).at(i), current.node});
        }
    }
    return ans;
}


int main() {
    int n; int m;
    cin >> n; cin >> m;

    adjList.resize(n + 1);
    visited.resize(n + 1);
    dist.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a; int b;
        cin >> a; cin >> b;
        adjList.at(a).push_back(b);
        adjList.at(b).push_back(a);
    }

    int out = INT_MAX;
    for (int i = 1; i <= n; i++) {
        fill(visited.begin(), visited.end(), false);
        fill(dist.begin(), dist.end(), false);

        int foo = bfs(i);
        out = min(out, foo);
    }
    cout << (out == INT_MAX ? -1 : out);
    return 0;
}
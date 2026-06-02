#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;


vector<vector<int>> adjacencyList;
vector<bool> visited;

vector<int> out;

void dfs(int idx, int depth) {
    if (visited.at(idx)) {
        return;
    }
    visited.at(idx) = true;
    for (int c : adjacencyList.at(idx)) {
        dfs(c, depth + 1);
    }
    out.at(idx) = depth % 2 + 1;
}

int main() {
    int n; cin >> n;
    int m; cin >> m;

    adjacencyList.resize(n + 1);
    visited.resize(n + 1);
    out.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a; int b; cin >> a; cin >> b;
        adjacencyList.at(a).push_back(b);
        adjacencyList.at(b).push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 0);
        cout << out.at(i) << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> adjacencyList;
vector<bool> visited;
vector<bool> deleted;

int dfs(int idx) {
    if (visited.at(idx)) {
        return 0;
    }
    visited.at(idx) = true;
    int count = 1;
    for (int c : adjacencyList.at(idx)) {
        count += dfs(c);
    }
    return count;
}

int main() {
    int n; int m;
    cin >> n; cin >> m;
    adjacencyList.resize(n + 1);
    visited.resize(n + 1);
    deleted.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a; int b; cin >> a; cin >> b;
        adjacencyList.at(a).push_back(b);
        adjacencyList.at(b).push_back(a);
    }

    for (int i = 0; i < n - 1; i++) {
        int toRemove; cin >> toRemove;
        deleted.at(toRemove) = true;

        int childNodesCount = 0;
        for (int c : adjacencyList.at(toRemove)) {
            if (! deleted.at(c)) {
                childNodesCount++;
            }
        }
        if (childNodesCount <= 1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
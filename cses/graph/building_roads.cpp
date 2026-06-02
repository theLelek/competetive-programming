#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> adjacencyList;
vector<int> visited;

void dfs(int idx) {
    if (visited.at(idx)) {
        return;
    }
    visited.at(idx) = true;
    for (int child : adjacencyList.at(idx)) {
        dfs(child);
    }
}

int main() {
    int n; int m;
    cin >> n;
    cin >> m;

    adjacencyList.resize(n, vector<int>(0));
    visited.resize(n);

    for (int i = 0; i < m; i++) {
        int a; int b;
        cin >> a; cin >> b;
        adjacencyList.at(a - 1).push_back(b - 1);
        adjacencyList.at(b - 1).push_back(a - 1);
    }

    int count = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < adjacencyList.size(); i++) {
        if (! visited.at(i) && i != 0) {
            count++;
//            cout << i << " " << i + 1 << "\n";
            ans.push_back({i, i + 1});
        }
        dfs(i);
    }
    cout << count << "\n";
    for (vector<int> foo : ans) {
        cout << foo.at(0) << " " << foo.at(1) << "\n";
    }
    return 0;
}
#include <iostream>
#include <limits.h>
#include <vector>


using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> dist;

int getGirth(int current, int previous) {
    if (visited.at(current) && current != previous) {
        return dist.at(previous) - dist.at(current) + 1;
    }
    visited.at(current) = true;
    dist.at(current) = dist.at(previous) + 1;

    int out = INT_MAX;
    for (int i = 0; i < adjList.at(current).size(); i++) {
        if (adjList.at(current).at(i) == previous || adjList.at(current).at(i) == current) continue;

        out = min(out, getGirth(adjList.at(current).at(i), current));
    }
    visited.at(current) = false;
    dist.at(current) = 0;
    return out;
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

    dist.at(1) = -1;
    cout << getGirth(1, 1);

    return 0;
}
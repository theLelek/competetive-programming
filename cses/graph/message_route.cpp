#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n; int m;
vector<vector<int>> adjacencyList;
vector<int> cameFrom;
vector<bool> visited;

void pushAllChildreen(queue<pair<int, int>> &nodes, int currentNode, int depth) {
    for (int i = 0; i < adjacencyList.at(currentNode).size(); i++) {
        if (visited.at(adjacencyList.at(currentNode).at(i))) continue;
        visited.at(adjacencyList.at(currentNode).at(i)) = true;

        nodes.push({adjacencyList.at(currentNode).at(i), depth + 1});
        cameFrom.at(adjacencyList.at(currentNode).at(i)) = currentNode;
    }
}

pair<int, int> bfs() {
    queue<pair<int, int>> nodes;
    visited.resize(n + 1);
    visited.at(1) = true;
    cameFrom.resize(n + 1, -1);

    pushAllChildreen(nodes, 1, 0);

    while (nodes.size() != 0) {
        pair<int, int> current = nodes.front();
        nodes.pop();

        if (current.first == n) {
            return {current.first, current.second + 1};
        }
        pushAllChildreen(nodes, current.first, current.second);
    }
    return {-1 , -1};
}

void printResult(int current) {
    if (current == -1) {
        return;
    }
    printResult(cameFrom.at(current));
    cout << current << " ";
}

int main() {
    cin >> n; cin >> m;
    adjacencyList.resize(n + 1);

    for (int i = 0; i< m; i++) {
        int a; int b;
        cin >> a; cin >> b;
        adjacencyList.at(a).push_back(b);
        adjacencyList.at(b).push_back(a);
    }
    pair<int, int> result = bfs();


    if (result.first == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << result.second << "\n";
        printResult(result.first);
    }

    return 0;
}
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

struct Node {

    vector<int> children;
    vector<int> weights;
};

vector<long long> shortestWay;
vector<Node> adjacencyList;

void dijkstra() {
    shortestWay.at(1) = 1;
    priority_queue<pair<long long, int>> pq; // weights, node
    pq.push({0, 1});
    while (! pq.empty()) {
        long long weight = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (shortestWay.at(node) <= weight) {
            continue;
        }
        shortestWay.at(node) = weight;

        for (int i = 0; i < adjacencyList.at(node).children.size(); i++) {
            long long currentWeight = adjacencyList.at(node).weights.at(i) + weight;
            pq.push({-currentWeight, adjacencyList.at(node).children.at(i)});
        }
    }
}

int main() {
    int n; int m;
    cin >> n; cin >> m;

    adjacencyList.resize(n + 1);
    shortestWay.resize(n + 1, LONG_LONG_MAX);


    for (int i = 0; i < m; i++) {
        int a; int b; int c;
        cin >> a; cin >> b; cin >> c;

        adjacencyList.at(a).children.push_back(b);
        adjacencyList.at(a).weights.push_back(c);
    }



    dijkstra();

    for (int i = 1; i < shortestWay.size(); i++) {
        cout << shortestWay.at(i) << " ";
    }

    return 0;
}

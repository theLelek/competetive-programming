#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> adjacencyList;
vector<bool> visited;

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
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n; cin >> n;
    vector<vector<int>> numbers;
    visited.resize(n + 1);
    numbers.push_back(vector<int>());
    for (int i = 1; i <= n; i++) {
        int x; int y; int p;
        cin >> x; cin >> y; cin >> p;
        numbers.push_back(vector<int>());
        numbers.at(i).push_back(x);
        numbers.at(i).push_back(y);
        numbers.at(i).push_back(p);
    }
    adjacencyList.resize(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        int x1 = numbers.at(i).at(0);
        int y1 = numbers.at(i).at(1);
        int p1 = numbers.at(i).at(2);
        for (int j = i + 1; j <= n; j++) {
            int x2 = numbers.at(j).at(0);
            int y2 = numbers.at(j).at(1);
            int p2 = numbers.at(j).at(2);

            int distanceX = x1 - x2;
            int distanceY = y1 - y2;
            int distance = distanceX * distanceX + distanceY * distanceY;
            if (p1*p1 >= distance) {
                adjacencyList.at(i).push_back(j);
            }
            if (p2*p2 >= distance) {
                adjacencyList.at(j).push_back(i);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
        fill(visited.begin(), visited.end(), false);
    }
    cout << ans;
    return 0;
}
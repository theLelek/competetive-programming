#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct element {
    int y;
    int x;
    int distance;
};

int h; int w;
vector<vector<char>> grid;

deque<element> q = {};
vector<vector<bool>> visited;

void addQueueElement(int fromY, int fromX, int toY, int toX, int distance) {
    if (toY >= 0 && toY < h && toX >= 0 && toX < w && ! visited.at(toY).at(toX)) {
        if (grid.at(toY).at(toX) == '.') return;

        visited.at(toY).at(toX) = true;
        if (grid.at(fromY).at(fromX) == grid.at(toY).at(toX)) {
            q.push_front({toY, toX, distance});
        } else {
            q.push_back({toY, toX, distance + 1});
        }
    }
}

int bfs01() {
    visited.resize(h, vector<bool>(w, false));
    visited.at(0).at(0) = true;
    q.push_back({0, 0, 1});
    int out = -1;
    while (! q.empty()) {
        element current = q.front();
        out = max(out, current.distance);
        q.pop_front();

        addQueueElement(current.y, current.x, current.y - 1, current.x, current.distance);
        addQueueElement(current.y, current.x, current.y + 1, current.x, current.distance);
        addQueueElement(current.y, current.x, current.y, current.x + 1, current.distance);
        addQueueElement(current.y, current.x, current.y, current.x - 1, current.distance);
    }
    return out;
}

int main() {
    cin >> h; cin >> w;
    grid.resize(h, vector<char>(w));

    for (int i = 0; i < h; i++) {
        string line; cin >> line;
        for (int j = 0; j < w; j++) {
            grid.at(i).at(j) = line.at(j);
        }
    }
    cout << bfs01();
    return 0;
}
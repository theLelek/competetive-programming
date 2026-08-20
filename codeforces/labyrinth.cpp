#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; int m;
int r; int c;
int x; int y;
vector<vector<char>> matrix;

struct element {
    int rowNode;
    int columnNode;
    int leftSteps;
    int rightSteps;
};

pair<bool, element> isNodeReachable(element from, int toRow, int toColumn) {
    if (! (toRow <= n && toRow >= 1 && toColumn <= m && toColumn >= 1)) {
        return {false, element{}};
    }
    if (matrix.at(toRow).at(toColumn) != '.') {
        return {false, element{}};
    }

    int rightDistance = max(0, toColumn - from.columnNode);
    if (rightDistance + from.rightSteps > y) {
        return {false, element{}};
    }
    int leftDistance = max(0, from.columnNode - toColumn);
    if (leftDistance + from.leftSteps > x) {
        return {false, element{}};
    }
    return {true, element{toRow, toColumn, from.leftSteps + leftDistance, from.rightSteps + rightDistance}};
}

int getNumberOfReachableCells() {
    deque<element> dq = {element{r, c, 0, 0}};
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    visited.at(r).at(c) = true;
    int numberOfReachableCells = 1;
    while (! dq.empty()) {
        element current = dq.front();
        dq.pop_front();

        // right
        pair<bool, element> rightResult = isNodeReachable(current, current.rowNode, current.columnNode + 1);
        if (rightResult.first && ! visited.at(current.rowNode).at(current.columnNode + 1)) {
            visited.at(current.rowNode).at(current.columnNode + 1) = true;
            numberOfReachableCells++;
            dq.push_back(rightResult.second);
        }
        // left
        pair<bool, element> leftResult = isNodeReachable(current, current.rowNode, current.columnNode - 1);
        if (leftResult.first && ! visited.at(current.rowNode).at(current.columnNode - 1)) {
            visited.at(current.rowNode).at(current.columnNode - 1) = true;
            numberOfReachableCells++;
            dq.push_back(leftResult.second);
        }
        // up
        pair<bool, element> upResult = isNodeReachable(current, current.rowNode - 1, current.columnNode);
        if (upResult.first && ! visited.at(current.rowNode - 1).at(current.columnNode)) {
            visited.at(current.rowNode - 1).at(current.columnNode) = true;
            numberOfReachableCells++;
            dq.push_back(upResult.second);
        }
        // down
        pair<bool, element> downResult = isNodeReachable(current, current.rowNode + 1, current.columnNode);
        if (downResult.first && ! visited.at(current.rowNode + 1).at(current.columnNode)) {
            visited.at(current.rowNode + 1).at(current.columnNode) = true;
            numberOfReachableCells++;
            dq.push_back(downResult.second);
        }
    }
    return numberOfReachableCells;
}

int main() {
    // 1 based
    cin >> n; cin >> m;
    cin >> r; cin >> c;
    cin >> x; cin >> y;

    matrix.resize(n + 1, vector<char>(m + 1));


    for (int i = 1; i <= n; i++) {
        string line; cin >> line;
        for (int j = 1; j <= m; j++) {
            matrix.at(i).at(j) = line.at(j - 1);
        }
    }

    cout << getNumberOfReachableCells() << "\n";
    return 0;
}

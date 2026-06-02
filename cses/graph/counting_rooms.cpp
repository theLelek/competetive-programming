#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> matrix;
vector<vector<bool>> visited;
int n;
int m;

int floodFill(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m) {
        return 0;
    }
    if (matrix.at(y).at(x) == '#') {
        return 0;
    }
    if (visited.at(y).at(x)) {
        return 0;
    }
    visited.at(y).at(x) = true;
    floodFill(y + 1, x);
    floodFill(y - 1, x);
    floodFill(y, x + 1);
    floodFill(y, x - 1);
    return 1;
}

int main() {
    cin >> n;
    cin >> m;
    visited.resize(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        matrix.push_back(vector<char>());
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            matrix.at(i).push_back(c);
        }
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += floodFill(i, j);
        }
    }
    cout << ans;
    return 0;
}

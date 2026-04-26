#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<string> grid;

int solveRecursively(int x, int y) {
    if (x == grid.size() || y == grid.size() || grid.at(y).at(x) == '*') {
        return 0;
    }
    if (x == grid.size() - 1 && y == grid.size() - 1) {
        return 1;
    }
    if (dp.at(y).at(x) != -1) {
        return dp.at(y).at(x);
    }
    int ans = solveRecursively(x + 1, y) + solveRecursively(x, y + 1);
    ans %= 1000000007;
    dp.at(y).at(x) = ans;
    return ans;
}

int solveIteratively() {
    dp.at(grid.size() - 1).at(grid.size() - 1) = 1;
    for (int i = grid.size() - 1; i >= 0; i--) {
        for (int j = grid.size() - 1; j >= 0; j--) {
            if (grid.at(i).at(j) == '*') {
                dp.at(i).at(j) = 0;
                continue;
            }
            if (i == grid.size() - 1 && j == grid.size() - 1) {
                continue;
            }
            int ans = 0;
            if (i < grid.size() - 1) {
                ans += dp.at(i + 1).at(j);
                ans %= 1000000007;
            }
            if (j < grid.size() - 1) {
                ans += dp.at(i).at(j + 1);
                ans %= 1000000007;
            }
            dp.at(i).at(j) = ans;
        }
    }
    return dp.at(0).at(0);
}

int main() {
    int n; cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid.at(i);
    }

    dp.assign(n, vector<int>(n, -1));
    cout << solveRecursively(0, 0);

    return 0;
}
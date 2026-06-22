#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n;
vector<int> numbers;

vector<vector<int>> dp;

int solveRecursively1(int idx, int prevValue) {
    if (idx == n) {
        return 0;
    }
    if (numbers.at(idx) <= prevValue) {
        return 0;
    }

    if (dp.at(idx).at(prevValue) != -1) {
        return dp.at(idx).at(prevValue);
    }

    int ans = INT_MIN;
    for (int i = idx; i < n; i++) {
        ans = max(ans, 1 + solveRecursively1(i + 1, numbers.at(i)));
    }
    dp.at(idx).at(prevValue) = ans;
    return ans;
}

int main() {
    cin >> n;
    int highest = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        highest = max(c, highest);
        numbers.push_back(c);
    }
    dp.resize(n + 5, vector<int>(highest + 5, -1));
    cout << solveRecursively1(0, 0);
    return 0;
}
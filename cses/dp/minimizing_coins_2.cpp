#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> numbers;
vector<int> dp;

int solveRecursively(int neededCoins) {
    if (neededCoins == 0) {
        return 0;
    }
    if (neededCoins < 0) {
        return INT_MAX / 2;
    }
    if (dp.at(neededCoins) != -1) {
        return dp.at(neededCoins);
    }

    int best = INT_MAX / 2;
    for (int i = 0; i < numbers.size(); i++) {
        best = min(best, 1 + solveRecursively(neededCoins - numbers.at(i)));
    }
    dp.at(neededCoins) = best;
    return best;
}

int solveIteratively(int x) {
    dp.at(0) = 0;
    for (int i = 1; i <= x; i++) {
        int best = INT_MAX / 2;
        for (int j = 0; j < numbers.size(); j++) {
            if (i - numbers.at(j) < 0) continue;
            best = min(best, 1 + dp.at(i - numbers.at(j)));
        }
        dp.at(i) = best;
    }
    return dp.at(x);
}

int main() {
    int n; int x; cin >> n; cin >> x;
    dp.resize(x + 5, -1);
    for (int i = 0; i < n ; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }
    int ans = solveIteratively(x);
    if (ans == INT_MAX / 2) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}
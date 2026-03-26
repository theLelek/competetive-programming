#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> coins;
vector<int> dp;


int solveRecursively(int currentTargetSum) {
    if (currentTargetSum == 0) {
        return 0;
    }
    if (currentTargetSum < 0) {
        return INT_MAX;
    }
    if (dp.at(currentTargetSum) != INT_MAX) {
        return dp.at(currentTargetSum);
    }

    int foo = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        //        currentCoins.push_back(coins[i]);
        int current = solveRecursively(currentTargetSum - coins[i]);
        foo = min(foo, current);
        //        currentCoins.pop_back();
    }
    dp.at(currentTargetSum) = foo; // TODO index is wrong (will be overriden)
    if (foo == INT_MAX) {
        return INT_MAX;
    } else {
        return 1 + foo;
    }
}

int main() {
    int n, x; cin >> n; cin >> x;
    for (int i = 0; i < n; i++) {
        int current; cin >> current;
        coins.push_back(current);
    }
    vector<int> currentCoins(0);
    dp.resize(x + 5, INT_MAX);

    int out =  solveRecursively(x);

    if (out == INT_MAX) {
        cout << -1;
    } else {
        cout << out;
    }
    return 0;
}
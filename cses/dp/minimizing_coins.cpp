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
        return INT_MAX / 2;
    }
    if (dp.at(currentTargetSum) != -1) {
        return dp.at(currentTargetSum);
    }

    int foo = INT_MAX / 2;
    for (int i = 0; i < coins.size(); i++) {
        int current = 1 + solveRecursively(currentTargetSum - coins[i]);
        foo = min(foo, current);
    }
    dp.at(currentTargetSum) = foo;
    return foo;
}

int main() {
    int n, x; cin >> n; cin >> x;
    for (int i = 0; i < n; i++) {
        int current; cin >> current;
        coins.push_back(current);
    }
    dp.resize(x + 5, -1);
    int out =  solveRecursively(x);

    if (out == INT_MAX / 2) {
        cout << -1;
    } else {
        cout << out;
    }
    return 0;
}
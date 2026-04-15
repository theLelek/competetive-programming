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

int solveIteratively(int targetSum) {
    dp.at(0) = 0;
    for (int i = 1; i <= targetSum; i++) {
        // needed value = i
        int best = targetSum + 1;
        for (int coin : coins) {
            if (i - coin < 0) {
                continue;
            }
            int current = 1 + dp.at(i - coin);
            best = min(best, current);
        }
        dp.at(i) = best;
    }
    return dp.at(targetSum) > targetSum ? -1 : dp.at(targetSum);
}

int main() {
    int n, x; cin >> n; cin >> x;
    for (int i = 0; i < n; i++) {
        int current; cin >> current;
        coins.push_back(current);
    }
    dp.resize(x + 5, x + 1);
    int out = solveIteratively(x);
    cout << out;
    return 0;
    }

/* remember for future:
 * try to avoid INT_MAX overflows happen
 * when chaning from INT_MAX to INT_MAX / 2 also change the if condition in the main function
*/
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> dp;

int solveRecursively(int n) {
    if (n < 0) {
        return INT_MAX / 2;
    }
    if (n == 0) {
        return 0;
    }
    if (dp.at(n) != -1) {
        return dp.at(n);
    }
    int best = INT_MAX / 2;
    int digits = n;
    while (digits > 0) {
        int digit = digits % 10;
        digits /= 10;
        if (digit == 0) {
            continue;
        }
        best = min(1 + solveRecursively(n - digit), best);
    }
    dp.at(n) = best;
    return best;
}

int solveIteratively(int n) {
    dp.at(0) = 0;
    for (int i = 1; i <= n; i++) {
        int digits = i;
        int best = INT_MAX;
        while (digits > 0) {
            int digit = digits % 10;
            digits /= 10;
            if (digit == 0) {
                continue;
            }
            best = min(best, 1 + dp.at(i - digit));
        }
        dp.at(i) = best;
    }
    return dp.at(n);
}

int main() {
    int n; cin >> n;
    dp.resize(n + 5, 0);
    cout << solveIteratively(n);
    return 0;
}
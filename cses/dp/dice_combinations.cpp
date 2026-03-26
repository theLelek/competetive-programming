#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int getNumberOfSumsN(int n) {
    if (dp[n] != -1) {
        return dp[n];
    }
    if (n == 0) {
        return 1;
    }
    int amount = 0;
    for (int i = 1; i <= 6 && i <= n; i++) {
        int foo = getNumberOfSumsN(n - i) % 1000000007;
        dp[n - i] = foo;
        amount += foo;
        amount = amount % 1000000007;
    }
    return amount;
}

int solveIteratively(int n) {
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        long long foo = 0;
        for (int j = 1; i - j >= 0 && j <= 6; j++) {
            foo += dp[i - j] % 1000000007;
        }
        dp[i] = foo % 1000000007;
    }
    return dp[n];
}

int main() {
    int n; cin >> n;
    dp.resize(n + 5, -1);
//    cout << getNumberOfSumsN(n);
    cout << solveIteratively(n);
    return 0;
}
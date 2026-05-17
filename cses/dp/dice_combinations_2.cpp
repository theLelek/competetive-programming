#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int solveRecursively(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    if (dp.at(n) != -1) {
        return dp.at(n);
    }
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += solveRecursively(n - i);
        ans %= 1000000007;
    }
    dp.at(n) = ans;
    return ans;
}

int solveIteratively(int n) {
    dp.at(0) = 1;
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= 6 && i - j >= 0; j++) {
            ans += dp.at(i - j);
            ans %= 1000000007;
        }
        dp.at(i) = ans;
    }
    return dp.at(n);
}

int main() {
    int n; cin >> n;
    dp.resize(n + 5, -1);
    cout << solveIteratively(n);

    return 0;
}
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;


vector<int> prices;
vector<int> pages;
vector<int> dp;

// int solveRecursively(int idx, int money) {
//     if (money < 0) {
//         return INT_MIN / 2;
//     }
//     if (idx == prices.size()) {
//         return 0;
//     }
//     if (dp.at(idx).at(money) != -1) {
//         return dp.at(idx).at(money);
//     }
//
//     int ans = solveRecursively(idx + 1, money);
//     for (int i = idx; i < prices.size(); i++) {
//         int foo = solveRecursively(i + 1, money - prices.at(i));
//         ans = max(ans, pages.at(i) + foo);
//     }
//     dp.at(idx).at(money) = ans;
//     return ans;
// }

int solveIteratively(int n, int x) {
    // max number of pages that can be made with money
    dp.at(0) = 0;
    for (int i = 1; i <= x; i++) {
        // from 0 - j
        int ans = dp.at(i - 1);
        for (int j = 0; j < n; j++) {
            int c = INT_MIN;
            if (i - prices.at(j) >= 0) {
                c = dp.at(i - prices.at(j)) + pages.at(j);
            }
            ans = max(ans, c);
        }
        dp.at(i) = ans;
    }
    return dp.at(x);
}

int solveIteratively2(int n, int x) {
    dp.at(0) = 0;
    for (int i = 0; i < n; i++) {
        // for price -> max number of pages
        vector<int> dp2(x + 5, 0);
        // numbers
        int ans = INT_MIN;
        for (int j = 1; j <= x; j++) {
            int c = INT_MIN;
            if (j - prices.at(i) >= 0) {
                c = dp2.at(j - prices.at(i)) + pages.at(i);
            }
        }
        dp.at()
    }
}

int main() {
    int n; int x; cin >> n; cin >> x;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        prices.push_back(c);
    }
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        pages.push_back(c);
    }
    dp.resize(x + 5, -1);
    cout << solveIteratively2(n, x);;
    return 0;
}
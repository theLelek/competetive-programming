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
    // get max number of pages with pages 0 - 1/2/...
    dp.at(0) = 0;
    // max number of pages with budget x with coins 0 - i
    for (int i = 0; i < n; i++) {
        cout << "";
        // numbers
        for (int j = x; j >= prices.at(i); j--) {
            int c = max(0, dp.at(j));
            if (j - prices.at(i) >= 0) {
                c = max(c, dp.at(j - prices.at(i)) + pages.at(i));
            }
            dp.at(j) = c;
        }
    }
    return dp.at(x);
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
    dp.resize(x + 5, 0);
    cout << solveIteratively(n, x);;
    return 0;
}
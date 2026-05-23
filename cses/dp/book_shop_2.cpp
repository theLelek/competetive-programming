#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;


vector<int> prices;
vector<int> pages;
vector<vector<int>> dp;

int solveRecursively(int idx, int money) {
    if (money < 0) {
        return INT_MIN / 2;
    }
    if (idx == prices.size()) {
        return 0;
    }
    if (dp.at(idx).at(money) != -1) {
        return dp.at(idx).at(money);
    }

    int ans = solveRecursively(idx + 1, money);
    for (int i = idx; i < prices.size(); i++) {
        int foo = solveRecursively(i + 1, money - prices.at(i));
        ans = max(ans, pages.at(i) + foo);
    }
    dp.at(idx).at(money) = ans;
    return ans;
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
    dp.resize(n + 5, vector<int>(x + 5, -1));
    cout << solveRecursively(0, x);;
    return 0;
}
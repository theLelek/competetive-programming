#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;


vector<int> prices;
vector<int> pages;

int solveRecursively(int idx, int money) {
    if (money < 0) {
        return INT_MIN;
    }
    if (idx == prices.size()) {
        return 0;
    }

    int ans = INT_MIN;
    for (int i = idx; i < prices.size(); i++) {
        int foo = solveRecursively(i, money - prices.at(i));


        ans = max(ans, pages.at(i) + foo);
    }
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
    cout << solveRecursively(x);
    return 0;
}
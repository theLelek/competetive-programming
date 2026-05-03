#include <iostream>
#include <vector>

using namespace std;

vector<int> prices;
vector<int> pages;
int maxPrice;
vector<vector<int>> dp;

int solveRecursively(int currentPrice, int idx) {
    if (currentPrice > maxPrice) {
        return 0;
    }
    if (idx == prices.size()) {
        return 0;
    }
    if (dp.at(idx).at(currentPrice) != -1) {
        return dp.at(idx).at(currentPrice);
    }
    int best1 = pages.at(idx) + solveRecursively(currentPrice + prices.at(idx), idx + 1);
    int best2 = solveRecursively(currentPrice, idx + 1);
    int best = max(best1, best2);
    dp.at(idx).at(currentPrice) = best;
    return best;
}

int main() {
    int n; cin >> n; int x; cin >> x;
    maxPrice = x;
    dp.resize(n + 5, vector<int>(x + 5, -1));
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        prices.push_back(c);
    }
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        pages.push_back(c);
    }

    cout << solveRecursively(0, 0);
    return 0;
}
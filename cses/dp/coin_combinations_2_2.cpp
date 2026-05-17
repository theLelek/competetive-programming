#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> numbers;
vector<vector<int>> dp;

int solveRecursively(int idx, int targetSum) {
    if (targetSum == 0) {
        return 1;
    }
    if (targetSum < 0) {
        return 0;
    }
    if (dp.at(idx).at(targetSum) != -1) {
        return dp.at(idx).at(targetSum);
    }

    int ans = 0;
    for (int i = idx; i < numbers.size(); i++) {
        ans += solveRecursively(i, targetSum - numbers.at(i));
        ans %= 1000000007;
    }
    dp.at(idx).at(targetSum) = ans;
    return ans;
}

int solveIteratively(int x) {
    for (int i = 0; i < numbers.size(); i++) {
        int best = INT_MAX;
        for (int j = 1; j <= x; j++) {
            if (i - j >= 0) {


            }
            int ans1 = dp.at(i).at(j)


        }
    }
}

int main() {
    int n, x; cin >> n; cin >> x;
    dp.resize(n + 5, vector<int>(x + 5, 0)); // change for recursive
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }
    int out = solveIteratively(x);
    cout << out;
    return 0;
}

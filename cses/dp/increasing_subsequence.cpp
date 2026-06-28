#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n;
vector<int> numbers;

vector<vector<int>> dp;

int solveRecursively(int idx, int prevIndex) {
    if (idx == n) {
        return 0;
    }
    if (numbers.at(idx) <= numbers.at(prevIndex) && prevIndex != -1) {
        return INT_MIN / 2;
    }
    if (prevIndex != -1 && dp.at(idx).at(numbers.at(prevIndex)) != -1) {
        return dp.at(idx).at(numbers.at(prevIndex));
    }

    int foo1 = solveRecursively(idx + 1, prevIndex);
    int foo2 = solveRecursively(idx + 1, idx);
    int ans = max(foo1, foo2);
    dp.at(idx).at(numbers.at(prevIndex)) = ans;
    return ans;
}

int main() {
    cin >> n;
    int highest = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        highest = max(c, highest);
        numbers.push_back(c);
    }
    dp.resize(n + 5, vector<int>(highest + 5, -1));
    cout << solveRecursively(0, -1);
    return 0;
}
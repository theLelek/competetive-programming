#include <vector>
#include <iostream>

using namespace std;

vector<int> numbers;
int m;
vector<vector<int>> dp;

int solveRecursively(int idx, int prevValue) {
    if (prevValue == m + 2) prevValue = numbers.at(idx - 1);
    if (idx == numbers.size()) {
        return 1;
    }
    if (dp.at(idx).at(prevValue) != -1) {
        return dp.at(idx).at(prevValue);
    }
    int ans = 0;

    if (numbers.at(idx) != 0) {
        if (abs(prevValue - numbers.at(idx)) > 1) {
            return 0;
        }
        ans += solveRecursively(idx + 1, m + 2); // todo
        ans %= 1000000007;
//        dp.at(idx).at(numbers.at(idx)) = ans;
        dp.at(idx).at(prevValue) = ans;
        return ans;
    }

    for (int i = 1; i <= m; i++) {
        if (abs(prevValue - i) <= 1 || idx == 0) {
            ans += solveRecursively(idx + 1, i);
            ans %= 1000000007;
        }
    }
    dp.at(idx).at(prevValue) = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        numbers.push_back(c);
    }
    dp.resize(n + 5, vector<int>(m + 5, -1));
    cout << solveRecursively(0, numbers.at(0));
    return 0;
}
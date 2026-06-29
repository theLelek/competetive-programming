#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> numbers;

vector<int> dp;

// int solveRecursively(int idx, int prevIndex) {
//     if (idx == n) {
//         return 0;
//     }
//     if (prevIndex != -1 && dp.at(idx).at(prevIndex) != -1) {
//         return dp.at(idx).at(prevIndex);
//     }
//
//     int foo1 = solveRecursively(idx + 1, prevIndex);
//     int foo2 = INT_MIN;
//     if (prevIndex == -1 || numbers.at(idx) > numbers.at(prevIndex)) {
//         foo2 = 1 + solveRecursively(idx + 1, idx);
//     }
//     int ans = max(foo1, foo2);
//     if (prevIndex != -1) {
//         dp.at(idx).at(prevIndex) = ans;
//     }
//     return ans;
// }

int solveIteratively() {
    dp.resize(n + 5, 1);
    int out = 1;
    for (int i = 1; i < n; i++) {
        // idx
        for (int j = 0; j < i; j++) {
            // prev idx
            int foo = 1;
            if (numbers.at(i) > numbers.at(j)) {
                foo = 1 + dp.at(j);
            }

            dp.at(i) = max(dp.at(i), foo);
            out = max(out, dp.at(i));
        }
    }
    return out;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }
    cout << solveIteratively();
    return 0;
}
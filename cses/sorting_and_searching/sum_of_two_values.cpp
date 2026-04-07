#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; long long x; cin >> n; cin >> x;
    vector<vector<long long>> indexed;
    for (int i = 0; i < n; i++) {
        long long c; cin >> c;
        indexed.push_back({c, i});
    }
    sort(indexed.begin(), indexed.end());

    int l = 0;
    int r = n - 1;
    while (l < r) {
        int currentSum = indexed.at(l).at(0) + indexed.at(r).at(0);

        if (currentSum == x) {
            cout << indexed.at(l).at(1) + 1 << " " << indexed.at(r).at(1) + 1 << "\n";
            return 0;
        } else if (currentSum > x) {
            r--;
        } else {
            l++;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
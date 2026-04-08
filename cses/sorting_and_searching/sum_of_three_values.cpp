#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; int x; cin >> n; cin >> x;
    vector<vector<int>> indexed;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        indexed.push_back({c, i});
    }
    sort(indexed.begin(), indexed.end());

    for (int i = 0; i < indexed.size(); i++) {
        int l = 0;
        int r = indexed.size() - 1;
        while (l < r) {
            if (l == i) {
                l++;
                continue;
            }
            if (r == i) {
                r--;
                continue;
            }
            int currentSum = indexed.at(l).at(0) + indexed.at(r).at(0) + indexed.at(i).at(0);
            if (currentSum == x) {
                cout << indexed.at(l).at(1) + 1<< " " << indexed.at(r).at(1) + 1 << " " << indexed.at(i).at(1) + 1;
                return 0;
            } else if (currentSum > x) {
                r--;
            } else if (currentSum < x) {
                l++;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
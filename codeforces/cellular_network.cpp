#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int lowerBound(vector<int> &numbers, int target) {
    int l = 0;
    int r = numbers.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (numbers.at(m) >= target) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int main() {
    int n; int m;
    cin >> n; cin >> m;

    vector<int> cities;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        cities.push_back(c);
    }
    vector<int> towers;
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        towers.push_back(c);
    }

    int out = INT_MIN;
    for (int i = 0; i < cities.size(); i++) {
        int idx = lowerBound(towers, cities.at(i));
        int current = INT_MAX;
        if (idx < towers.size()) {
            current = abs(cities.at(i) - towers.at(idx));
        }
        if (idx - 1 >= 0) {
            current = min(current, abs(cities.at(i) - towers.at(idx - 1)));
        }
        out = max(out, current);
    }

    cout << out;
    return 0;
}

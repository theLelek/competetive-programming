#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; int q; cin >> n; cin >> q;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<int>> prefixSum;

    for (int i = 0; i < n; i++) {
        prefixSum.push_back({});
        for (int j = 0; j < n; j++) {
            int c = (grid.at(i).at(j)) == '*' ? 1 : 0;
            if (i - 1 >= 0) {
                c += prefixSum.at(i - 1).at(j);
            }
            if (j - 1 >= 0) {
                c += prefixSum.at(i).at(j - 1);
            }
            if (j - 1 >= 0 && i - 1 >= 0) {
                c -= prefixSum.at(i - 1).at(j - 1);
            }
            prefixSum.at(i).push_back(c);
        }
    }

    while (q--) {
        // y_1, x_1, y_2, x_2
        int y1; cin >> y1; int x1; cin >> x1; int y2; cin >> y2; int x2; cin >> x2;
        y1--; y2--; x1--; x2--;
        int ans = prefixSum.at(y2).at(x2);

        if (x1 > 0) {
            ans -= prefixSum.at(y2).at(x1 - 1);
        }
        if (y1 > 0) {
            ans -= prefixSum.at(y1 - 1).at(x2);
        }
        if (y1 > 0 && x1 > 0) {
            ans += prefixSum.at(y1 - 1).at(x1 - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}

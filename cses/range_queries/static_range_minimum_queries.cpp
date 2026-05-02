#include <cmath>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
    int n; int q; cin >> n; cin >> q;
    vector<int> numbers;
    while (n--) {
        int c; cin >> c;
        numbers.push_back(c);
    }

    // preprocessing
    vector<vector<int>> sparseTable;
    for (int i = 0; pow(2, i) <= numbers.size(); i++) {
        sparseTable.push_back({});
        int powerOf2 = pow(2, i);
        int prevPowerOf2 = pow(2, i - 1);
        for (int j = 0; j + pow(2, i) - 1 < numbers.size(); j++) {
            if (i == 0) {
                sparseTable.at(i).push_back(numbers.at(j));
                continue;
            }
            int colum1 = j;
            int colum2 = j + prevPowerOf2;
            int m = min(sparseTable.at(i - 1).at(colum1), sparseTable.at(i - 1).at(colum2));
            sparseTable.at(i).push_back(m);
        }
    }

    // int answering
    while (q--) {
        int from; int to; cin >> from; cin >> to; from--; to--;

        int qLength = to - from + 1;
        int greatestPowerOf2 = (int) log2(qLength);
        int ans1 = sparseTable.at(greatestPowerOf2).at(from);
        int ans2 = sparseTable.at(greatestPowerOf2).at(to - pow(2, greatestPowerOf2) + 1);
        cout << min(ans1, ans2) << "\n";
    }

    return 0;
}


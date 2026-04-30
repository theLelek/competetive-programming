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
        sparseTable.push_back(vector<int>(numbers.size(), INT_MAX));
        int interval = pow(2, i);
        int priorInterval = interval / 2;
        for (int j = 0; j + pow(2, i) - 1 < numbers.size(); j++) {
            if (i == 0) {
                sparseTable.at(i).at(j) = numbers.at(j);
                continue;
            }
            int c = min(sparseTable.at(i - 1).at(j), sparseTable.at(i - 1).at(j + priorInterval));
            sparseTable.at(i).at(j) = (c);
        }
    }

    // answering queries
    // for minimum queries overlaps dont matter -> thus constant answering is possible
    // non overlapping answering takes log2(n)
    while (q--) {
        int from; cin >> from; int to; cin >> to; from--; to--;
        int queryLength = to - from + 1;
        int prevPowerOf2 = (int) log2(queryLength);

        int q1From = from;
        int q2From = to - pow(2, prevPowerOf2) + 1;
        cout << min(sparseTable.at(prevPowerOf2).at(q1From), sparseTable.at(prevPowerOf2).at(q2From)) << "\n";
    }


    return 0;
}
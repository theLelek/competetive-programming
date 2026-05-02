

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n; int x; cin >> x;
    vector<int> numbers;
    while (n--) {
        int c; cin >> c;
        numbers.push_back(c);
    }

    // building
    vector<vector<int>> sparseTable;
    for (int i = 0; pow(2, i) <= numbers.size(); i++) {
        sparseTable.push_back({});
        for (int j = 0; j + pow(2, i) - 1 < numbers.size(); j++) { // todo
            if (i == 0) {
                sparseTable.at(i).push_back(numbers.at(j));
                continue;
            }
            int colum1 = j;
            int colum2 = j + pow(2, i - 1);
            int m = min(sparseTable.at(i - 1).at(colum1), sparseTable.at(i - 1).at(colum2));
            sparseTable.at(i).push_back(m);
        }
    }

    // processing
    while (x--) {
        int from; int to; cin >> from; cin >> to; from--; to--;

        int qLength = to - from + 1;
        int greatedPowerOf2 = (int) log2(qLength);

        int colum1 = from;
        int colum2 = to - pow(2, greatedPowerOf2) + 1;
        int ans = min(sparseTable.at(greatedPowerOf2).at(colum1), sparseTable.at(greatedPowerOf2).at(colum2));
        cout << ans << "\n";
    }
    return 0;
}


// todo building different than precessing?
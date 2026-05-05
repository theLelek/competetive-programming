#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; int q; cin >> n; cin >> q;
    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }


    vector<vector<long long>> sparseTable;
    // preprocessing
    for (int i = 0; pow(2, i) <= numbers.size(); i++) {
        sparseTable.push_back({});
        for (int j = 0; pow(2, i) + j - 1 < numbers.size(); j++) {
            if (i == 0) {
                sparseTable.at(i).push_back(numbers.at(j));
                continue;
            }

            int colum1 = j;
            int colum2 = j + pow(2, i - 1);
            sparseTable.at(i).push_back(sparseTable.at(i - 1).at(colum1) + sparseTable.at(i - 1).at(colum2));
        }
    }

    // answering
    for (int i = 0; i < q; i++) {
        int from; int to;
        cin >> from; cin >> to; from--; to--;
        int qLength = to - from + 1;
        long long ans = 0;
        long long idx = 0;
        while (qLength > 0) {
            int greatestPowerOf2 = (int) log2(qLength);

            ans += sparseTable.at(greatestPowerOf2).at(from + idx);

            idx += pow(2, greatestPowerOf2);
            qLength -= pow(2, greatestPowerOf2);
        }
        cout << ans << "\n";
    }
    return 0;
}
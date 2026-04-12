#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; int q; cin >> n; cin >> q;
    vector<int> numbers;
    while (n--) {
        int c; cin >> c;
        numbers.push_back(c);
    }
    vector<vector<int>> sparseTable = {};
    sparseTable.push_back({});
    for (int i = 0; i < numbers.size(); i++) {
        sparseTable[0].push_back(numbers[i]);
    }

    for (int i = 0; pow(i, 2) <= n; i++) {


    }


    return 0;
}
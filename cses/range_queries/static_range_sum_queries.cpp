#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; int q; cin >> n; cin >> q;
    vector<long long> numbers;
    while (n--) {
        long long c; cin >> c;
        numbers.push_back(c);
    }

    //build
    vector<long long> prefixSum = {0};
    for (int i = 0; i < numbers.size(); i++) {
        long long c = numbers.at(i) + prefixSum.back();
        prefixSum.push_back(c);
    }

    while (q--) {
        int from; int to; cin >> from; cin >> to; from--; to--;
        cout << prefixSum.at(to + 1) - prefixSum.at(from) << "\n";
    }



    return 0;
}

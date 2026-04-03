#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n; int x; cin >> n; cin >>x;
    vector<int> numbers;
    vector<int> prefixSum;
    map<int, int> map;

    while (n--) {
        int current;
        cin >> current;
        numbers.push_back(current);
        if (! prefixSum.empty()) {
            prefixSum.push_back(prefixSum.back() + current);
        } else {
            prefixSum.push_back(current);
        }
    if (map.contains(1)) {

        }
        map.at(x - current) =
    }

    for (int i = 0; i < numbers.size(); i++) {

    }
    int ans = 0;
    cout << ans;
    return 0;
}

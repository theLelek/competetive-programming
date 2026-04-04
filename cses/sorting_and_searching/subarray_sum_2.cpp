#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n; long long x; cin >> n; cin >>x;
    vector<long long> numbers;
    vector<long long> prefixSum;
    map<long long, long long> map;
    long long ans = 0;
    map[0] = 1;

    for (int i = 0; i < n; i++) {
        long long current;
        cin >> current;
        numbers.push_back(current);
        if (! prefixSum.empty()) {
            prefixSum.push_back(prefixSum.back() + current);
        } else {
            prefixSum.push_back(current);
        }

        if (map.count(prefixSum.at(i) - x)) {
            ans += map.at(prefixSum.at(i) - x);
        }
        map.insert({prefixSum.back(), 0});
        map[prefixSum.back()] += 1;
//        cout << map.at(prefixSum.at(i) - x) << endl;
    }
    cout << ans;
    return 0;
}
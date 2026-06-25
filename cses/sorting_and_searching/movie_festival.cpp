#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> numbers;
    for (int i = 0; i < n; i++) {
        int a; int b; cin >> a; cin >> b;
        vector<int> current = {b, a};
        numbers.push_back(current);
    }


    sort(numbers.begin(), numbers.end()); // todo how to sort after 2. element


    int prevEnd = INT_MIN;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int start = numbers.at(i).at(1);
        int end = numbers.at(i).at(0);
        if (start >= prevEnd) {
            ans++;
            prevEnd = end;
        }
    }

    cout << ans;
    return 0;
}
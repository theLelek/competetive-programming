#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> input;

int getFirstLowerOrEqual(int target) {
    // get last true
    int l = -1;
    int r = input.size() - 1;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (input.at(m) <= target) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    if (l == -1) return -1;
    return input.at(l);
}

bool canTargetAll(int power) {
    int left = input.at(0);
    int right = getFirstLowerOrEqual(left + power);
    while (left != right) {
        left = right;
        right = getFirstLowerOrEqual(left + power);
    }
    return left == input.back();
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        input.push_back(c);
    }
    sort(input.begin(), input.end());

    cout << canTargetAll(3);



    return 0;
}
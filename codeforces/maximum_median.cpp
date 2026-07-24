#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n; int k;
vector<int> numbers;

int getOperations(int medianIncrease) {
    int medianIdx = numbers.size() / 2;
    int count = 0;
    int medianToSet = numbers.at(medianIdx) + medianIncrease;
    for (int i = medianIdx; i < numbers.size(); i++) {
        if (numbers.at(i) >= medianToSet) {
            continue;
        }

        count += medianToSet - numbers.at(i);
    }
    return count;
}

bool isTrue(int m) {
    return getOperations(m) <= k;
}

int lastTrue(int l, int r) {
    l--;
    while (l < r) {
        int m = l + (r - l + 1) / 2;

        if (isTrue(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}


int main() {
    cin >> n; cin >> k;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }

    sort(numbers.begin(), numbers.end());

    // last true

    int medianIndex = numbers.size() / 2;

    int lastTrueIndex = lastTrue(1, k + 5);

    if (lastTrueIndex == 0) {
        cout << numbers.at(medianIndex);
    } else {
        cout << numbers.at(medianIndex) + lastTrueIndex;
    }
    return 0;
}
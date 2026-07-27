#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;
int n;
int k;

int minimumAmountOfSubArrays(long long maxSum) {
    int amount = 1;

    long long currentSum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers.at(i) > maxSum) return -1;

        currentSum += numbers.at(i);

        if (currentSum > maxSum) {
            amount++;
            currentSum = numbers.at(i);
        }
    }
    return amount;
}

bool isTrue(long long m) {
    long long foo = minimumAmountOfSubArrays(m);
    return foo != -1 && foo <= k;
}

long long firstTrue() {
    long long l = 0;
    long long r = LONG_LONG_MAX / 2;
    while (l < r) {
        long long m = l + (r - l) / 2;
        if (isTrue(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int main() {
    cin >> n; cin >> k;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }
    cout << firstTrue() << "\n";

    return 0;
}
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<long long> numbers;
long long bestDiff = INT_MAX;

void generateSubsets(vector<long long> &subset1, vector<long long> &subset2, long long sum1, long long sum2, int k) {
    if (k == numbers.size()) {
        if (abs(sum1 - sum2) < bestDiff) {
            bestDiff = abs(sum1 - sum2);
        }
        return;
    }
    subset1.push_back(numbers.at(k));
    generateSubsets(subset1, subset2, sum1 + numbers.at(k), sum2, k + 1);
    subset1.pop_back();

    subset2.push_back(numbers.at(k));
    generateSubsets(subset1, subset2, sum1, sum2 + numbers[k], k + 1);
    subset2.pop_back();
}

int main() {
    int n; cin >> n;
    vector<long long> subset1;
    vector<long long> subset2;
    while (n--) {
        int c; cin >> c;
        numbers.push_back(c);
    }
    generateSubsets(subset1, subset2, 0, 0, 0);
    cout << bestDiff;
    return 0;
}
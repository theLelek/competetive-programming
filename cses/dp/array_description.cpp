#include <limits.h>
#include <vector>
using namespace std;

#include <iostream>

vector<int> numbers;
int m;

int solveRecursively(int idx, int prevValue) {
    if (idx == numbers.size()) {
        return 1;
    }
    int ans = 0;
    if (numbers.at(idx) == 0) {
        for (int i = 1; i <= m; i++) {
           if (abs(prevValue - i) <= 1 || idx == 0) {
               ans += solveRecursively(idx + 1, i);
           }
        }
    } else if (abs(prevValue - numbers.at(idx)) <= 1) {
        ans += solveRecursively(idx + 1,  numbers.at(idx));
    } else {
        return 0;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        numbers.push_back(c);
    }
    cout << solveRecursively(0, numbers.at(0));
    return 0;
}
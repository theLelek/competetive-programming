#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<int> numbers;
set<int> out;

int solveRecursively(int idx, int currentSum) {
    if (idx == numbers.size()) {

        return 1;
    }
    return solveRecursively(idx + 1, currentSum) + solveRecursively(idx + 1, currentSum + numbers.at(idx));
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c; numbers.push_back(c);
    }
    dp.resize(100, vector<int>(1000, -1));;
    solveRecursively(0, 0);
    for (int element : out) {
        cout << element << " ";
    }
    return 0;
}

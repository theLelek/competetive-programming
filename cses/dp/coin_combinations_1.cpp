#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> numbers;

int solveRecursively(int targetSum) {
    if (targetSum == 0) {
        return 1;
    }
    if (targetSum < 0) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < numbers.size(); i++) {
        count += solveRecursively(targetSum - numbers.at(i));
    }
    return count;
}

int main() {
    int n; int x; cin >> n; cin >> x;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }

    dp.resize(n + 5, -1);
    cout << solveRecursively(x);
    return 0;
}
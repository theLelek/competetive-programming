#include <iostream>
#include <vector>

using namespace std;

vector<int> dp; // index = coin sum | value = how many combinations
vector<int> numbers;

int solveRecursively(int targetSum) {
    if (targetSum == 0) {
        return 1;
    }
    if (targetSum < 0) {
        return 0;
    }
    if (dp.at(targetSum) != -1) {
        return dp.at(targetSum);
    }

    int count = 0;
    for (int i = 0; i < numbers.size(); i++) {
        int foo = solveRecursively(targetSum - numbers.at(i)) % 1000000007;
        count = (foo != -1) ? count + foo : count;
        count = count % 1000000007;
    }
    dp.at(targetSum) = count;
    return count;
}

int main() {
    int n; int x; cin >> n; cin >> x;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }

    dp.resize(x + 5, -1);
    cout << solveRecursively(x);
    return 0;
}
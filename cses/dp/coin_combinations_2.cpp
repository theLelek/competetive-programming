#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp; // index = coin sum | value = how many combinations
vector<int> numbers;

int solveRecursively(int targetSum, int idx) {
    if (targetSum == 0) {
        return 1;
    }
    if (targetSum < 0) {
        return 0;
    }
    if (dp.at(targetSum).at(idx) != -1) {
        return dp.at(targetSum).at(idx);
    }

    int count = 0;
    for (int i = idx; i < numbers.size(); i++) {
        count += solveRecursively(targetSum - numbers.at(i), i) % 1000000007;
        count = count % 1000000007;
    }
    dp.at(targetSum).at(idx) = count;
    return count;
}


int main() {
    int n; int x; cin >> n; cin >> x;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }

    dp.resize(x + 5, vector<int>(n + 5, -1));
    cout << solveRecursively(x, 0);
    return 0;
}
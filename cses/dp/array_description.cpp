#include <vector>
using namespace std;

#include <iostream>

vector<int> numbers;
int m;

int solveRecursively(int idx) {
    if (idx == numbers.size()) {
        return 0;
    }
    int ans = 0;
    if (numbers.at(idx) == 0) {

    }

    ans += solveRecursively(idx + 1);
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
    cout << solveRecursively();

    // n numbers between 1 and  m,
    // the absolute difference between two adjacent values is at most 1.
    // value = 0 -> unknown value

    // subproblem = number of arrays
    // dp state = idx, prev 
    return 0;
}
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    stack<vector<int>> monotonicStack; // [0] = value [1] = index
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        while (monotonicStack.size() > 0 && monotonicStack.top().at(0) >= c) {
            monotonicStack.pop();
        }
        if (monotonicStack.size() == 0) {
            cout << 0 << " ";
        } else {
            cout << monotonicStack.top().at(1) + 1<< " ";
        }
        monotonicStack.push({c, i});
    }
    return 0;
}
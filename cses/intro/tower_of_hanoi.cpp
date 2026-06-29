#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int getCurrentTo(int from, int to) {
    for (int i = 0; i <= 2; i++) {
        if (i != from && i != to) return i;
    }
    return -1;
}

int n;
vector<stack<int>> towers;
vector<vector<int>> out;

void move(int amount, int from, int to) {
    if (amount == 1) {
        out.push_back({from, to});
        int foo = towers.at(from).top();
        towers.at(from).pop();
        towers.at(to).push(foo);
        return;
    }
    int currentTo = getCurrentTo(from, to);

    move(amount - 1, from, currentTo);

    int foo = towers.at(from).top();
    towers.at(from).pop();
    towers.at(to).push(foo);
    out.push_back({from, to});

    move(amount - 1, currentTo, to);
}

int main() {
    cin >> n;
    towers.resize(3, stack<int>());
    for (int i = n; i >= 1; i--) {
        towers.at(0).push(i);
    }
    move(n, 0 , 2);

    cout << out.size() << "\n";
    for (int i = 0; i < out.size(); i++) {
        cout << out.at(i).at(0) + 1 << " " << out.at(i).at(1) + 1 << "\n";
    }
    return 0;
}
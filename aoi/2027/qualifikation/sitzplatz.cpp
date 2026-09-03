#include <iostream>

using namespace std;


int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int k; int v; int u; int w;
        cin >> k; cin >> v; cin >> u; cin >> w;

        int seats = k * v;
        if (seats - u - w > 0) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}
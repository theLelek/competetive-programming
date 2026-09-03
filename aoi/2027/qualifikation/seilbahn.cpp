#include <iostream>

using namespace std;

int main() {
    int n; int p;
    cin >> n; cin >> p;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int s; cin >> s;

        p -= s;
        if (p <= 0) {
            ans = i + 1;
            break;
        }
    }

    cout << ans;
    return 0;
}
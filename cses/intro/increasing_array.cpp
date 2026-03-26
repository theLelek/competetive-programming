#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int previous;
    int current = -1;
    long long out = 0;
    while (n--) {
        previous = current;
        cin >> current;
        if (previous > current) {
            out += previous - current;
            current = previous;
        }
    }
    cout << out;
    return 0;
}
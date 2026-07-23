#include <iostream>
#include <vector>

using namespace std;

bool isTrue(int value) {
    return value < 5;
}

int lastTrue(int l, int r) {
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (isTrue(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return r;
}

int main() {

    cout << lastTrue(0, 67);

    return 0;
}
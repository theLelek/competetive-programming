#include <iostream>
#include <vector>

using namespace std;

bool isTrue(int value) {
    return value > 5;
}

int lastTrue(int l, int r) {
    l--;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (isTrue(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int firstTrue(int l, int r) {
    r++;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (isTrue(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int main() {

    cout << firstTrue(0, 10);

    return 0;
}
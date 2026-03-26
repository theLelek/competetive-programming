#include <vector>
#include "iostream"

using namespace std;

int main() {
    int n; cin >> n;
    vector<bool> numbers(n);
    n--;
    while (n--) {
        int c; cin >> c;
        numbers.at(c - 1) = true;
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (! numbers.at(i)) {
            cout << i + 1;
        }
    }
    return 0;
}
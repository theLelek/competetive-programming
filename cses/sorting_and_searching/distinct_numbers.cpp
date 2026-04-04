#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    int n; cin >> n;
    set<long long> numbers;

    while (n--) {
        long long current; cin >> current;
        numbers.insert(current);
    }
    cout << numbers.size();
    return 0;
}
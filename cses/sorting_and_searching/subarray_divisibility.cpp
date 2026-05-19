#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> numbers(n);
    numbers.at(0) = 1;
    long long prefixSum = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        prefixSum += c;
        int remainder = ((prefixSum % n) + n) % n;
        ans += numbers.at(remainder);
        numbers.at(remainder)++;
    }
    cout << ans;
    return 0;
}
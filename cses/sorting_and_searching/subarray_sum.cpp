#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; int x; cin >> n; cin >> x;
    vector<int> numbers;
    while (n--) {
        int current;
        cin >> current;
        numbers.push_back(current);
    }
    int ans = 0;
    int currentSum = 0;
    int j = 0;
    for (int i = 0; i < numbers.size(); i++) {
        while (j < numbers.size() && currentSum < x) {
            currentSum += numbers[j];
            j++;
        }
        if (currentSum == x) {
            ans++;
        }
        currentSum -= numbers[i];
    }
    cout << ans;
    return 0;
}
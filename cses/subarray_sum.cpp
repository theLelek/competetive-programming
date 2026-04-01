#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n; int x; cin >> n; cin >>x;
    vector<int> numbers;
    while (n--) {
        int current;
        cin >> current;
        numbers.push_back(current);
    }

    int ans = 0;

    int r = 0;
    int currentSum = numbers[0];
    for (int l = 0; l < numbers.size(); l++) {
        while (r + 1 < numbers.size() && currentSum + numbers[r + 1] <= x) {
            currentSum += numbers[r + 1];
            r++;
        }
        if (currentSum == x) {
//            cout << l << " " << r << "\n";
            ans++;
        }
        currentSum -= numbers[l];
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int n; int k;

struct number {
    bool isPositive;
    int value;
};

vector<number> compress() {
    vector<number> numbers;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;

        if (a == 0) {
            if (numbers.size() == 0 || numbers.back().isPositive) {
                numbers.push_back({false, 0});
            }
            numbers.back().value += 1;
        } else {
            if (numbers.size() == 0 || ! numbers.back().isPositive) {
                numbers.push_back({true, 0});
            }
            numbers.back().value += a;
        }
    }
    return numbers;
}

int getStreak(vector<number> &numbers, int start) {
    int streak = 0;
    int usedFreezes = 0;
    for (int i = start; i < numbers.size(); i++) {
        if (! numbers.at(i).isPositive) {
            usedFreezes += numbers.at(i).value;
        } else {
            streak += numbers.at(i).value;
        }
        if (usedFreezes > k) {
            return streak + k;
        }
    }
    return streak + usedFreezes;
}

int main() {
    cin >> n; cin >> k;

    vector<number> numbers = compress();


    int ans = 0;
    for (int i = 0; i < numbers.size(); i++) {
        ans = max(ans, getStreak(numbers, i));
    }
    cout << ans;
    return 0;
}
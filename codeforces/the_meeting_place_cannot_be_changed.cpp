#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n;
vector<int> friendsCoords;
vector<int> maxSpeed;

bool canFriendsMeet(long double seconds) {
    long double firstTravelDistance = maxSpeed.at(0) * seconds;
    pair<long double, long double> range = {friendsCoords.at(0) - firstTravelDistance, friendsCoords.at(0) + firstTravelDistance};
    for (int i = 1; i < n; i++) {
        long double currentTravelDistance = maxSpeed.at(i) * seconds;
        long double from = friendsCoords.at(i) - currentTravelDistance;
        long double to = friendsCoords.at(i) + currentTravelDistance;
        if (from > range.second || to < range.first) return false;
        range.first = max(range.first, from);
        range.second = min(range.second, to);;
    }
    return true;
}

long double firstTrue() {
    long double l = 0;
    long double r = LONG_LONG_MAX;
    long double foo = pow(10, -7);
    while (l < r - foo) {
        long double m = l + (r - l) / 2;
        if (canFriendsMeet(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        friendsCoords.push_back(c);
    }
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        maxSpeed.push_back(c);
    }

    cout << fixed << setprecision(10) << firstTrue();

    return 0;
}
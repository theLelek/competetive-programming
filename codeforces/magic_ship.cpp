#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

long long x1; long long y1;
long long x2; long long y2;
long long n;
vector<long long> placement;
string directions;

vector<long long> getDirection(char c) {
    switch (c) {
        case 'U':
            return {0, 1};
        case 'D':
            return {0, -1};
        case 'L':
            return {-1, 0};
        case 'R':
            return {1, 0};
    }
    return {};
}

vector<long long> getPlacementAfterNDays() {
    vector<long long> placement = {0, 0};
    for (long long i = 0; i < directions.size(); i++) {
        vector<long long> direction = getDirection(directions.at(i));
        placement.at(0) += direction.at(0);
        placement.at(1) += direction.at(1);
    }
    return placement;
}

vector<long long> getPlacementAfterDays(long long days) {
    long long fitsAmount = days / directions.size();
    vector<long long> out = {placement.at(0) * fitsAmount, placement.at(1) * fitsAmount};
    for (long long i = 0; i + fitsAmount * directions.size() < days; i++) {
        vector<long long> currentDirection = getDirection(directions.at(i));
        out.at(0) += currentDirection.at(0);
        out.at(1) += currentDirection.at(1);
    }
    return out;
}

bool isPositionVisitable(long long x1, long long y1, long long x2, long long y2, long long days) {
    return abs(x1 - x2) + abs(y1 - y2) <= days;
}

long long firstTrue() {
    long long l = 1;
    long long r = LONG_LONG_MAX;
    while (l < r) {
        long long m = l + (r - l) / 2;
        vector<long long> piecePlacements = getPlacementAfterDays(m);
        if (isPositionVisitable(x1, y1, x2 + (-piecePlacements.at(0)), y2 + (-piecePlacements.at(1)), m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (r == LONG_LONG_MAX) return -1;
    return r;
}

int main() {

    cin >> x1; cin >> y1;
    cin >> x2; cin >> y2;
    cin >> n;
    cin >> directions;

    placement = getPlacementAfterNDays();
    cout << firstTrue();

    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<long long>> numbers;
    for (int i = 0; i < n; i++) {
        int duration; int deadline;
        cin >> duration; cin >> deadline;
        numbers.push_back({duration, deadline});
    }

    sort(numbers.begin(), numbers.end());

    long long ans = 0;
    long long time = 0;
    for (int i = 0; i < n; i++) {
        long long duration = numbers.at(i).at(0); // todo maybe change
        long long deadline = numbers.at(i).at(1);
        ans += deadline - duration - time;
        time += duration;
    }

    cout << ans;
    return 0;
}
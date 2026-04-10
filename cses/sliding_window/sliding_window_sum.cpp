#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    int n; int k; cin >> n; cin >> k;
    long long x; long long a; long long b; long long c; cin >> x; cin >> a; cin >> b; cin >> c;
    list<long long> window;
    long long currentSum = x;
    long long currentElement = x;
    window.push_back(x);
    long long ans = -1;
    for (int i = 0; i < n; i++) {
//        cout << currentElement << " ";

        if (window.size() > k) {
            currentSum -= window.front();
            window.pop_front();
        }
        if (window.size() == k) {
//            cout << currentSum << " ";
            if (ans == -1) {
                ans = currentSum;
            } else {
                ans = ans ^ currentSum;
            }
        }
        currentElement = (a * currentElement + b) % c;
        window.push_back(currentElement);
        currentSum += currentElement;
    }

    cout << ans;
    return 0;
}
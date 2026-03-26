#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;
    if (n == 4) {
        cout << "2 4 1 3";
        return 0;
    }
    vector<int> out;
    for (int i = 0; i < n; i+=2) {
        out.push_back(i + 1);
    }
    for (int i = 1; i < n; i+=2) {
        out.push_back(i + 1);
        if (abs(out.back() - out[out.size() - 2]) == 1) {
            cout << "NO SOLUTION";
            return 0;
        }
    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
   }
    return 0;
}
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int n; int k;
    fin >> n; fin >> k;
    vector<int> numbers;

    for (int i = 0; i < n; i++) {
        int c; fin >> c;
        numbers.push_back(c);
    }
    sort(numbers.begin(), numbers.end());

    vector<int> prefixDiamonds(n);
    vector<pair<int, int>> diamonds;

    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r != n - 1 && abs(numbers.at(l) - numbers.at(r + 1)) <= k) {
            r++;
        }
        int size = r - l + 1;
        prefixDiamonds.at(l) = size;

        diamonds.push_back({l, r});
    }

    int highest = 0;
    for (int i = prefixDiamonds.size() - 1; i >= 0; i--) {
        if (prefixDiamonds.at(i) > highest) {
            highest = prefixDiamonds.at(i);
        }
        prefixDiamonds.at(i) = highest;
    }

    int ans = 1;
    for (int i = 0; i < diamonds.size(); i++) {
        int l = diamonds.at(i).first;
        int r = diamonds.at(i).second;
        int size = r - l + 1;
        int toAdd = r == prefixDiamonds.size() - 1 ? 0 : prefixDiamonds.at(r + 1);
        ans = max(ans, size + toAdd);
    }
    fout << ans;
    return 0;
}
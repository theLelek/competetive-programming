#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int lowerBound(vector<int> &numbers, int target) {
    int l = 0;
    int r = numbers.size();
    while (l < r) {
        int m = l + (r - l) / 2;

        if (numbers.at(m) >= target) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int upperBound(vector<int> &numbers, int target) {
    int l = 0;
    int r = numbers.size();
    while (l < r) {
        int m = l + (r - l) / 2;

        if (numbers.at(m) > target) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int main() {
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    int n; int q;
    fin >> n; fin >> q;

    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int c; fin >> c;
        numbers.push_back(c);
    }

    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < q; i++) {
        int a; int b;
        fin >> a; fin >> b;

        int index1 = lowerBound(numbers, a);
        int index2 = upperBound(numbers, b);

        fout << index2 - index1 << "\n";
    }
    return 0;
}

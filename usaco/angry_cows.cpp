#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n; int k;
vector<int> numbers;

bool canAllCowsBeKilled(int power) {
    int leftIndex = 0;
    for (int i = 0; i < k; i++) {
        int end = numbers.at(leftIndex) + power * 2;
        int j;
        for (j = 0; j < numbers.size(); j++) {
            if (numbers.at(j) > end) break;
        }
        leftIndex = j;
        if (leftIndex == numbers.size()) return true;
    }
    return false;
}

int firstTrue() {
    int l = 1;
    int r = INT_MAX / 2;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (canAllCowsBeKilled(m)) {
            r = m;
        } else {
           l = m + 1;
        }
    }
    return r;
}

int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    fin >> n; fin >> k;
    for (int i = 0; i < n; i++) {
        int c; fin >> c,
        numbers.push_back(c);
    }
    sort(numbers.begin(), numbers.end());

    fout << firstTrue();
}
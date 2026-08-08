#include <iostream>
#include <vector>

using namespace std;

struct node {
    vector<int> parents;
};

int main() {
    int n; int q;
    cin >> n; cin >> q;

    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }


     
    return 0;
}
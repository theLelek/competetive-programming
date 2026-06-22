#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> numbers;
set<int> out;


// void solveRecursively(int idx, int currentSum) {
//     if (idx == numbers.size()) {
//         out.insert(currentSum);
//         return;
//     }
//
//     solveRecursively(idx + 1, currentSum + numbers.at(idx));
//     solveRecursively(idx + 1, currentSum);
// }

void solveIteratively(int n) {
    out.insert(numbers.at(0));
    for (int i = 1; i < n; i++) {
        set<int> holder;
        int ans1 = numbers.at(i);
        holder.insert(ans1);
        for (int element : out) {
            int ans2 = element;
            int ans3 = ans1 + ans2;
            holder.insert(ans2);
            holder.insert(ans3);
        }
        out.insert(holder.begin(), holder.end());
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c; numbers.push_back(c);
    }
    solveIteratively(n);
    cout << out.size() << "\n";
    for (int element : out) {
        cout << element << " ";
    }
    return 0;
}

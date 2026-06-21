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
    dp.push_back(numbers.at(0));
    out.insert(numbers.at(0));
    for (int i = 1; i < n; i++) {
        vector<int> holder;
        int ans1 = numbers.at(i);
        out.insert(ans1);
        holder.push_back(ans1);
        for (int j = 0; j < dp.size(); j++) {
            int ans2 = dp.at(j);
            int ans3 = ans1 + ans2;
            out.insert(ans2);
            out.insert(ans3);
            holder.push_back(ans2);
            holder.push_back(ans3);
        }
        dp = holder;
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

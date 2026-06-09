#include <iostream>
#include <vector>
#include <pstl/execution_defs.h>
using namespace std;

vector<int> parents;
vector<int> nodeCount;
int largestComponent = 1;

int find(int node) {
    if (parents.at(node) == node) return node;
    parents.at(node) = find(parents.at(node));
    return parents.at(node);
}

int unite(int a, int b) {
    int f1 = find(a);
    int f2 = find(b);
    if (f1 != f2) {
        if (nodeCount.at(f1) > nodeCount.at(f2)) {
            parents.at(f2) = f1;
            nodeCount.at(f1) += nodeCount.at(f2);
            largestComponent = max(largestComponent, nodeCount.at(f1));
        } else {
            parents.at(f1) = f2;
            nodeCount.at(f2) += nodeCount.at(f1);
            largestComponent = max(largestComponent, nodeCount.at(f2));
        }
        return 1;
    }
    return 0;
}

int main() {
    vector<int> dp;
    int n; int m;
    cin >> n; cin >> m;

    parents.resize(n + 1);
    nodeCount.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parents.at(i) = i;
    }

    int count = n;
    for (int i = 1; i <= m; i++) {
        int a; int b;
        cin >> a; cin >> b;
        count -= unite(a, b);
        cout << count << " " << largestComponent << "\n";
    }
    return 0;
}
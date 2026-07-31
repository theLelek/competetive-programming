#include <iostream>
#include <vector>

using namespace std;

struct element {
    long long value;
    long long lazyValue;
};

vector<long long> numbers;
vector<element> segmentTree;

long long buildHelper(long long nodeFrom, long long nodeTo, long long index) {
    if (nodeFrom == nodeTo) {
        segmentTree.at(index).value = numbers.at(nodeFrom);
        return numbers.at(nodeFrom);
    }

    long long m = nodeFrom + (nodeTo - nodeFrom) / 2;
    long long l = buildHelper(nodeFrom, m, index * 2);
    long long r = buildHelper(m + 1, nodeTo, index * 2 + 1);
    segmentTree.at(index).value = l + r;
    return l + r;
}

void buildSegmentTree() {
    segmentTree.resize((numbers.size() + 1) * 4);
    buildHelper(0, numbers.size() - 1, 1);
}

long long answer(long long nodeFrom, long long nodeTo, long long index, long long from, long long to) {
    if (nodeFrom >= from && nodeTo <= to) {
        return segmentTree.at(index).value;
    }
    if (from > nodeTo || to < nodeFrom) {
        return 0;
    }

    long long m = nodeFrom + (nodeTo - nodeFrom) / 2;
    long long currentLazyValue = segmentTree.at(index).lazyValue;
    long long amountOfNodesLeft = m - nodeFrom + 1;
    long long amountOfNodesRight = nodeTo - (m + 1) + 1;

    segmentTree.at(index * 2).value += currentLazyValue * amountOfNodesLeft;
    segmentTree.at(index * 2).lazyValue += currentLazyValue;

    segmentTree.at(index * 2 + 1).value += currentLazyValue * amountOfNodesRight;
    segmentTree.at(index * 2 + 1).lazyValue += currentLazyValue;

    segmentTree.at(index).lazyValue = 0;

    long long l = answer(nodeFrom, m, index * 2, from, to);
    long long r = answer(m + 1, nodeTo, index * 2 + 1, from, to);

    return l + r;
}

long long update(long long nodeFrom, long long nodeTo, long long index, long long from, long long to, long long toAdd) {
    if (nodeFrom > to || nodeTo < from) {
        return segmentTree.at(index).value;
    }

    long long m = nodeFrom + (nodeTo - nodeFrom) / 2;

    if (nodeFrom != nodeTo) {
        long long amountOfNodesLeft = m - nodeFrom + 1;
        long long amountOfNodesRight = nodeTo - (m + 1) + 1;
        long long currentLazyValue = segmentTree.at(index).lazyValue;

        segmentTree.at(index * 2).value += currentLazyValue * amountOfNodesLeft;
        segmentTree.at(index * 2).lazyValue += currentLazyValue;

        segmentTree.at(index * 2 + 1).value += currentLazyValue * amountOfNodesRight;
        segmentTree.at(index * 2 + 1).lazyValue += currentLazyValue;
        segmentTree.at(index).lazyValue = 0;
    }

    if (nodeFrom >= from && nodeTo <= to) {
        long long amountOfChildren = nodeTo - nodeFrom + 1;
        segmentTree.at(index).lazyValue += toAdd;
        segmentTree.at(index).value += toAdd * amountOfChildren;
        return segmentTree.at(index).value;
    }

    long long l = update(nodeFrom, m, index * 2, from, to, toAdd);
    long long r = update(m + 1, nodeTo, index * 2 + 1, from, to, toAdd);

    segmentTree.at(index).value = l + r;
    return l + r;
}

int main() {
    long long n; long long q;
    cin >> n; cin >> q;
    for (long long i = 0; i < n; i++) {
        long long c; cin >> c;
        numbers.push_back(c);
    }

    buildSegmentTree();

    for (long long i = 0; i < q; i++) {
        long long type; cin >> type;
        if (type == 1) {
            long long a; long long b; long long u;
            cin >> a; cin >> b; cin >> u;
            // update
            update(0, numbers.size() - 1, 1, a - 1, b - 1, u);
        } else {
            // answer
            long long k; cin >> k;
            cout << answer(0, numbers.size() - 1, 1, k - 1, k - 1) << "\n";
        }
    }
    return 0;
}
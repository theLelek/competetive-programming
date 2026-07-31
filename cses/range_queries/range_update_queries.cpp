#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

struct element {
    int value;
    int lazyValue;
};

vector<int> numbers;
vector<element> segmentTree;

int buildHelper(int nodeFrom, int nodeTo, int index) {
    if (nodeFrom == nodeTo) {
        segmentTree.at(index).value = numbers.at(nodeFrom);
        return numbers.at(nodeFrom);
    }

    int m = nodeFrom + (nodeTo - nodeFrom) / 2;
    int l = buildHelper(nodeFrom, m, index * 2);
    int r = buildHelper(m + 1, nodeTo, index * 2 + 1);
    segmentTree.at(index).value = l + r;
    return l + r;
}

void buildSegmentTree() {
    segmentTree.resize(numbers.size() * 4);
    buildHelper(0, numbers.size() - 1, 1);
}

int answer(int nodeFrom, int nodeTo, int index, int from, int to) {
    int amountOfChildNodes = to - from + 1;
    if (nodeFrom >= from && nodeTo <= to) {
        return segmentTree.at(index).value + segmentTree.at(index).lazyValue * amountOfChildNodes;
    }
    if (from > nodeTo || to < nodeFrom) {
        return 0;
    }

    int m = nodeFrom + (nodeTo - nodeFrom) / 2;
    int currentLazyValue = segmentTree.at(index).lazyValue;

    segmentTree.at(index * 2).lazyValue += currentLazyValue;
    segmentTree.at(index * 2 + 1).lazyValue += currentLazyValue;
    segmentTree.at(index).lazyValue = 0;
    segmentTree.at(index).value += currentLazyValue * amountOfChildNodes;

    int l = answer(nodeFrom, m, index * 2, from, to);
    int r = answer(m + 1, nodeTo, index * 2 + 1, from, to);

    return l + r;
}

void update(int nodeFrom, int nodeTo, int index, int from, int to) {

}


int main() {
    int n; int q;
    cin >> n; cin >> q;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c);
    }

    buildSegmentTree();

    segmentTree.at(1).lazyValue = 10;
    cout << answer(0, numbers.size() - 1, 1, 0, 1);
    return 0;
}
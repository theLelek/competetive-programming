#include <iostream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    char previous = line[0];
    char current;
    int out = 1;
    int count = 1;
    for (int i = 1; i < line.size(); i++) {
        current = line[i];
        out = max(out, count);
        if (previous == current) {
            count++;
        } else {
            count = 1;
        }
        previous = current;
    }
    cout << max(out, count);
    return 0;
}

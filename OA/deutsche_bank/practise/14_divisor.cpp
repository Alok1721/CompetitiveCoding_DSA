#include <iostream>
#include <vector>
using namespace std;

int count = 0;
int n, p;

void backtrack(int idx, int prev) {
    if (idx == n) {
        count++;
        return;
    }

    // Start from 1 up to p / prev to ensure product is ≤ p
    int maxVal = (idx == 0) ? p : (p / prev);
    for (int i = 1; i <= maxVal; i++) {
        backtrack(idx + 1, i);
    }
}

int main() {
    cin >> n >> p;
    count = 0;
    backtrack(0, 1);
    cout << count << endl;
    return 0;
}

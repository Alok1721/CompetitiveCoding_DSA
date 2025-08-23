#include <bits/stdc++.h>
using namespace std;

string minimizeByCharSwaps(string s) {
    int n = s.size();
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());

    vector<bool> fixedPos(n, false);
    for (int i = 0; i < n; i++) {
        if (s[i] == sorted_s[i]) {
            fixedPos[i] = true; // already correct place
        }
    }

    for (int i = 0; i < n; i++) {
        if (fixedPos[i]) continue; // don't touch fixed positions

        char smallest = s[i];
        int swapIndex = -1;

        // find smallest possible swap candidate in non-fixed positions to the right
        for (int j = n - 1; j > i; j--) {
            if (!fixedPos[j] && s[j] < smallest) {
                smallest = s[j];
                swapIndex = j;
            }
        }

        if (swapIndex != -1 && s[swapIndex] < s[i]) {
            swap(s[i], s[swapIndex]);
            // after swapping, check if those positions are now fixed
            if (s[i] == sorted_s[i]) fixedPos[i] = true;
            if (s[swapIndex] == sorted_s[swapIndex]) fixedPos[swapIndex] = true;
        }
    }

    return s;
}

int main() {
    string s;
    cin >> s;
    cout << minimizeByCharSwaps(s) << "\n";
    return 0;
}

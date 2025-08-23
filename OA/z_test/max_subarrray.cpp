#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {-1, 2, 4, -5, 3, -5, 3, -5}; // fixed initialization
    int n = arr.size();

    int ans = arr[0];
    int sum = 0;
    int left = 0, right = 0, tempStart = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > ans) {
            ans = sum;
            left = tempStart;
            right = i;
        }

        if (sum < 0) {
            sum = 0;
            tempStart = i + 1;  // next index may be new start
        }
    }

    cout << "Max Sum = " << ans << " from index " << left << " to " << right << "\n";
    return 0;
}

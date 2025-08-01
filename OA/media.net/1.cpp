#include <bits/stdc++.h>
using namespace std;

// Count set bits in integer
int bit_count(int n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if ((1 << i) & n)
            count++;
    }
    return count;
}

// Backtracking function
void rec(int index, int n, vector<int>& arr, vector<int>& path, int pre_XOR, unordered_set<int>& result) {
    if (path.size() >= 2) {
        result.insert(pre_XOR);
    }

    for (int i = index; i < n; i++) {
        // Always allow first element
        if (path.empty()) {
            path.push_back(arr[i]);
            rec(i + 1, n, arr, path, arr[i], result);
            path.pop_back();
        } else {
            // Check if strictly increasing
            if (arr[i] > path.back()) {
                // Check XOR condition
                int curr_bitcount = bit_count(pre_XOR);
                int next_bitcount = bit_count(arr[i]);
                if (curr_bitcount <= next_bitcount) {
                    path.push_back(arr[i]);
                    rec(i + 1, n, arr, path, pre_XOR ^ arr[i], result);
                    path.pop_back();
                }
            }
        }
    }
}

int solve(vector<int>& arr) {
    int n = arr.size();
    unordered_set<int> result;
    vector<int> path;
    rec(0, n, arr, path, 0, result);
    return result.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(a) << endl;
    return 0;
}

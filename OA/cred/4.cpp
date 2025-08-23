#include <bits/stdc++.h>
using namespace std;

string mergeStrings(const string &A, const string &B) {
    if (!A.empty() && !B.empty() && A.back() == B.front()) {
        return A + B.substr(1);
    } else {
        return A + B;
    }
}

int findShortestLengthNumber(vector<string> &arr, int n) {
    string result = arr[0];
    for (int i = 1; i < n; i++) {
        string y = arr[i];
        string merged1 = mergeStrings(result, y);
        string merged2 = mergeStrings(y, result);
        if (merged1.size() <= merged2.size()) {
            result = merged1;
        } else {
            result = merged2;
        }
    }
    cout << result << "\n";
    return result.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << findShortestLengthNumber(arr, n) << "\n";
    }
    return 0;
}

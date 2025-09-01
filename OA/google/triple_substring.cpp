#include <bits/stdc++.h>
using namespace std;

// Expand around center and collect palindrome contributions
void expandAndCount(const string &s, int left, int right, 
                    vector<long long> &prefix, vector<long long> &suffix,
                    long long &ans) {
    int n = s.size();
    while (left >= 0 && right < n && s[left] == s[right]) {
        long long leftCount  = (left > 0 ? prefix[left-1] : 0);
        long long rightCount = (right+1 < n ? suffix[right+1] : 0);
        ans += leftCount * rightCount;

        left--; right++;
    }
}

// Utility to build prefix palindrome counts
vector<long long> buildPrefix(const string &s) {
    int n = s.size();
    vector<long long> prefix(n, 0);
    for (int center = 0; center < 2*n-1; center++) {
        int l = center/2, r = l + center%2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            prefix[r]++;  // palindrome ends at r
            l--; r++;
        }
    }
    for (int i = 1; i < n; i++) prefix[i] += prefix[i-1];
    return prefix;
}

// Utility to build suffix palindrome counts
vector<long long> buildSuffix(const string &s) {
    int n = s.size();
    vector<long long> suffix(n, 0);
    for (int center = 0; center < 2*n-1; center++) {
        int l = center/2, r = l + center%2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            suffix[l]++;  // palindrome starts at l
            l--; r++;
        }
    }
    for (int i = n-2; i >= 0; i--) suffix[i] += suffix[i+1];
    return suffix;
}

long long countPalindromicTriplets(const string &s) {
    int n = s.size();
    auto prefix = buildPrefix(s);
    auto suffix = buildSuffix(s);

    long long ans = 0;

    // Enumerate middle palindrome using center expansion
    for (int center = 0; center < 2*n-1; center++) {
        int l = center/2, r = l + center%2;
        expandAndCount(s, l, r, prefix, suffix, ans);
    }

    return ans;
}

// Example run
int main() {
    string s ;
    cin>>s;
    cout << countPalindromicTriplets(s) << "\n"; // Expected 5
    return 0;
}

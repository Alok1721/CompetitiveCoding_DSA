#include<bits/stdc++.h>
using namespace std;
// //!dp storage ways
// vector<pair<int,int>> palins; // store intervals [l, r]
// for (int len = 1; len <= n; len++) {
//     for (int l = 0; l + len - 1 < n; l++) {
//         int r = l + len - 1;
//         if (s[l] == s[r] && (len <= 2 || dp[l+1][r-1])) {
//             dp[l][r] = true;
//             palins.push_back({l, r});  // collect
//         }
//     }
// }

// //!center expanssion method O(1) space
// vector<pair<int,int>> palins;  // store [l, r]
// for (int center = 0; center < 2*n-1; center++) {
//     int left = center / 2;
//     int right = left + (center % 2); // handles odd/even
    
//     while (left >= 0 && right < n && s[left] == s[right]) {
//         palins.push_back({left, right});  // collect
//         left--; right++;
//     }
// }

int main()
{
    int n;
    string s;
    cin>>n>>s;
    vector<pair<int,int>> palins;  // store [l, r]
    for (int center = 0; center < 2*n-1; center++) {
        int left = center / 2;
        int right = left + (center % 2); // handles odd/even
        
        while (left >= 0 && right < n && s[left] == s[right]) {
            palins.push_back({left, right});  // collect
            left--; right++;
        }
    }
    for(auto it:palins)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
    
}
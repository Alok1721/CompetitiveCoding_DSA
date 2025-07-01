#include <bits/stdc++.h>
using namespace std;

int countShrinkArray(vector<long long>& a) {
    long long n = a.size();
    if(n<=1)return -1;
    if (n <= 2 && abs(a[0]-a[1])>1) return -1;

    for (long long i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) <=1) {
            return 0;
        }
    }
    sort(a.begin(), a.end());
    for (long long i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) <=1) {
            return 1;
        }
    }
    
    return -1; 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout<<countShrinkArray(a)<<endl;

    }
    return 0;

}
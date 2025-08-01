#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;


ll findTotalBits(int n) {
    
    ll total = 0;
    for (int i = 0; i < 32; i++) {
        ll cycleLen = 1LL << (i + 1);
        ll fullCycles = n / cycleLen;
        ll rem = n % cycleLen;
        
        total += fullCycles * (1LL << i);
        total += max(0LL, rem - (1LL << i) + 1);
    }
    return total;


}


int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<findTotalBits(n) << endl;
       
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool canBobWin(long long a, long long x, long long y) {
   int dist=abs(x-a);
    int lx=x-dist;
    int rx=x+dist;

    dist=abs(y-a);
    int ly=y-dist;
    int ry=y+dist;

    int l=max(lx,ly);
    int r=min(rx,ry);

    for(long long i=l; i<=r; i++) {
        if(i!=a )
        {
            return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t;
    cin >> t;
    
    while (t--) {
        long long a,x,y;
        cin>>a>>x>>y;
        cout<<(canBobWin(a,x,y)?"YES":"NO")<<endl;

    }
    return 0;

}
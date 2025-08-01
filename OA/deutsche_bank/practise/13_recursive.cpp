#include<bits/stdc++.h>
using namespace std;

pair<int,int> kFantasticSequence(int k,int t)
{
    // (a(i+1) = (k*b(i) + a(i)*a(i)) mod 3001
    // (b(i+1) = (k*a(i) + b(i)) mod 3001
    // a0=1 and b0=2
    // Return the T-th pair of the K-fantastic sequence

    vector<int> a(t+1), b(t+1);
    a[0] = 1;
    b[0] = 2;
    
    for(int i = 0; i < t; i++) {
        a[i+1] = (k * b[i] + a[i] * a[i]) % 3001;
        b[i+1] = (k * a[i] + b[i]) % 3001;
    }

    return {a[t], b[t]};
}

int main()
{
    int k,t;
    cin>>k>>t;
    cout<<kFantasticSequence(k,t).first<<" "<<kFantasticSequence(k,t).second<<endl;

    return 0;
}
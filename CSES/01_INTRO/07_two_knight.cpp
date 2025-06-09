#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long n;
    long long total_attack=0;
    long long knight_attack=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        total_attack=(1LL*(i*i)*((i*i) -1))/2;
        knight_attack=1LL*4*(i-1)*(i-2);
        cout<<total_attack-knight_attack<<endl;
    }
    
    return 0;
}
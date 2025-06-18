#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;

void solve(int n,int from ,int to , int aux)
{
    if(n==0)return ;
    solve(n-1,from,aux,to);
    cout<<from<<" "<<to<<"\n";
    solve(n-1,aux,to,from);

}



int main()
{
    int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n"; // 2^n - 1 for n = 2
    solve(n,1,3,2);
    return 0;
}
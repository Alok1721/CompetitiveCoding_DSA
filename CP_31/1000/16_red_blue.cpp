#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        long long n,r,b;
        cin>>n>>r>>b;
        string s;
        int len_red=r/(b+1);
        int extra_red=r%(b+1);
        for(int times=1;times<=b+1;times++)
        {
            for(int i=0;i<len_red;i++)
            {
                s+='R';
            }
            if(extra_red>0)
            {
                s+='R';
                extra_red--;
            }

            if(times!=b+1)
            {
                s+='B';
            }
        }
        cout<<s<<endl;

    }
    return 0;
}
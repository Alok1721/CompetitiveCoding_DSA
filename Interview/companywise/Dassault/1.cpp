#include<bits/stdc++.h>
using namespace std;
int findMaxNumber(vector<int> &a, int n)
{
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int num=abs(a[i]);
        while(num>0)
        {
            int digit=num%10;
            s.insert(digit);
            num=num/10;
        }
    }
    vector<int> digits(s.rbegin(),s.rend());
    int result=0;
    for(int digit:digits)
    {
        result=result*10+digit;
    }

    return result;

}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<findMaxNumber(a,n);;
    return 0;
}
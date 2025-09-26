#include<bits/stdc++.h>
using namespace std;
int sumOfDigits(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}


int findLargestNumber(int n)
{

    int ans=-1;
    int original_sum=sumOfDigits(n);
    for(int i=n-1;i>=0;i--)
    {
        int current_sum=sumOfDigits(i);
        if(current_sum>original_sum)
        {
            ans=i;
            break;
        }
    }
    return ans;
}
int main()
{

    int n;
    cin>>n;
    cout<<findLargestNumber(n);
    return 0;
}
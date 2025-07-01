#include <bits/stdc++.h>
using namespace std;

int findMaxSubarray(vector<long long>&a,vector<long long>&b,long long n)
{
    long long maxSubarray = 1;
    vector<long long> longestSubarrayA(2*n+1,0);
    vector<long long> longestSubarrayB(2*n+1,0);
    long long counter=1;
    for(long long i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            counter++;
        }
        else
        {
            longestSubarrayA[a[i-1]] = max(longestSubarrayA[a[i-1]], counter);
            counter = 1;
        }
    }
    longestSubarrayA[a[n-1]] = max(longestSubarrayA[a[n-1]], counter);
    counter = 1;
    for(long long i=1;i<n;i++)
    {
        if(b[i]==b[i-1])
        {
            counter++;
        }
        else
        {
            longestSubarrayB[b[i-1]] = max(longestSubarrayB[b[i-1]], counter);
            counter = 1;
        }
    }
    longestSubarrayB[b[n-1]] = max(longestSubarrayB[b[n-1]], counter);
    counter = 1;

    for(long long i=1;i<=2*n;i++)
    {
        
            maxSubarray = max(maxSubarray, longestSubarrayA[i] + longestSubarrayB[i]);
        
    }

    return maxSubarray; // Subtracting 1 to avoid double counting the last element


}



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<long long> b(n);
        for(long long i = 0; i < n; i++) {
            cin >> b[i];
        }
        cout<<findMaxSubarray(a,b,n)<<endl;
       
    }
    return 0;
}
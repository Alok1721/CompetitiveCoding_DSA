#include<bits/stdc++.h>
using namespace std;

vector<int> NSR(vector<int>arr){
    int n=arr.size();
    vector<int>nsr(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty()&&arr[st.top()]>arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nsr[i]=n;
        }
        else
        {
            nsr[i]=st.top();
        }
        st.push(i);
    }
    return nsr;
}
vector<int> NSL(vector<int>arr){
    int n=arr.size();
    vector<int>nsl(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&arr[st.top()]>arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nsl[i]=-1;
        }
        else
        {
            nsl[i]=st.top();
        }
        st.push(i);
    }
    return nsl;
}

int maxSquare(vector<int>arr,int n){
 
    int maxSquare=0;
    vector<int>nsr=NSR(arr);
    vector<int>nsl=NSL(arr);
    for(int i=0;i<n;i++)
    {
        int tempWidth=nsr[i]-nsl[i]-1;
        int tempHeight=arr[i];
        int height=min(tempWidth,tempHeight);
        int width=min(tempWidth,tempHeight);
        int area=width*height;
        maxSquare=max(maxSquare,area);
    }
    return maxSquare;
}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxSquare(arr,n);
 return 0;   
}
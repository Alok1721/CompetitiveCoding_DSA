#include <bits/stdc++.h>
using namespace std;
vector<int>findCandies(int n,int k){

    vector<int>result(k,0);
    int i=0;
    int count=1;
    while(n>0){
        if(count<=n)
        {
            result[i]+=count;
            n-=count;
        }
        else
        {
            result[i]+=n;
            n=0;
        }
        count++;//needed for next
        i=(i+1)%k;
    }
    return result;

}

int main() {
 
    int n,k;
    cin>>n>>k;
    vector<int>result=findCandies(n,k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
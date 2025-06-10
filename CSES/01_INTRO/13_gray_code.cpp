#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;

vector<int> getBinaryNumber(int n,int length)
{
    vector<int> result;
    for(int i=(int)length-1;i>=0;i--)
    {
        int shift=n>>i;
        (shift&1 )? result.push_back(1):result.push_back(0);
    }
    return result;
}
vector<int> getGrayCode(vector<int>&arr)
{
    vector<int>result;
    result.push_back(arr[0]);
    for(int i=0;i<(int)arr.size()-1;i++)
    {
        result.push_back(arr[i]^arr[i+1]);
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int> binaryNumber;
    vector<int> grayCode;

    for(int i=0;i<pow(2,n);i++)
    {
        binaryNumber=getBinaryNumber(i,n);
        grayCode=getGrayCode(binaryNumber);
        for(int j=0;j<(int)grayCode.size();j++)
        {
            cout<<grayCode[j];
        }
        cout<<endl;
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void invertedPyramid(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"  ";
        }
        for(int j=i;j<n-i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}



int main()
{
    int n;
    cin>>n;
    invertedPyramid(n);
    return 0;
}
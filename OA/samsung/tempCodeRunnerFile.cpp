#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&students,int left,int right,int k)
{
    if(right-left+1<3)return right-left+1;
    int ans=right-left+1;
    for(int i=left+1;i<=right;i++)
    {
        if(students[i-1]+k==students[i]&&students[i]+k==students[i+1])
        {
            int leftRem=solve(students,left,i-2,k);
            int rightRem=solve(students,i+2,right,k);
            ans=min(ans,leftRem+rightRem);
        }
    }
    return ans;
}


int findMinStudent(vector<int>students,int k)
{
    return solve(students, 0, students.size() - 1,k);
}


int main()
{
    int n,k;
    cin >> n>>k;
    vector<int> students(n);
    for(int i = 0; i < n; i++)
    {
        cin >> students[i];
    }
    cout<<findMinStudent(students,k)<<endl;

    return 0;
}
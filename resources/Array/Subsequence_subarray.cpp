class Solution {
public:
    int n;
    int solve(string &s,int k,int i,int prev)
    {
        if(i>=n)return 0;//path ended
        int take=0,skip=0;
        if(prev==-1|| s[i]-s[prev]<=k)
        {
            take=1+solve(s,k,i+1,i);
        }
        skip=solve(s,k,i+1,prev);
        return max(take,skip);
    }
    int longestIdealString(string s, int k) {
        n=s.size();
        return solve(s,k,0,-1);
    }
};
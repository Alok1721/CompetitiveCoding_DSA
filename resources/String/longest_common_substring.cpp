class Solution {
    public:
      int result;
      int dp[1001][1001];
      int solve(string &s1,string &s2,int i,int j)
      {
          if(i>=s1.size() || j>=s2.size())return 0;
          int take=0;
          if(dp[i][j]!=-1)return dp[i][j];
          if(s1[i]==s2[j])
          {
              take=1+solve(s1,s2,i+1,j+1);
          
              result=max(take,result);
          }
          solve(s1,s2,i+1,j);
          solve(s1,s2,i,j+1);
          return dp[i][j]= take;
          
      }
      int longestCommonSubstr(string& s1, string& s2) {
          // your code here
          result=0;
          memset(dp,-1,sizeof(dp));
          solve(s1,s2,0,0);
      
          return result;
      }
  };
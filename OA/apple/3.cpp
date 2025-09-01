class Solution {
    public:
        int dp[10001];
        bool solve(vector<int>&nums,int i)
        {
            if(i==nums.size()-1)return true;
            if(i>=nums.size())return false;
            if(dp[i]!=-1)return dp[i];
            int take=false;
            for(int jump=1;jump<=nums[i];jump++)
            {
               if(solve(nums,jump+i))
               {
                return dp[i]=true;
               }
            }
            return dp[i]= false;
        }
        bool canJump(vector<int>& nums) {
            memset(dp,-1,sizeof(dp));
            return solve(nums,0);
        }
    };
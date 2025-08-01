
//use this template to solve game related problems, it can easily find the winner of game , 
//--->IMPORTANT: this template is for 2 player game, where player 1 always try to maximize the score and player 2 always try to minimize the score
class Solution {
public:
    int n;
    int solve(vector<int>&nums,int left,int right)
    {
        if(left>right)return 0;
        int player1=INT_MIN;
        player1=max(player1,nums[left]-solve(nums,left+1,right));
        player1=max(player1,nums[right]-solve(nums,left,right-1));
        return player1;
    }
    bool predictTheWinner(vector<int>& nums) {
     n=nums.size();
     if(n==1)return true;
     int result=solve(nums,0,n-1);   
    if(result>=0)return true;
    return false;
    }
};



/* 
/**********************************************
!1140. Stone Game II
? Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.
?Alice and Bob take turns, with Alice starting first.
?On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.
?The game continues until all the stones have been taken.
?Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
*Example 1:
*Input: piles = [2,7,9,4,4]
*Output: 10 
! alice want maximum score and bob give worst score to alice
 **********************************************/


class Solution {
    public:
        int n;
        int dp[101][101][2];
        int solve(vector<int>&piles,int i,int m,bool isAlice)
        {
            if(i>=n)return 0;
    
            if(dp[i][m][isAlice]!=-1)return dp[i][m][isAlice];
            int result=0;
            if(isAlice)
            {
                result=INT_MIN;
                int total=0;
                for(int step=1;step<=2*m && i+step<=n;step++)
                {
                    total+=piles[i+step-1];
                    result=max(result,total+solve(piles,i+step,max(m,step),false));
                }
    
            }
            else
            {
                result=INT_MAX;
                for(int step=1;step<=2*m && i+step<=n;step++)
    
                {
                    result=min(result,solve(piles,i+step,max(m,step),true));
                }
            }
            return dp[i][m][isAlice]= result;
    
        }
        int stoneGameII(vector<int>& piles) {
            memset(dp,-1,sizeof(dp));
        n=piles.size();
        int result=solve(piles,0,1,true);//piles, i,m=1,alice
        return result;        
        }
    };
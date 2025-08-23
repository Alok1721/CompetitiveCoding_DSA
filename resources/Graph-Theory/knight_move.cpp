
/*
?
Steps by Knight
Difficulty: MediumAccuracy: 37.32%Submissions: 127K+Points: 4Average Time: 20m
Given a square chessboard of size (n x n), the initial position and target postion of Knight are given. Find out the minimum steps a Knight will take to reach the target position.

Note: The initial and the target position coordinates of Knight have been given according to 1-base indexing.

Examples:

Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
Output: 1
Explanation:
Knight takes 1 step to reach from 
(3, 3) to (1 ,2).

*/

class Solution {
    public:
      vector<pair<int,int>> dirs={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
      int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
          // Code here
          vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
          queue<vector<int>> q;
          q.push({knightPos[0],knightPos[1],0});
          visited[knightPos[0]][knightPos[1]]=true;
          while(!q.empty())
          {
              auto knight=q.front();
              q.pop();
              int x=knight[0];
              int y=knight[1];
              int step=knight[2];
              if(x==targetPos[0] && y==targetPos[1])return step;
              for(auto dir:dirs)
              {
                  int nx=x+dir.first;
                  int ny=y+dir.second;
                  if(nx<=n && ny<=n && nx>0 && ny>0 && !visited[nx][ny])
                  {
                      visited[nx][ny]=true;
                      q.push({nx,ny,step+1});
                  }
              }
              
          }
          return -1;
          
      }
  };
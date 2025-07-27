//use bfs to find the minimum number of jumps to reach the end of the array

class Solution {
public:
    int minJumps(vector<int>& arr) {
     int n=arr.size();
     int max_val=*max_element(arr.begin(),arr.end());
     unordered_map<int,vector<int>> value_index;
     for(int i=0;i<n;i++)
     {
        value_index[arr[i]].push_back(i);
     }   
     vector<bool>visited(n+1,false);
     queue<pair<int,int>> q;//index,jump
     q.push({0,0});
     visited[0]=true;
     while(!q.empty())
     {
        auto curr=q.front();
        q.pop();
        int index=curr.first;
        int jump=curr.second;
        if(index==n-1)return jump;
        
            for(auto id:value_index[arr[index]])
            {
                if(!visited[id])
                {
                    q.push({id,jump+1});
                    visited[id]=true;
                }

            }
            value_index.erase(arr[index]);
        
        if(index+1<n &&!visited[index+1])
        {
            q.push({index+1,jump+1});
            visited[index+1]=true;
        }
        if(index-1>=0 &&!visited[index-1])
        {
            q.push({index-1,jump+1});
            visited[index-1]=true;
        }

     }

        return -1;
    }
};
//*******************
40. Combination Sum II
Solved
Medium
Topics
premium lock icon
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
//******************

class Solution {
    public:
        void solve(vector<int>&candidates, int target, int id,vector<int>&temp,vector<vector<int>>&result)
        {
            if(target<0)return;
            if(target==0)
            {
                result.push_back(temp);
                return;
            }
    
            for(int i=id;i<candidates.size();i++)
            {
                if(i>id && candidates[i]==candidates[i-1]){
                    continue;}
                temp.push_back(candidates[i]);
                solve(candidates,target-candidates[i],i+1,temp,result);
                temp.pop_back();
            }
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> temp;
            sort(begin(candidates),end(candidates));
            solve(candidates,target,0,temp,result);
            return result;
        }
    };
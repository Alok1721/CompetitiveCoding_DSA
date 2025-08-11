/*
41. First Missing Positive
Solved
Hard
Topics
premium lock icon
Companies
Hint
Amazon
Microsoft
Adobe
Google
Facebook
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

*/




class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool isContain1=false;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)isContain1=true;
            if(nums[i]<=0 || nums[i]>n) nums[i]=1;
        }
        if(!isContain1)return 1;

        for(int i=0;i<n;i++)
        {
            int idx=abs(nums[i])-1;
            if(nums[idx]<0)continue;
            nums[idx]=-1*nums[idx];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }
};
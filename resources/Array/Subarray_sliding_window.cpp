/**************************************
992. Subarrays with K Different Integers

Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

**************************************/
class Solution {
public:
    //-->having only one formulas for number of subarray at index j is j-i+1 but will conside all subarray that itself less than k unique element , so that we will find all subarray then subtract from k-1 subarray

    int subarray(vector<int>&nums,int k)
    {
         
        int r=0;
        int l=0;
        int n=nums.size();
        int result=0;
        while(r<n)
        {
            mp[nums[r]]++;
            while(mp.size()>k && l<=r)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            result+=r-l+1;
            r++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums,k)-subarray(nums,k-1);
    }
};
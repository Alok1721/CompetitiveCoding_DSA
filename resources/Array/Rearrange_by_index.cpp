class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int right=1;
        vector<int>result(n);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                result[right]=nums[i];
                right+=2;
            }else
            {
                result[left]=nums[i];
                left+=2;
            }
        }
        return result;
    }
};
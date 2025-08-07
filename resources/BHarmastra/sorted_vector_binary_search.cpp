//====>helpful for finding the rank of an element in a sorted vector
/*********

315. Count of Smaller Numbers After Self
Solved
Hard
Topics
premium lock icon
Companies
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

*********** */

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted;
        vector<int>result(n);

        for(int i=n-1;i>=0;i--)
        {
            int index=lower_bound(sorted.begin(),sorted.end(),nums[i])-sorted.begin();
            sorted.insert(sorted.begin()+index,nums[i]);
            result[i]=index;
        }
        return result;
    }
};
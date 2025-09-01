/*
Equivalent Sub-Arrays
Difficulty: MediumAccuracy: 54.44%Submissions: 13K+Points: 4
Given an array arr[] of n integers. Count the total number of sub-array having total distinct elements same as that of total distinct elements of the original array.

 

Example 1:

Input:
N=5
arr[] = {2, 1, 3, 2, 3} 
Output: 5
Explanation:
Total distinct elements in array is 3
Total sub-arrays that satisfy the condition
are:
Subarray from index 0 to 2
Subarray from index 0 to 3
Subarray from index 0 to 4
Subarray from index 1 to 3
Subarray from index 1 to 4
*/

class Solution {
  public:
    int countDistinctSubarray(int arr[], int n) {
        // Step 1: Count total distinct elements in the array
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(arr[i]);
        }
        int k = st.size();  // total distinct elements required
        
        // Step 2: Sliding window
        unordered_map<int,int> freq;
        int left = 0, right = 0, distinct = 0, ans = 0;
        
        while(right < n) {
            // expand the window
            if(freq[arr[right]] == 0) distinct++;
            freq[arr[right]]++;
            right++;
            
            // shrink the window until it has exactly all k distinct
            while(distinct == k) {
                ans += (n - right + 1);  // every subarray starting at `left` and ending >= right-1
                freq[arr[left]]--;
                if(freq[arr[left]] == 0) distinct--;
                left++;
            }
        }
        return ans;
    }
};

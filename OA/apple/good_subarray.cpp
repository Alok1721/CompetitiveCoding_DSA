#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countGoodSubarrays(const std::vector<int>& nums, int k) {
        long long total_good_subarrays = 0;
        long long current_pairs = 0;
        std::unordered_map<int, int> freq; // Frequency map for elements in window
        int left = 0;
        int n = nums.size();

        // Iterate over all possible right endpoints
        for (int right = 0; right < n; ++right) {
            int element_at_right = nums[right];
            
            // Add element_at_right to the window
            // Add pairs formed by this element with existing ones
            current_pairs += freq[element_at_right];
            // Increment frequency of element_at_right
            freq[element_at_right]++;
            
            // Shrink window while pair count is at least k
            while (current_pairs >= k && left <= right) {
                // All subarrays from left to right (inclusive) ending at right are good
                total_good_subarrays += right - left + 1;
                
                // Remove element_at_left from the window
                int element_at_left = nums[left];
                // Reduce pairs by the number of remaining elements equal to element_at_left
                current_pairs -= freq[element_at_left] - 1;
                // Decrement frequency
                freq[element_at_left]--;
                if (freq[element_at_left] == 0) {
                    freq.erase(element_at_left);
                }
                // Move left pointer
                left++;
            }
        }
        
        return total_good_subarrays;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,0,5};
    cout << sol.countGoodSubarrays(nums, 2) << endl;
    return 0;
}
